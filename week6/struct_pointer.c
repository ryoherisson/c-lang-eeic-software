#include <stdio.h>
#include <string.h>
#define MAX_LEN 6

typedef struct {
    int x;
    int y;
} Point;

typedef struct str_by_arr {
    char s[MAX_LEN + 1];
} StrByArr;

typedef struct str_by_ptr {
    char *s;
} StrByPtr;


int main()
{
    Point pt = {.x = 10, .y = 30};
    Point *q;
    q = &pt;
    printf("%d\n", (*q).x);
    printf("%d\n", q->x); // (*q).xと同じ

    // copy
    StrByArr x1 = {.s = "hoge"};
    StrByArr x2 = x1;
    strcpy(x1.s, "fuga");
    printf("x1.s: %s\n", x1.s);
    printf("x2.s: %s\n", x2.s);

    // pointer
    char buff[] = "hoge";
    StrByPtr y1 = {.s = buff};
    StrByPtr y2 = y1;
    strcpy(y1.s, "fuga");
    printf("x1.s: %s\n", y1.s);
    printf("x2.s: %s\n", y2.s);
    printf("%p %p\n", y1.s, y2.s); // 同じアドレス

    return 0;
}