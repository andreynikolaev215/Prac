// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    double data;
    struct queue *next;
};


void putqu(struct queue **head, double value)
{
    struct queue *tmp = *head;
    if ((*head) == NULL)
    {
        printf("%d", 1);
        *head = (struct queue *)malloc(sizeof(struct queue));
        (*head)->next = NULL;
        (*head)->data = value;
    } 
    else
    {
    printf("%d", 2);
    while ((*head)->next != NULL) (*head) = (*head)->next;
    (*head)->next = (struct queue *)malloc(sizeof(struct queue));
    (*head)->next->data = value;
    (*head)->next->next = NULL;
    (*head) = tmp;
    }
}

int getqu(struct queue **head){
    double value;
    value = (*head)->data;
    (*head) = (*head)->next;
    return value;
}

int sizequ(struct queue *head)
{
    int n = 0;
    for(; head != NULL; head = head->next){
        ++n;
    }
    return n;
}


void delete_queue(struct queue *q)
{
    struct queue *tmp = q;
    struct queue *n;
    while (q != NULL)
    {
        n = q;
        q = q->next;
        free(n);
    }
    q = tmp;
}

void print_list(struct queue *head)
{
    struct queue *tmp = head;
    printf("\n");
    printf("Your list: \n");
    while (head != NULL)
    {
        printf("%lf\n", head->data);
        head = head->next;
    }
    head = tmp;
}

int main(void){
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    struct queue *tmp = head;
    head = NULL;
    
    double value;
    printf("Enter new elem: ");
    scanf("%lf", &value);  
    putqu(&head, value);
    printf("Enter new elem: ");
    scanf("%lf", &value);  
    putqu(&head, value);
    print_list(head);
    int l = sizequ(head);
    printf("\n");
    printf("Size of your list: %d", l);
    printf("\n");
    int k = getqu(&head);
    print_list(head);
    printf("\n");
    printf("The received element: ");
    printf("%d", k);
    return 0;
}
