#include <stdio.h>

static char font[2560];
static char image[80][32];

int main(int argc, char **argv) {
    int r = fread(&font, 1, 2048, stdin);
    printf("P4\n%d %d\n", 32*8, 8*10);

    for (int y=0; y<8; y++)
        for (int x=0; x<32; x++)
            for (int i=2; i<10; i++)
                image[y*10+i][x] = font[(y*32+x)*10+i];

    for (int i=0; i<80; i++)
        fwrite(&image[i], 1, 32, stdout);
}

