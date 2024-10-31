// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <stdio.h>

struct complex_number
{
    float x; // действительная часть
    float y; // мнимая часть
};
  
void print_complex_number(struct complex_number n)
{
    printf("num: (%f, %f)\n", n.x, n.y);
}

void change_num(struct complex_number *n)
{
    float x1;
    float y1;
    printf("Enter new x: ");
    scanf("%f", &x1);
    n->x = x1;
    printf("Enter new y: ");
    scanf("%f", &y1);
    n->y = y1;
}

struct complex_number sum_num(struct complex_number *n1, struct complex_number *n2)
{
    struct complex_number sum;
    sum.x = n1->x + n2->x;
    sum.y = n1->y + n2->y;
    return sum;
}

int main(void)
{
    struct complex_number M = {.x = 14, .y = 6};
    print_complex_number(M);
    struct complex_number N = {.x = 3, .y = -4};
    print_complex_number(N);
    change_num(&M);
    print_complex_number(M);
    struct complex_number A = sum_num(&M, &N);
    print_complex_number(A);
    return 0;
}
