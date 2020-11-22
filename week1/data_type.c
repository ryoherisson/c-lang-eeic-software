#include <stdio.h>

int main()
{
    int height;
    int width;
    height = 10;
    width = 5;
    int area;
    area = height * width;
    printf("Height: %d Width: %d Area: %d\n", height, width, area);

    char c1, c2, c3;
    c1 = 12;
    c2 = 127;
    c3 = 140; // overflow
    printf("c1: %d, c2: %d, c3: %d, c1-c2: %d\n", c1, c2, c3, c1 - c2);

    float f = 123.5;
    printf("f=%f, f/3=%f\n", f, f / 3);

    printf("address of height is %p. address of width is %p\n", &height, &width);
    printf("address of c1 is %p. address of c2 is %p. address of c3 is %p\n", &c1, &c2, &c3);

    return (0);
}
