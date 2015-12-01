void render(char* buf, int width, int height) {

    int x, y;
    for(x = 0; x < width; x++) {
        buf[x*3    ] = x;
        buf[x*3 + 1] = x;
        buf[x*3 + 2] = x;
    }

}
