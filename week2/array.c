#include <stdio.h>

int main()
{
    int a[3];

    a[0] = 12;
    a[1] = 3;
    a[2] = 5;

    for (int n = 0; n < 3; ++n)
    {
        // printf("a[%d] is %d\n", n, a[n]);
        printf("The address of a[%d] is %p\n", n, &a[n]);
    }

    // 2 dimention
    int mat[2][3] = {
        {32,  5, 76},
        { 1, 12,  8},
    };

    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < 3; ++x) {
            // printf("%d, ", mat[y][x]);
            printf("%p, ", &mat[y][x]);
        }
        printf("\n");
    }

    // 3 dimension
    int mat3d[2][2][3] = {
        {
            {32,  5, 76},
            { 1, 12,  8},
        }, 
        {
            {16,  2, 38},
            { 0,  6,  4},
        }
    };

    for (int z = 0; z < 2; ++z) {
        for (int y = 0; y < 2; ++y) {
            for (int x = 0; x < 3; ++x) {
                // printf("%d, ", mat3d[z][y][x]);
                printf("%p, ", &mat3d[z][y][x]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}