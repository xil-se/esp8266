#include <unistd.h>
#include <stdio.h>

void ledmate_init(unsigned char* buf, int width, int height);
void ledmate_render(int t);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define CLAMP(a, b, x) MIN(MAX((x), (a)), (b))

void print_fb(unsigned char* buf, int width, int height) {
    char text[width*height*3*4*20+100];
    char *text_cur = text;
    printf("\033[0;0H");
    for(int y = 0; y < height / 2; y++) {
        unsigned char upper[width*3];
        unsigned char lower[width*3];
        int x, pos;
        for(x = 0; x < width; x++) {
            int start1 = y*width*3*2 + x*3;
            int start2 = y*width*3*2 + width*3 + (width - 1 - x)*3;
            int c = 16;
            upper[x*3 + 1] = CLAMP(0, 255, c*buf[start1]);
            upper[x*3    ] = CLAMP(0, 255, c*buf[start1 + 1]);
            upper[x*3 + 2] = CLAMP(0, 255, c*buf[start1 + 2]);
            lower[x*3 + 1] = CLAMP(0, 255, c*buf[start2]);
            lower[x*3    ] = CLAMP(0, 255, c*buf[start2 + 1]);
            lower[x*3 + 2] = CLAMP(0, 255, c*buf[start2 + 2]);
        }
        for(x = 0; x < width; x++) {
            pos = sprintf(text_cur, "\033[38;2;%d;%d;%d;48;2;%d;%d;%dm▀",
                    upper[x*3], upper[x*3 + 1], upper[x*3 + 2],
                    lower[x*3], lower[x*3 + 1], lower[x*3 + 2]);
            text_cur += pos;
        }
        pos = sprintf(text_cur, "\033[0m\n");
        text_cur += pos;
    }
    printf("%s\n", text);
}


int main(void) {
    int width = 144;
    int height = 8;
    int bpp = 3;
    unsigned char buf[width * height * bpp];
    int t = 0;

    ledmate_init(buf, width, height);
    for(;;t++) {
        ledmate_render(t);
        print_fb(buf, width, height);
        fflush(stdout);
        usleep(1000000 / 20);
    }

    return 0;
}
