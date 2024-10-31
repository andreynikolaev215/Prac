// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <stdio.h>

struct color_point
{
    float x;
    float y;
    char* color;
};
  
void print_c_point(struct color_point p)
{
    printf("x: %f \n", p.x);
    printf("y: %f \n", p.y);
    printf("color: %s \n", p.color);
}

void change_coords(struct color_point *p)
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

void change_color(struct color_point *p, char* new_color)
{
    p->color = new_color;
}

int main(void)
{
    struct color_point M = {.x = 14, .y = 6, .color = "red"};
    print_c_point(M);
    printf("Enter new color: ");
    char c[20];
    fgets(c, 20, stdin);
    change_coords(&M);
    change_color(&M, c);
    print_c_point(M);
    return 0;
}
