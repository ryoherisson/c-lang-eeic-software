#include <stdio.h>
typedef struct {
    int x;
    int y;
} Point;


void print_point(Point pt) {
    printf("pt: (%d, %d)\n", pt.x, pt.y);
}

// copyされる
Point add_point(Point pt1, Point pt2) {
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}


int main()
{
    Point pt_a = {.x = 10, .y = 2};
    Point pt_b = {.x = 3, .y = 5};
    Point out = add_point(pt_a, pt_b);
    print_point(pt_a); // pt: (10, 2)
    print_point(pt_b); // pt: (3, 5)
    print_point(out);  // pt: (13, 7)
    print_point(pt_a); // pt: (10, 2)  // pt_aは変更されない

    return 0;
}