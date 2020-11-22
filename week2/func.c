#include <stdio.h>


double absolute(double src)
{
    double dst;
    if (0 < src) {
        dst = src;
    } else {
        dst = -src;
    }
    return dst;
}

float average(float a, float b)
{
    return (a + b) / 2.0;
}

int power(int a, int b)
{
    int ret = 1;
    for (int i = 0; i < b; ++i)
    {
        ret *= a;
    }
    return ret;
}

int main()
{
    double v = -0.4;
    double result = absolute(v);

    printf("absolute value of %f is %f\n", v, result);
    printf("absolute value of %f is %f\n", 0.5, absolute(0.5));
    printf("average value of %f and %f is %f\n", 55.0, 12.0, average(55.0, 12.0));
    printf("%d powerd by %d is %d\n", 2, 10, power(2, 10));


    return 0;
}