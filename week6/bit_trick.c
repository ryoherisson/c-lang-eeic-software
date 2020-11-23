#include <stdio.h>

void print_bit_uchar(unsigned char c) {
    for (int i = 0; i < 8; ++i)
    {
        if (c & 1 << (7 - i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    int n = 3;
    for (unsigned char b = 0; b < (1 << n); ++b)
    {
        printf("b: ");
        print_bit_uchar(b);
        printf("{");
        if (b & 0b00000001) {
            printf("A, ");
        }
        if (b & 0b00000010) {
            printf("B, ");
        }
        if (b & 0b00000100) {
            printf("C, ");
        }
        printf("}\n");
    }
    return 0;
}