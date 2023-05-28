#include <stdio.h>

static char font[1024];
static char image[32][32];

int main(int argc, char **argv) {
    int r = fread(&font, 1, 1024, stdin);
    printf("P4\n%d %d\n", 32*8, 4*8);

    for (int y=0; y<4; y++)
        for (int x=0; x<32; x++)
            for (int i=0; i<8; i++)
                image[y*8+i][x] = font[(y*32+x)*8+i];

    for (int i=0; i<32; i++)
        fwrite(&image[i], 1, 32, stdout);
}

