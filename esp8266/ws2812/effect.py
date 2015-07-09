import socket
import time
import math
from colorsys import *

class Foo():
	def __init__(self):
		self.i = 0

	def rainbow(a):
		return hsv_to_rgb(a, 1.0, 1.0)
	def clamp(self, x, a, b):
		return max(min(x, b), a)

	def setpixel(self, buf, x, y, rgb):
		oldx=x
		if y % 2 == 1: x = 143 - x
		try:
			buf[x*3 + 144*3*y]     = int(rgb[1])
			buf[x*3 + 144*3*y + 1] = int(rgb[0])
			buf[x*3 + 144*3*y + 2] = int(rgb[2])
		except:
			print oldx, y, rgb

	def lissajous(self, A, a, B, b, x0, y0, delta, t):
		x = x0 + A * math.sin(a*t + delta)
		y = y0 + B * math.sin(b*t)

		return (x, y)


	def render_lissajous(self, buf, u, v, A, a, B, b, x0, y0, delta, t, intensity):
		(x, y) = self.lissajous(A + v, a, B + v, b, u, 4, self.i / 10.0, self.i / 10.0 + t/100.0)
		(r, g, b) = hsv_to_rgb(t/100.0, 1.0, 1.0)
		r = int(r*16 * intensity)
		g = int(g*16 * intensity)
		b = int(b*16 * intensity)
		if y >= 0 and y <= 8:
			self.setpixel(buf, self.clamp(int(x + 70), 0, 143), self.clamp(int(y), 0, 7), (r, g, b))


	def render3(self, buf):
		i = self.i
		u1 = 40 * math.sin(i / 10.0 + math.pi)	
		u2 = 40 * math.sin(i / 10.0)	
		v1 = 2.5 * math.sin(i / 10.0 + 3*math.pi/2)
		v2 = 2.5 * math.sin(i / 10.0 + math.pi/2)
		i1 = v1/6 + 1
		i2 = v2/6 + 1
		
		if v1 < 0:
			for t in range(0, 300):
				self.render_lissajous(buf, u1, v1,  20, 6, 4,      6, u1, 4, 0, t, i1)
			for t in range(0, 300):
				self.render_lissajous(buf, u2, v2,  20, 3, 4,      6, u2, 4, 0, t, i2)
		else:
			for t in range(0, 300):
				self.render_lissajous(buf, u2, v2,  20, 3, 4,      6, u2, 4, 0, t, i2)
			for t in range(0, 300):
				self.render_lissajous(buf, u1, v1,  20, 6, 4,      6, u1, 4, 0, t, i1)

	def render2(self, buf):
		for x in range(0, 144):
			h = (x - self.i*4) % 144
			(r, g, b) = hsv_to_rgb(h / 144.0, 1.0, 1.0)
			#y = int(4+4*math.sin(0.5*math.pi * (x/144.0)))
			y = int(4+4*math.sin((  3.2   )*math.pi * ((x + self.i)/144.0)))
			self.clamp(y, 0, 7)
			#y = 1
			v = 10
			self.setpixel(buf, x, y, (r*v,g*v,b*v))
			if x < 143:
				self.setpixel(buf, (x+1), y, (r*v,g*v,b*v))

	def render1(self, buf):
		for y in range(0,8):
			for x in range(0, 144):
				(r,g,b) = self.render(x, y)
				buf[x*3 + y*144*3]     = chr(g)
				buf[x*3 + y*144*3 + 1] = chr(r)
				buf[x*3 + y*144*3 + 2] = chr(b)

	def render(self, x, y):
		if y % 2 == 1:
			x = 144 - x
		oldx = x
		x = (x + int(30*math.sin((self.i+y)/3.0))) % 144
		h = math.fmod((x + 30 * (1.0 + math.sin(self.i/5.0))) / 144.0, 1.0)
		rgb = hsv_to_rgb(h, 1.0, 1.0)
		v = (math.sin(self.i / 3.0) + 1.0) + 1.5
		r = rgb[0] * 2.0 * v
		g = rgb[1] * 2.0 * v
		b = rgb[2] * 2.0 * v

		return (int(r), int(g), int(b))
	
	def main(self):
		UDP_IP = "192.168.5.28"
		UDP_PORT = 8888
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
		while True:
			self.i = (self.i + 1)
			data = bytearray(144*8*3)
		
			self.render1(data)
			#self.render2(data)
			self.render3(data)

			sock.sendto("\x01" + bytes(data[0:1458]), (UDP_IP, UDP_PORT))
			sock.sendto("\x02" + bytes(data[1458:1458*2]), (UDP_IP, UDP_PORT))
			sock.sendto("\x03" + bytes(data[1458*2:]), (UDP_IP, UDP_PORT))
			time.sleep(0.05)

if __name__ == "__main__":
	Foo().main()
