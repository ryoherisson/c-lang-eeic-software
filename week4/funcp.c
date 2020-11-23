#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part)
{
    *int_part = (long) x;
    *frac_part = x - *int_part;
}

int *min(int *a, int *b)
{
    if (*a < *b) {
        return a;
    } else {
        return b;
    }
}

void max_min(int a[], int n, int *max, int *min)
{
    *max = 0;
    *min = 1e9;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
}

void f1(int *a) {
    int b = 10;
    a = &b;
}

int *f2() {
    int b = 10;
    return &b;
}

int main()
{
    long n;
    double d;
    decompose(3.14, &n, &d);
    printf("n: %ld, d: %f\n", n, d);

    int num1 = 9;
    int num2 = 3;
    int *ret;
    ret = min(&num1, &num2);
    printf("*ret: %d, ret: %p\n", *ret, ret);
    printf("&num1: %p, &num2: %p\n", &num1, &num2);
    num2 = 10;
    printf("*ret: %d, ret: %p\n", *ret, ret);


    int array[5] = {7, 2, 10, 3, 5};
    int max_val, min_val;
    max_min(array, 5, &max_val, &min_val);
    printf("max: %d, min: %d\n", max_val, min_val);

    // 無効なはず？
    int a = 10;
    f1(&a);
    printf("f1: %d\n", a);
    int *p = f2();
    printf("f2: %d\n", *p);

    return 0;
}