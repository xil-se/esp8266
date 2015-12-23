#include <string.h> //memcpy
#include <math.h> // don't use this later

#include "font8x8_basic.h"

unsigned char *buf;
int width;
int height;
int t;

int _SIN[256];
#define SIN(x) (_SIN[(x) & 0xFF])

char _BOUNCE[256];
#define BOUNCE(x) (_BOUNCE[(x) & 0xFF])

void setpixel(int x, int y, int col) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    if (y % 2 == 1) x = width - 1 - x;

    int stride = width * 3;
    buf[y*stride + x*3    ] = (col & 0x00ff00) >> 8;
    buf[y*stride + x*3 + 1] = (col & 0xff0000) >> 16;
    buf[y*stride + x*3 + 2] = (col & 0x0000ff);
}

void glyph(char c, int x, int y, int col) {
    int x1, y1;
    unsigned char g;

    if ((unsigned)c > 127) return;
    for (y1 = 0; y1 < 8; y1++) {
        g = font8x8_basic[(unsigned)c][y1];
        for (x1 = 0; x1 < 8; x1++) {
            if ((g >> x1) & 0x01) {
                setpixel(x + x1, y + y1, col);
            }
        }
    }
}

void text(char *str, int x, int y, int col) {
    char c;

    while((c = *(str++))) {
        if (x > -8 && x < width && y > -8 && y < height) {
            glyph(c, x, y, col);
            x += 8;
        }
    }
}

void bouncyText(char *str, int x, int y, int col) {
    char c;
    int i = 0, offset;

    while((c = *(str++))) {
        if (c > 127) continue;
        i++;
        // glyph(c, x, y + ((int) (sin((float)t/2 + i) * 3)), col);
        // offset = (SIN(((x<<2) + (t<<3))) >> 30);
        offset = BOUNCE(((x<<2) + (t<<3)));
        glyph(c, x, y + offset, col);
        x += 8;
    }
}

void solidBackground(int col) {
    int x, y;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            setpixel(x, y, col);
        }
    }
}

void background() {
    int x, X, y;
    int stride = width * 3;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            X = (y % 2 == 1) ? width - 1 - x : x;
            buf[y*stride + X*3    ] = SIN(x + t)>>28;
            buf[y*stride + X*3 + 1] = SIN(x - y - t)>>28;
            buf[y*stride + X*3 + 2] = SIN(-4*x + 5*y - 3*t)>>28;
        }
    }
}

void initRenderer(unsigned char* _buf, int _width, int _height) {
    buf = _buf;
    width = _width;
    height = _height;

    int i;
    for (i = 0; i < 256; i++) {
        _SIN[i] = sin(M_PI * ((float)i / 128)) * 0x7fffffff;
        _BOUNCE[i] = sin(M_PI * ((float)i / 128)) * 3;
    }
}

void render(int _t) {
    t = _t;

    // solidBackground(0x040005);
    background();


    // text("hello", 0, 0, 0x000f0f);
    bouncyText("happy 32c3!", t % (width + 8*11) - 8*11, 0, 0x060f00);
    // bouncyText("weeeee", t % (width + 8*6) - 8*6, 0, 0x000f00);
    // text("hello", 0, -8 + t % 16, 0xff00ff);
    // scrollText("so the idea is that the rendering is done on the chip. it receives text and commands to reders it", 0);
}
