#include <stdio.h>

int main()
{
    int a = 10;
    int *p;
    int **q;
    p = &a;
    q = &p;

    printf("&a: %p, p: %p, q: %p\n", &a, p, q);
    printf("*p: %d, *q: %d\n", *p, **q);

    printf("a + 3 = %d\n", *p + 3);

    *p = 13;
    printf("a: %d, *p: %d, *q: %d\n", a, *p, **q);

    (*p)++;
    printf("a: %d, *p: %d, *q: %d\n", a, *p, **q);

    printf("*&a: %d, &*a: error, *&p: %d, &*p: %p\n", *&a, *p, &*q);

    return 0;
}