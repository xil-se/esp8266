#!/usr/bin/python

import os
import socket
import time
from PIL import Image
import sys

UDP_IP = "192.168.1.18"
UDP_PORT = 8888
DISP_WIDTH = 144
DISP_HEIGHT = 8
INTENSITY_DIVISOR = 32
GIF_FILE = "nyan_scaled3.gif"


def main():
    gif = Image.open(GIF_FILE)

    frame_idx = 0
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP

    while True:
        try:
            gif.seek(frame_idx)
            frame = gif.convert("RGB")
            frame_buffer = build_framebuffer(frame)
            gif_width, gif_height = frame.size

            send_framebuffer(sock, frame_buffer)
            time.sleep(0.1)
            frame_idx = frame_idx + 1
        except EOFError:
            frame_idx = 0

def set_pixel(buf, x, y, (r, g, b)):
    oldx=x
    if y % 2 == 1: x = 143 - x
    try:
        buf[x*3 + DISP_WIDTH*3*y]     = int(g / INTENSITY_DIVISOR)
        buf[x*3 + DISP_WIDTH*3*y + 1] = int(r / INTENSITY_DIVISOR)
        buf[x*3 + DISP_WIDTH*3*y + 2] = int(b / INTENSITY_DIVISOR)
    except:
            print oldx, y, (r, g, b)

def build_framebuffer(frame):
    frame_buffer = bytearray(3*DISP_WIDTH*DISP_HEIGHT)
    gif_width, gif_height = frame.size

    for y in range(0, DISP_HEIGHT):
        for x in range(0, DISP_WIDTH):
            if x < gif_width and y < gif_height:
                rgb = frame.getpixel((x, y))
                set_pixel(frame_buffer, x, y, rgb)
    return frame_buffer


def send_framebuffer(sock, frame_buffer):
    sock.sendto("\x01" + bytes(frame_buffer[0:1458]),      (UDP_IP, UDP_PORT))
    sock.sendto("\x02" + bytes(frame_buffer[1458:1458*2]), (UDP_IP, UDP_PORT))
    sock.sendto("\x03" + bytes(frame_buffer[1458*2:]),     (UDP_IP, UDP_PORT))


if __name__ == "__main__":
    main()
