#include <stdio.h>
#define N 5

void set_one(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = 1;
    }
}

void my_strcpy(char *s1, const char *s2)
{
    int i = 0;
    while ((s1[i] = s2[i]) != '\0')
    {
        ++i;
    }
}

int main()
{
    int a[N] = {2, 6, 1, 4, 7};
    int sum1, sum2;
    sum1 = sum2 = 0;

    for (int i = 0; i < N; ++i) 
    {
        sum1 += a[i];
    }
    printf("sum1: %d\n", sum1);

    int *p;
    for (p = &a[0]; p < &a[N]; ++p)
    {
        sum2 += *p;
    }
    printf("sum2: %d\n", sum2);

    int b[] = {1, 2, 3, 4, 5}, *q;
    q = b;
    printf("sizeof(p): %lu\n", sizeof(q));
    printf("sizeof(a): %lu\n", sizeof(b));

    // 配列はpointerを渡す。最初の要素のアドレス。
    set_one(b, 5);
    printf("%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);

    char amsg[] = "abc";
    char *pmsg = "abc";
    printf("%s %s\n", amsg, pmsg);

    char str1[] = "aaaaaaaaaa";
    char str2[] = "hoge";
    printf("str1: %s\n", str1); // str1: aaaaaaaaaa
    my_strcpy(str1, str2);
    printf("str1: %s\n", str1); // str1: hoge
    // ここでは、str1は以下のようになっています：
    // {'h', 'o', 'g', 'e', '\0', 'a', 'a', 'a', 'a', 'a', '\0'}

    return 0;
}