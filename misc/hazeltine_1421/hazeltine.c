// cc -o hazeltine hazeltine.c
// ./hazeltine < romdump.bin > font.pbm
// CC0/BSD-0 2024 by Ivo van Poorten
#include <stdio.h>

static unsigned char img[32][4*16];

int main(int argc, char **argv) {
    for (int line=0; line<4; line++) {
        for (int x=0; x<32; x++) {
            for (int y=0; y<16; y++) {
                img[x][(line*16)+y] = getchar();
            }
        }
    }
    puts("P4\n256 64");
    for (int y=0; y<4*16; y++) {
        for (int x=0; x<32; x++) {
            putchar(img[x][y]);
        }
    }
}

