#include <stdio.h>
typedef struct a {
    int arr[3];
} A;

int main()
{
    A a1 = {.arr = {1, 2, 3}};
    A a2 = a1;

    for (int i = 0; i < 3; ++i) {
        printf("%d, %d\n", a1.arr[i], a2.arr[i]);
        // 1, 1
        // 2, 2
        // 3, 3
    }

    a2.arr[0] = 100;  // 値を編集
    for (int i = 0; i < 3; ++i) {
        printf("%d, %d\n", a1.arr[i], a2.arr[i]);
        // 1, 100   編集がa2にだけ反映されている
        // 2, 2
        // 3, 3
    }
    return 0;
}