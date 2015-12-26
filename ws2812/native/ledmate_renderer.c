#include <string.h> //memcpy

#include <stdio.h> // printf
//#include <c_stdio.h> // c_printf


#include "ledmate_font8x8.h"

// #define GENERATE_TABLES
#ifdef GENERATE_TABLES
#   include <math.h>
#   include <stdlib.h>
    int _SIN[256];
    signed char _BOUNCE[256];
#else
    int _SIN[256] = {0, 52701886, 105372028, 157978697, 210490205, 262874923, 315101294, 367137860, 418953276, 470516330, 521795962, 572761285, 623381597, 673626407, 723465451, 772868705, 821806412, 870249094, 918167571, 965532977, 1012316783, 1058490807, 1104027236, 1148898639, 1193077990, 1236538674, 1279254514, 1321199779, 1362349203, 1402677998, 1442161873, 1480777043, 1518500249, 1555308767, 1591180424, 1626093615, 1660027307, 1692961061, 1724875039, 1755750016, 1785567395, 1814309215, 1841958163, 1868497584, 1893911493, 1918184579, 1941302224, 1963250500, 1984016187, 2003586778, 2021950482, 2039096240, 2055013722, 2069693340, 2083126253, 2095304368, 2106220350, 2115867624, 2124240379, 2131333570, 2137142926, 2141664947, 2144896908, 2146836865, 2147483647, 2146836865, 2144896908, 2141664947, 2137142926, 2131333570, 2124240379, 2115867624, 2106220350, 2095304368, 2083126253, 2069693340, 2055013722, 2039096240, 2021950482, 2003586778, 1984016187, 1963250500, 1941302224, 1918184579, 1893911493, 1868497584, 1841958163, 1814309215, 1785567395, 1755750016, 1724875039, 1692961061, 1660027307, 1626093615, 1591180424, 1555308767, 1518500249, 1480777043, 1442161873, 1402677998, 1362349203, 1321199779, 1279254514, 1236538674, 1193077990, 1148898639, 1104027236, 1058490807, 1012316783, 965532977, 918167571, 870249094, 821806412, 772868705, 723465451, 673626407, 623381597, 572761285, 521795962, 470516330, 418953276, 367137860, 315101294, 262874923, 210490205, 157978697, 105372028, 52701886, 0, -52701886, -105372028, -157978697, -210490205, -262874923, -315101294, -367137860, -418953276, -470516330, -521795962, -572761285, -623381597, -673626407, -723465451, -772868705, -821806412, -870249094, -918167571, -965532977, -1012316783, -1058490807, -1104027236, -1148898639, -1193077990, -1236538674, -1279254514, -1321199779, -1362349203, -1402677998, -1442161873, -1480777043, -1518500249, -1555308767, -1591180424, -1626093615, -1660027307, -1692961061, -1724875039, -1755750016, -1785567395, -1814309215, -1841958163, -1868497584, -1893911493, -1918184579, -1941302224, -1963250500, -1984016187, -2003586778, -2021950482, -2039096240, -2055013722, -2069693340, -2083126253, -2095304368, -2106220350, -2115867624, -2124240379, -2131333570, -2137142926, -2141664947, -2144896908, -2146836865, -2147483647, -2146836865, -2144896908, -2141664947, -2137142926, -2131333570, -2124240379, -2115867624, -2106220350, -2095304368, -2083126253, -2069693340, -2055013722, -2039096240, -2021950482, -2003586778, -1984016187, -1963250500, -1941302224, -1918184579, -1893911493, -1868497584, -1841958163, -1814309215, -1785567395, -1755750016, -1724875039, -1692961061, -1660027307, -1626093615, -1591180424, -1555308767, -1518500249, -1480777043, -1442161873, -1402677998, -1362349203, -1321199779, -1279254514, -1236538674, -1193077990, -1148898639, -1104027236, -1058490807, -1012316783, -965532977, -918167571, -870249094, -821806412, -772868705, -723465451, -673626407, -623381597, -572761285, -521795962, -470516330, -418953276, -367137860, -315101294, -262874923, -210490205, -157978697, -105372028, -52701886};
    signed char _BOUNCE[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

#define SIN(x) (_SIN[(x) & 0xFF])
#define BOUNCE(x) (_BOUNCE[(x) & 0xFF])

unsigned char *buf;
int width;
int height;
int t;
int text_t;
int current_msg;
char msg[8][256];
char msg_count;

static void hsvtorgb(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char h, unsigned char s, unsigned char v)
{
    unsigned char region, fpart, p, q, t;

    if(s == 0) {
        /* color is grayscale */
        *r = *g = *b = v;
        return;
    }

    /* make hue 0-5 */
    region = h / 43;
    /* find remainder part, make it from 0-255 */
    fpart = (h - (region * 43)) * 6;

    /* calculate temp vars, doing integer multiplication */
    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * fpart) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;

    /* assign temp vars based on color cone region */
    switch(region) {
        case 0:
            *r = v; *g = t; *b = p; break;
        case 1:
            *r = q; *g = v; *b = p; break;
        case 2:
            *r = p; *g = v; *b = t; break;
        case 3:
            *r = p; *g = q; *b = v; break;
        case 4:
            *r = t; *g = p; *b = v; break;
        default:
            *r = v; *g = p; *b = q; break;
    }

    return;
}

static void setpixel(int x, int y, int col) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    if (y % 2 == 1) x = width - 1 - x;

    int stride = width * 3;
    buf[y*stride + x*3    ] = (col & 0x00ff00) >> 8;
    buf[y*stride + x*3 + 1] = (col & 0xff0000) >> 16;
    buf[y*stride + x*3 + 2] = (col & 0x0000ff);
}

static void glyph(char c, int x, int y, int col) {
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

static void text(char *str, int x, int y, int col) {
    char c;

    while((c = *(str++))) {
        if (x > -8 && x < width && y > -8 && y < height) {
            glyph(c, x, y, col);
        }
        x += 8;
    }
}

static void bouncy_text(char *str, int x, int y, int col) {
    char c;
    int i = 0, offset;

    while((c = *(str++))) {
        if (c > 127) continue;
        i++;
        offset = BOUNCE(((i*32) + (text_t<<3)));
        glyph(c, x, y + offset, col);
        x += 8;
    }
}

static void solid_background(int col) {
    int x, y;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            setpixel(x, y, col);
        }
    }
}

static void background() {
    int x, X, y;
    int stride = width * 3;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            X = (y % 2 == 1) ? width - 1 - x : x;
            int h = ((t>>1) + x) * 2 + (SIN(t*10) >> 30) + (SIN(y*30 + t*10) >> 28);
            unsigned char r, g, b;
            hsvtorgb(&r, &g, &b, h, 255, 16);

            buf[y*stride + X*3    ] = g;
            buf[y*stride + X*3 + 1] = r;
            buf[y*stride + X*3 + 2] = b;
        }
    }
}

void ledmate_push_msg(const char *str, int length) {
    if (msg_count == sizeof(msg) / sizeof(msg[0])) {
        memmove(&msg[0][0], &msg[1][0], sizeof(msg[0]) * (msg_count - 1));
    }
    if (msg_count < 8) msg_count++;

    length = length > 254 ? 254 : length;
    memcpy(&msg[msg_count - 1][0], str, length);
    msg[msg_count - 1][length] = '\0';
}

void ledmate_init(unsigned char* _buf, int _width, int _height) {
    buf = _buf;
    width = _width;
    height = _height;

    current_msg = 0;
    msg_count = 0;

    {
        char foo[] = "\x01\x30\x30\x30" "<<< %s(un='%s') = %u";
        ledmate_push_msg(foo, sizeof(foo));
    }
    {
        char foo[] = "\x04\x00\x00\x00" "xil is my happy place";
        ledmate_push_msg(foo, sizeof(foo));
    }
    {
        char foo[] = "\x04\x00\x00\x00" "welcome to 32c3";
        ledmate_push_msg(foo, sizeof(foo));
    }

#ifdef GENERATE_TABLES
    int i;
    for (i = 0; i < 256; i++) {
        _SIN[i] = sin(M_PI * ((float)i / 128)) * 0x7fffffff;
        _BOUNCE[i] = sin(M_PI * ((float)i / 128)) * 3;
    }
    printf("int _SIN[256] = {");
    for (i = 0; i < 255; i++) {
        printf("%d, ", _SIN[i]);
    }
    printf("%d};\n", _SIN[255]);
    printf("char _BOUNCE[256] = {");
    for (i = 0; i < 255; i++) {
        printf("%d, ", _BOUNCE[i]);
    }
    printf("%d};\n", _BOUNCE[255]);
    exit(0);
#endif
}

static int render_text(char *str) {
    unsigned char mode = str[0];
    char direction = 0;

    switch (mode) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            background();
            break;
        default:
            break;
    }


    switch (mode) {
        case 1:
            direction = 1;
        case 2:
        {
            unsigned int col = (str[1] << 16) | (str[2] << 8) | str[3];
            char *_str = &str[4];
            int len = strnlen(_str, 250);
            if (direction) {
                text(_str, 144 - text_t, 0, col);
            }
            else {
                text(_str, text_t - 8 * len, 0, col);
            }
            if (text_t > 144 + 8 * len) {
                return 1;
            }
            break;
        }
        case 3:
        {
            unsigned int col = (str[1] << 16) | (str[2] << 8) | str[3];
            unsigned char dur = str[4];
            char *_str = &str[5];
            if (text_t > dur) return 1;
            bouncy_text(_str, 0, 0, col);
            break;
        }
        case 4:
        direction = 1;
        case 5:
        {
            unsigned int col = (str[1] << 16) | (str[2] << 8) | str[3];
            char *_str = &str[4];
            int len = strnlen(_str, 250);
            if (text_t > 144 + 8 * len) return 1;
            if (direction) {
                bouncy_text(_str, 144 - text_t, 0, col);
            }
            else {
                bouncy_text(_str, text_t - 8 * len, 0, col);
            }
            break;
        }
    }

    return 0;
}

void ledmate_render(int _t) {
    (void) background;
    (void) solid_background;
    (void) text;
    (void) bouncy_text;

    t = _t;

    if (msg_count > 0) {
        int ret = render_text(msg[current_msg]);
        text_t++;
        if (ret) {
            current_msg = (current_msg + 1) % msg_count;
            text_t = 0;
        }
    }
    else {
        bouncy_text("happy 32c3!", t % (width + 8*11) - 8*11, 0, 0);
        background();
    }
}
