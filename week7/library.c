#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
    // math.h
    printf("PI: %f\n", M_PI);
    printf("cos(PI): %f\n", cos(M_PI));
    printf("exp(3.0): %f\n", exp(3.0));
    printf("pow(3.0, 2.0): %f\n", pow(3.0, 2.0));
    printf("sqrt(9.0): %f\n", sqrt(9.0));
    printf("fabs(-2.5): %f\n", fabs(-2.5));

    // ctype.h
    printf("isalpha('a'): %d\n", isalpha('a'));
    printf("isalpha('3'): %d\n", isalpha('3'));

    printf("isdigit('a'): %d\n", isdigit('a'));
    printf("isdigit('3'): %d\n", isdigit('3'));

    // string.h
    char src[] = {'a', 'b', '\0', 'c', 'd'};
    char dst1[10];
    char dst2[10];

    strcpy(dst1, src);
    memcpy(dst2, src, 5);

    // assert.h
    int N = 10;
    int a[N];
    int n = getchar();
    n -= '0';

    assert(0 <= n && n < N);

    a[n] = 123;
    printf("a[%d]: %d", n, a[n]);

    // stdlib.h
    srand(123);
    for (int n = 0; n < 4; ++n) {
        printf("%d\n", rand());
    }

    for (int n = 0; n < 4; ++n) {
        double r = (double) rand() / RAND_MAX;
        printf("%f\n", r);
    }
    
    return 0;
}