#!/usr/bin/python

import os
import socket
import time
from PIL import Image
import sys

UDP_IP = "192.168.5.10"
UDP_PORT = 8888
DISP_WIDTH = 144
DISP_HEIGHT = 8
INTENSITY_DIVISOR = 32
IMAGE_FILE = "image.png"


def main():
    img = Image.open(IMAGE_FILE)
    frame = img.convert("RGB")
    img_width, img_height = frame.size

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    frame_buffer = bytearray(3 * DISP_WIDTH * DISP_HEIGHT)
    while True:
        for r in range(0, img_height - DISP_HEIGHT + 1):
            for y in range(0, DISP_HEIGHT):
                for x in range(0, DISP_WIDTH):
                    rgb = frame.getpixel((x, r+y))
                    set_pixel(frame_buffer, x, y, rgb)

            send_framebuffer(sock, frame_buffer)
            time.sleep(0.1)

def set_pixel(buf, x, y, (r, g, b)):
    oldx=x
    if y % 2 == 1: x = 143 - x
    try:
        buf[x*3 + DISP_WIDTH*3*y]     = int(g / INTENSITY_DIVISOR)
        buf[x*3 + DISP_WIDTH*3*y + 1] = int(r / INTENSITY_DIVISOR)
        buf[x*3 + DISP_WIDTH*3*y + 2] = int(b / INTENSITY_DIVISOR)
    except:
            print oldx, y, (r, g, b)

def send_framebuffer(sock, frame_buffer):
    sock.sendto("\x01" + bytes(frame_buffer[0:1458]),      (UDP_IP, UDP_PORT))
    sock.sendto("\x02" + bytes(frame_buffer[1458:1458*2]), (UDP_IP, UDP_PORT))
    sock.sendto("\x03" + bytes(frame_buffer[1458*2:]),     (UDP_IP, UDP_PORT))


if __name__ == "__main__":
    main()
