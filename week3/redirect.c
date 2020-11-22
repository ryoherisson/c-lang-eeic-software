#include <stdio.h>

// ./redirect < sample.dat > out.dat 更新
// ./redirect < sample.dat >> out.dat　追記

int main() 
{
    int c = getchar();
    while (c != EOF)
    {
        putchar('/');
        putchar(c);
        c = getchar();
    }
    return 0;
}