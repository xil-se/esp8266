
#include <stdint.h>

typedef enum {
    ledmate_mode_invalid            = 0,
    ledmate_mode_text_left          = 1,
    ledmate_mode_text_right         = 2,
    ledmate_mode_bounce_text        = 3,
    ledmate_mode_bounce_text_left   = 4,
    ledmate_mode_bounce_text_right  = 5,
    ledmate_mode_image_left         = 6,
    ledmate_mode_image_right        = 7,
    ledmate_mode_image_up           = 8,
    ledmate_mode_image_down         = 9,
    ledmate_mode_bounce_image_left  = 10,
    ledmate_mode_bounce_image_right = 11,
} ledmate_mode;

#pragma pack(push, 1)
typedef struct {
    uint8_t         mode;
    uint8_t         payload[];
} ledmate_header;

typedef struct {
    uint8_t         r;
    uint8_t         g;
    uint8_t         b;
    char            text[];
} ledmate_text;

typedef struct {
    uint8_t         r;
    uint8_t         g;
    uint8_t         b;
    uint8_t         duration;
    char            text[];
} ledmate_bounce_text;

typedef struct {
    uint8_t         a;
    uint8_t         r;
    uint8_t         g;
    uint8_t         b;
} ledmate_pixel;

typedef struct {
    uint8_t         x;
    uint8_t         y;
    ledmate_pixel   pixels[];
} ledmate_image;
#pragma pack(pop)

void ledmate_push_msg(const char *_str, int length);
void ledmate_init(unsigned char* _buf, int _width, int _height);
void ledmate_render(int _t);
