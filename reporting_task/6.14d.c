#include <stdio.h>

struct real_number
{
    int x; // числитель
    int y; // знаменатель
};
  
void print_real_number(struct real_number n)
{
    float s = (float)n.x / n.y;
    printf("num: %d/%d  ==>  n = %f\n", n.x, n.y, s);
}

void change_num(struct real_number *n)
{
    int x1;
    int y1;
    printf("Enter new x: ");
    scanf("%d", &x1);
    n->x = x1;
    printf("Enter new y: ");
    scanf("%d", &y1);
    n->y = y1;
}

struct real_number sum_num(struct real_number *n1, struct real_number *n2)
{
    struct real_number sum;
    sum.x = n1->x * n2->y + n2->x * n1->y;
    sum.y = n1->y * n2->y;
    return sum;
}

struct real_number mult_num(struct real_number *n1, struct real_number *n2)
{
    struct real_number mult;
    mult.x = n1->x * n2->x;
    mult.y = n1->y * n2->y;
    return mult;
}

int main(void)
{
    struct real_number M = {.x = 2, .y = 3};
    print_real_number(M);
    struct real_number N = {.x = 3, .y = 4};
    print_real_number(N);
    change_num(&M);
    print_real_number(M);
    struct real_number A = sum_num(&M, &N);
    print_real_number(A);
    struct real_number B = mult_num(&M, &N);
    print_real_number(B);
    return 0;
}
