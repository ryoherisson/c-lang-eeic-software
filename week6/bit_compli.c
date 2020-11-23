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
    int i = 3;
    unsigned char mask =~(1 << i);
    print_bit_uchar(mask);

    unsigned char a = 0b00001110;
    a = a & mask;
    print_bit_uchar(a);
    return 0;
}