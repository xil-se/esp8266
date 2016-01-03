#include "alpha_blend_int.h"

color alpha_blend(const color src, const color dst)
{
    color out;
    uint8_t a_inv;

    // from https://en.wikipedia.org/wiki/Alpha_compositing
    // outA = srcA + dstA * (1 - srcA)
    // outRGB = (srcRGB * srcA + dstRGB * dstA * (1 - srcA)) / outA

    if (src.c.a == 0xff) {
        return src;
    }

    a_inv = 0xff - src.c.a;
    out.c.a = src.c.a + dst.c.a * a_inv / 0xff;

    out.c.r = (src.c.r * src.c.a / 0xff + dst.c.r * dst.c.a * a_inv / 0xff) / out.c.a;
    out.c.g = (src.c.g * src.c.a / 0xff + dst.c.g * dst.c.a * a_inv / 0xff) / out.c.a;
    out.c.b = (src.c.b * src.c.a / 0xff + dst.c.b * dst.c.a * a_inv / 0xff) / out.c.a;

    return out;
}

