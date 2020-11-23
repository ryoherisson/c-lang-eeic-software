#include <stdio.h>

void swap(char *prefectures[], int i, int j)
{
    char *tmp = prefectures[i];
    prefectures[i] = prefectures[j];
    prefectures[j] = tmp;
}

void print_each(char *prefectures[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s-ken\n", prefectures[i]);
    }
}

int main()
{
    char s1[] = "toyama";
    char s2[] = "ishikawa";
    char s3[] = "fukui";

    char *hokuriku1[3];
    hokuriku1[0] = s1;
    hokuriku1[1] = s2;
    hokuriku1[2] = s3;

    for (int i = 0; i < 3; ++i)
    {
        hokuriku1[i][0] = 'A';
        printf("%s\n", hokuriku1[i]);
    }

    char *hokuriku2[] = {"toyama", "ishikawa", "fukui"};
    // hokuriku1[0][0] = 'a';  // Segmentation Fault
    printf("%s\n", hokuriku2[0]);

    // int *a[] = {{0, 1}, {2, 3, 4}, {5}}; // ダメ
    // printf("%d", a[0][0]);  // Segmentation Fault

    // これはOK
    // int arr1[] = {0, 1};
    // int arr2[] = {2, 3, 4};
    // int arr3[] = {5};
    // int *b[] = {arr1, arr2, arr3};
    // printf("%d\n", b[0][0]);   // 0

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int *v[] = {arr1, arr2};
    int **p;
    p = v;
    printf("v[0][1]: %d\n", p[0][1]); // 2
    printf("v[1][0]: %d\n", p[1][0]); // 4
    printf("v[1][1]: %d\n", *(*(p+1)+1)); // 5

    print_each(hokuriku2, 3);
    swap(hokuriku2, 1, 2);
    print_each(hokuriku2, 3);
    return 0;
}