#include <stdio.h>

void find_largest(int a[], int n, int *max)
{
    *max = a[0];
    for (int i = 0; i < n; ++i)
    {
        if (*max < a[i])
        {
            *max = a[i];
        }
    }
}

void find_largest2(int a[], int n, int **p_max)
{
    *p_max = &a[0];

    for (int i = 0; i < n; ++i)
    {
        if (**p_max < a[i])
        {
            *p_max = &a[i];
        }
    }
}

int main()
{
    int arr[] = {3, 6, 2};
    int ans;
    find_largest(arr, 3, &ans);
    printf("max: %d\n", ans);

    int *p_ans;
    find_largest2(arr, 3, &p_ans);
    // p_ansはarr[]のアドレスが格納されているので、arr[]の値を変えるとp_ansの値も変わる
    arr[1] = 10;
    printf("max: %d\n", *p_ans);

    return 0;
}