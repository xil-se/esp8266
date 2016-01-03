#ifndef ALPHA_BLEND
#define ALPHA_BLEND

#include <stdint.h>

#ifdef BIG_ENDIAN
typedef union {
    struct {
        uint8_t     a;
        uint8_t     r;
        uint8_t     g;
        uint8_t     b;
    } c;
    uint32_t    u;
} color;
#else
typedef union {
    struct {
        uint8_t     b;
        uint8_t     g;
        uint8_t     r;
        uint8_t     a;
    } c;
    uint32_t    u;
} color;
#endif // BIG_ENDIAN

color alpha_blend(const color src, const color dst);

#endif // ALPHA_BLEND
