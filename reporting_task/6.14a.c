#include<stdio.h>

struct point
{
    float x;
    float y;
};
  
void print_point(struct point p)
{
    printf("x: %f \n", p.x);
    printf("y: %f \n", p.y);
}

void change_coords(struct point *p)
{
    float x1;
    float y1;
    printf("Enter new x: ");
    scanf("%f", &x1);
    p->x = x1;
    printf("Enter new y: ");
    scanf("%f", &y1);
    p->y = y1;
}

int main(void)
{
    struct point M = {.x = 14, .y = 6};
    print_point(M);
    change_coords(&M);
    print_point(M);
    return 0;
}
