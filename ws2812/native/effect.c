#include <string.h> //memcpy

#include "font8x8_basic.h"

char *buf;
int width;
int height;
int t;

void setpixel(int x, int y, int col) {
  if (x < 0 || x >= width || y < 0 || y >= height) return;

  int oldx = x;
  if (y % 2 == 1) x = width - 1 - x;

  int stride = width * 3;
  buf[y*stride + x*3    ] = (col & 0x00ff00) >> 8;
  buf[y*stride + x*3 + 1] = (col & 0xff0000) >> 16;
  buf[y*stride + x*3 + 2] = (col & 0x0000ff);
}

void text(char *str, int x, int y, int col) {
  char c;
  int x1, y1;

  while(c = *(str++)) {
    if (c > 127) continue;
    for (y1 = 0; y1 < 8; y1++) {
      for (x1 = 0; x1 < 8; x1++) {
        if ((font8x8_basic[c][y1] >> x1) & 0x01) {
          setpixel(x + x1, y + y1, col);
        }
      }
    }
    x += 8;
  }
}

solidBackground(col) {
  int x, y;
  int stride = width * 3;
  for(y = 0; y < height; y++) {
      for(x = 0; x < width; x++) {
        setpixel(x, y, col);
      }
  }
}

background() {
  int x, y;
  int stride = width * 3;
  for(y = 0; y < height; y++) {
      for(x = 0; x < width; x++) {
          buf[y*stride + x*3    ] = 4;
          buf[y*stride + x*3 + 1] = (x*(t%20))/8;
          buf[y*stride + x*3 + 2] = (t/3) % 10;
      }
  }
}

void render(char* _buf, int _width, int _height, int _t) {

    buf = _buf;
    width = _width;
    height = _height;
    t = _t;

    solidBackground(0x040005);
//    background();


    text("hello", 0, 0, 0x000f0f);
//    text("hello", 0, -8 + t % 16, 0xff00ff);
//    scrollText("so the idea is that the rendering is done on the chip. it receives text and commands to reders it", 0);
}
