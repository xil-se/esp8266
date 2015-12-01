void render(char* buf, int width, int height, int t) {

    int x, y;
    int stride = width * 3;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            buf[y*stride + x*3    ] = t%4;
            buf[y*stride + x*3 + 1] = y*4;
            buf[y*stride + x*3 + 2] = x/4;
        }
    }

}
