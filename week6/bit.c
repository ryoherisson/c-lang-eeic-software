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
    unsigned char a = 3;
    unsigned char b = 6;
    unsigned char x;

    x = a & b;
    print_bit_uchar(x);
    printf("%u\n", x);

    x = a | b;
    print_bit_uchar(x);
    printf("%u\n", x);

    x = a ^ b;
    print_bit_uchar(x);
    printf("%u\n", x);

    unsigned char c = 35; // 00100011
    unsigned char y;

    y = c << 2;
    print_bit_uchar(y); // 10001100
    printf("%u\n", y);

    y = c >> 2;
    print_bit_uchar(y); // 00001000
    printf("%u\n", y);

    y = ~c;
    print_bit_uchar(y); // 11011100
    printf("%u\n", y);

    return 0;
}