#include <stdint.h>
#include <string.h> //memcpy
#include <stdio.h> // pruint32_tf
//#include <c_stdio.h> // c_pruint32_tf

#include "ledmate_font8x8.h"

// #define GENERATE_TABLES
#ifdef GENERATE_TABLES
#   include <math.h>
#   include <stdlib.h>
    int32_t _SIN[256];
    int8_t _BOUNCE[256];
#else
    int32_t _SIN[256] = {0, 52701886, 105372028, 157978697, 210490205, 262874923, 315101294, 367137860, 418953276, 470516330, 521795962, 572761285, 623381597, 673626407, 723465451, 772868705, 821806412, 870249094, 918167571, 965532977, 1012316783, 1058490807, 1104027236, 1148898639, 1193077990, 1236538674, 1279254514, 1321199779, 1362349203, 1402677998, 1442161873, 1480777043, 1518500249, 1555308767, 1591180424, 1626093615, 1660027307, 1692961061, 1724875039, 1755750016, 1785567395, 1814309215, 1841958163, 1868497584, 1893911493, 1918184579, 1941302224, 1963250500, 1984016187, 2003586778, 2021950482, 2039096240, 2055013722, 2069693340, 2083126253, 2095304368, 2106220350, 2115867624, 2124240379, 2131333570, 2137142926, 2141664947, 2144896908, 2146836865, 2147483647, 2146836865, 2144896908, 2141664947, 2137142926, 2131333570, 2124240379, 2115867624, 2106220350, 2095304368, 2083126253, 2069693340, 2055013722, 2039096240, 2021950482, 2003586778, 1984016187, 1963250500, 1941302224, 1918184579, 1893911493, 1868497584, 1841958163, 1814309215, 1785567395, 1755750016, 1724875039, 1692961061, 1660027307, 1626093615, 1591180424, 1555308767, 1518500249, 1480777043, 1442161873, 1402677998, 1362349203, 1321199779, 1279254514, 1236538674, 1193077990, 1148898639, 1104027236, 1058490807, 1012316783, 965532977, 918167571, 870249094, 821806412, 772868705, 723465451, 673626407, 623381597, 572761285, 521795962, 470516330, 418953276, 367137860, 315101294, 262874923, 210490205, 157978697, 105372028, 52701886, 0, -52701886, -105372028, -157978697, -210490205, -262874923, -315101294, -367137860, -418953276, -470516330, -521795962, -572761285, -623381597, -673626407, -723465451, -772868705, -821806412, -870249094, -918167571, -965532977, -1012316783, -1058490807, -1104027236, -1148898639, -1193077990, -1236538674, -1279254514, -1321199779, -1362349203, -1402677998, -1442161873, -1480777043, -1518500249, -1555308767, -1591180424, -1626093615, -1660027307, -1692961061, -1724875039, -1755750016, -1785567395, -1814309215, -1841958163, -1868497584, -1893911493, -1918184579, -1941302224, -1963250500, -1984016187, -2003586778, -2021950482, -2039096240, -2055013722, -2069693340, -2083126253, -2095304368, -2106220350, -2115867624, -2124240379, -2131333570, -2137142926, -2141664947, -2144896908, -2146836865, -2147483647, -2146836865, -2144896908, -2141664947, -2137142926, -2131333570, -2124240379, -2115867624, -2106220350, -2095304368, -2083126253, -2069693340, -2055013722, -2039096240, -2021950482, -2003586778, -1984016187, -1963250500, -1941302224, -1918184579, -1893911493, -1868497584, -1841958163, -1814309215, -1785567395, -1755750016, -1724875039, -1692961061, -1660027307, -1626093615, -1591180424, -1555308767, -1518500249, -1480777043, -1442161873, -1402677998, -1362349203, -1321199779, -1279254514, -1236538674, -1193077990, -1148898639, -1104027236, -1058490807, -1012316783, -965532977, -918167571, -870249094, -821806412, -772868705, -723465451, -673626407, -623381597, -572761285, -521795962, -470516330, -418953276, -367137860, -315101294, -262874923, -210490205, -157978697, -105372028, -52701886};
    int8_t _BOUNCE[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

#define SIN(x) (_SIN[(x) & 0xFF])
#define BOUNCE(x) (_BOUNCE[(x) & 0xFF])



struct {
    uint8_t *buf;
    uint32_t width;
    uint32_t height;
    uint32_t t;
    char msg[8][256];
    char msg_count;
} ledmate;



static void hsvtorgb(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t h, uint8_t s, uint8_t v)
{
    uint8_t region, fpart, p, q, t;

    if(s == 0) {
        /* color is grayscale */
        *r = *g = *b = v;
        return;
    }

    /* make hue 0-5 */
    region = h / 43;
    /* find remainder part, make it from 0-255 */
    fpart = (h - (region * 43)) * 6;

    /* calculate temp vars, doing uint32_teger multiplication */
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

static void setpixel(uint32_t x, uint32_t y,  uint32_t col) {
    if (x < 0 || x >= ledmate.width || y < 0 || y >= ledmate.height) return;
    if (y % 2 == 1) x = ledmate.width - 1 - x;

    uint32_t stride = ledmate.width * 3;
    ledmate.buf[y*stride + x*3    ] = (col & 0x00ff00) >> 8;
    ledmate.buf[y*stride + x*3 + 1] = (col & 0xff0000) >> 16;
    ledmate.buf[y*stride + x*3 + 2] = (col & 0x0000ff);
}

static void glyph(uint8_t c, uint32_t x, uint32_t y, uint32_t col) {
    uint32_t x1, y1;
    uint8_t g;

    if (c > 127) return;
    for (y1 = 0; y1 < 8; y1++) {
        g = font8x8_basic[c][y1];
        for (x1 = 0; x1 < 8; x1++) {
            if ((g >> x1) & 0x01) {
                setpixel(x + x1, y + y1, col);
            }
        }
    }
}

static void text(char *_str, int32_t x, int32_t y, uint32_t col) {
    uint8_t *str = (uint8_t*) _str;
    uint8_t c;

    while((c = *(str++))) {
        if (x > -8 && x < ledmate.width && y > -8 && y < ledmate.height) {
            glyph(c, x, y, col);
            x += 8;
        }
    }
}

static void bouncyText(char *_str, int32_t x, int32_t y, uint32_t col) {
    uint8_t *str = (uint8_t*) _str;
    uint8_t c;
    uint32_t offset;

    while((c = *(str++))) {
        if (c > 127) continue;
        offset = BOUNCE(((x << 2) + (ledmate.t << 3)));
        glyph(c, x, y + offset, col);
        x += 8;
    }
}

static void solidBackground(uint32_t col) {
    uint32_t x, y;
    for(y = 0; y < ledmate.height; y++) {
        for(x = 0; x < ledmate.width; x++) {
            setpixel(x, y, col);
        }
    }
}

static void background() {
    uint32_t x, X, y;
    uint32_t stride = ledmate.width * 3;
    for(y = 0; y < ledmate.height; y++) {
        for(x = 0; x < ledmate.width; x++) {
            X = (y % 2 == 1) ? ledmate.width - 1 - x : x;

            uint32_t h = ((ledmate.t >> 1) + x) * 2 + (SIN(ledmate.t * 10) >> 30)
                    + (SIN(y * 30 + ledmate.t * 10) >> 28);
            uint8_t r, g, b;
            hsvtorgb(&r, &g, &b, h, 255, 16);

            ledmate.buf[y*stride + X*3    ] = g;
            ledmate.buf[y*stride + X*3 + 1] = r;
            ledmate.buf[y*stride + X*3 + 2] = b;
        }
    }
}

void ledmate_push_msg(const char *_str, int32_t length) {
    const uint8_t *str = (const uint8_t*) _str;
    if (ledmate.msg_count == sizeof(ledmate.msg) / sizeof(ledmate.msg[0])) {
        memmove(&ledmate.msg[0][0], &ledmate.msg[1][0], sizeof(ledmate.msg[0]) * (ledmate.msg_count - 1));
    }
    if (ledmate.msg_count < 8) ledmate.msg_count++;

    length = length > 254 ? 254 : length;
    memcpy(&ledmate.msg[ledmate.msg_count - 1][0], str, length);
    ledmate.msg[ledmate.msg_count - 1][length] = '\0';
}

void ledmate_init(uint8_t* _buf, uint32_t _width, uint32_t _height) {
    ledmate.buf = _buf;
    ledmate.width = _width;
    ledmate.height = _height;

    ledmate.msg_count = 0;
    ledmate_push_msg("xil.se", sizeof("xil.se"));
    ledmate_push_msg("111111", sizeof("xil.se"));
    ledmate_push_msg("222222", sizeof("xil.se"));
    ledmate_push_msg("333333", sizeof("xil.se"));
    ledmate_push_msg("444444", sizeof("xil.se"));
    ledmate_push_msg("555555", sizeof("xil.se"));
    ledmate_push_msg("666666", sizeof("xil.se"));
    ledmate_push_msg("777777", sizeof("xil.se"));
    ledmate_push_msg("888888", sizeof("xil.se"));


#ifdef GENERATE_TABLES
    uint32_t i;
    for (i = 0; i < 256; i++) {
        _SIN[i] = sin(M_PI * ((float)i / 128)) * 0x7fffffff;
        _BOUNCE[i] = sin(M_PI * ((float)i / 128)) * 3;
    }
    pruint32_tf("uint32_t _SIN[256] = {");
    for (i = 0; i < 255; i++) {
        pruint32_tf("%d, ", _SIN[i]);
    }
    pruint32_tf("%d};\n", _SIN[255]);
    pruint32_tf("uint8_t _BOUNCE[256] = {");
    for (i = 0; i < 255; i++) {
        pruint32_tf("%d, ", _BOUNCE[i]);
    }
    pruint32_tf("%d};\n", _BOUNCE[255]);
    exit(0);
#endif
}

void ledmate_render(uint32_t _t) {
    (void) solidBackground;
    (void) background;
    (void) text;
    (void) bouncyText;

    ledmate.t = _t;

    background();
    text(ledmate.msg[(ledmate.t / 10) % ledmate.msg_count], 0, 0, 0x0f0000);
    bouncyText("happy 32c3!", ledmate.t % (ledmate.width + 8*11) - 8*11, 0, 0);
}
