#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "abc";
    unsigned long len = strlen(s1);
    printf("sizeof(s1): %lu, strlen(s1): %lu\n", sizeof(s1), len);

    char s2[10];
    strcpy(s2, "hello");
    printf("%s\n", s2);
    printf("sizeof(s2): %lu, strlen(s2): %lu\n", sizeof(s2), strlen(s2));

    char s3[10] = "hoge";
    printf("sizeof(s3): %lu, strlen(s3): %lu\n", sizeof(s3), strlen(s3));
    strcat(s3, "fuga");
    printf("%s\n", s3);
    printf("sizeof(s3): %lu, strlen(s3): %lu\n", sizeof(s3), strlen(s3));

    char s4[] = "abc";
    char s5[] = "bbcde";
    int cmp = strcmp(s4, s5);
    printf("%d\n", cmp);

    return 0;
}