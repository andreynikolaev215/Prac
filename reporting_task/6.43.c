#include <stdio.h>
#include <stdlib.h>

struct stack
{
    double data;
    struct stack *next;
};

void pushst(struct stack **head, double value)
{
    struct stack *tmp = *head;
    if ((*head) == NULL)
    {
        *head = (struct stack *)malloc(sizeof(struct stack));
        (*head)->next = NULL;
        (*head)->data = value;
    } 
    else
    {
    while ((*head)->next != NULL) (*head) = (*head)->next;
    (*head)->next = (struct stack *)malloc(sizeof(struct stack));
    (*head)->next->data = value;
    (*head)->next->next = NULL;
    (*head) = tmp;
    }
}

int popst(struct stack **head)
{
    struct stack *tmp = *head;
    struct stack *q;
    q = (struct stack *)malloc(sizeof(struct stack));
    double value;
    if ((*head) == NULL) return 0;
    else if ((*head)->next == NULL)
    {
        value = (*head)->data;
        *head = NULL;
        return value;
    }
    else if ((*head)->next != NULL)
    {
        while ((*head)->next->next != NULL) *head = (*head)->next;
    q = (*head)->next;
    value = (*head)->next->data;
    free(q);
    (*head)->next = NULL;
    *head = tmp;
    return value;
    }
}

int sizest(struct stack *head)
{
    int n = 0;
    for(; head != NULL; head = head->next){
        ++n;
    }
    return n;
}

void delete_stack(struct stack *q)
{
    struct stack *tmp = q;
    struct stack *n;
    while (q != NULL)
    {
        n = q;
        q = q->next;
        free(n);
    }
    q = tmp;
}

void print_list(struct stack *head)
{
    struct stack *tmp = head;
    printf("\n");
    printf("Your list: \n");
    while (head != NULL)
    {
        printf("%lf\n", head->data);
        head = head->next;
    }
    head = tmp;
}

int main(){
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    struct stack *tmp = head;
    head = NULL;
    
    double value;
    for (int i = 0; i < 4; ++i)
    {
        printf("Enter new elem: ");
        scanf("%lf", &value);  
        pushst(&head, value);
    }
    print_list(head);
    int l = sizest(head);
    printf("\n");
    printf("Size of your list: %d", l);
    printf("\n");
    for (int i = 0; i < 4; ++i)
    {
        int k = popst(&head);
        print_list(head);
        printf("\n");
        printf("The received element: %d\n", k);
    }
    return 0;
}
