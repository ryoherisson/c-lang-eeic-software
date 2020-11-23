#include <stdio.h>
#define MAX_NAME_LEN 20

typedef struct point {
    int x;
    int y;
} Point;

// struct point {
//     int x;
//     int y;
// };

typedef struct rect {
    Point pt1;
    Point pt2;
    char name[MAX_NAME_LEN + 1];
} Rect;


int main()
{
    // struct point pt;
    // pt.x = 10;
    // pt.y = 30;
    // struct point pt = {.x = 10, .y = 30};
    // Point pt = {.x = 10, .y = 30};
    // printf("%d %d\n", pt.x, pt.y);

    Rect r = {.pt1 = {.x = 10, .y = 30},
              .pt2 = {.x = 25, .y = 12},
              .name = "sample_rect"};
    printf("r.pt1 = %d, %d\n", r.pt1.x, r.pt1.y);
    printf("r.pt2 = %d, %d\n", r.pt2.x, r.pt2.y);
    printf("r.name = %s\n", r.name);

    return 0;
}
