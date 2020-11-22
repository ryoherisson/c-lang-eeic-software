#include <stdio.h>

int main()
{
    int c = getchar();

    // ctrl + D or ctrl + c
    // while (c != EOF)
    // {
    //     putchar(c);
    //     c = getchar();
    // }

    // while (c != EOF)
    // {
    //     if (c == '\n') {
    //         printf("You entered a new line\n");
    //     } else {
    //         printf("You entered %c\n", c);
    //     }
    //     c = getchar();
    // }

    long nc;
    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);

    return 0;
}