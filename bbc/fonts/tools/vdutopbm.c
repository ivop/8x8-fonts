#include <stdio.h>

static unsigned char bitmap[256][8];

void main(void) {
    int c;
    while ((c = fgetc(stdin)) == 23) {
        c = fgetc(stdin);
        for (int i=0; i<8; i++) {
            bitmap[c][i] = fgetc(stdin);
        }
    }
    printf("P4\n%d %d\n", 32*8, 8*8);
    for (int m=0; m<8; m++) {
        c = m*32;
        for (int p=0; p<8; p++) {
            for (int k=0; k<32; k++) {
                fputc(bitmap[c+k][p], stdout);
            }
        }
    }
}
