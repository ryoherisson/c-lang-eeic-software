#include <stdio.h>

// double avg_mat(int height, int width, int (*mat)[width])
double avg_mat(int height, int width, int mat[][width])
{
    double sum = 0.0;
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            sum += mat[h][w];
        }
    }
    return sum / (height * width);
}

double avg_mat2(int *mat, int num_element)
{
    double sum = 0.0;
    for (int i = 0; i < num_element; ++i)
    {
        sum += mat[i];
    }
    return sum / num_element;
}

int main()
{
    char hokuriku2[][9] = {"toyama", "ishikawa", "fukui"};
    for (int i = 0; i < 3; ++i)
    {
        printf("%s\n", hokuriku2[i]);
    }

    // pointer配列ではこの書き方はできない.
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int (*p)[3];  // 「int 3つ分」を1単位とするポインタ
    p = arr;      // p と p + 1 の間の値（アドレス）の差は12（つまりint3つ分） 
    printf("%p %p\n", &arr[0], &arr[1]); // 0x7fff571015f0 0x7fff571015fc  つまり差は12
    printf("%p %p\n", p, p + 1);         // 0x7fff571015f0 0x7fff571015fc

    printf("avg of arr: %.1f\n", avg_mat(2, 3, arr)); // 3.5


    printf("%f\n", avg_mat2(&arr[0][0], 2 * 3));
    printf("%f\n", avg_mat2(arr[0], 2 * 3)); // なぜ?

    return 0;
}