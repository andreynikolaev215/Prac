#include <stdio.h>
#include <stdlib.h>


struct node
{
    char *data;
    struct node *next;
};
int occurrence_element(struct node *head, char *elem)
{
    int a = 0;
    struct node *tmp = head;
    while (head->data != ".")
    {
        if (head->data == elem) a = 1;
        head = head->next;
    }
    head = tmp;
    return a;
}

void make_new_list(struct node *head1, struct node *head2, struct node *head3){
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    struct node *tmp3 = head3;
    
    while (head1->data != ".")
    {
        if (occurrence_element(head2, head1->data) == 0)
        {
            head3->data = head1->data;
            head3->next = (struct node *)malloc(sizeof(struct node));
            head3 = head3->next;   
        }
        head1 = head1->next;
    }
    head1 = tmp1;
    head2 = tmp2;
    while (head2->data != ".")
    {
        if (occurrence_element(head1, head2->data) == 0)
        {
            head3->data = head2->data;
            head3->next = (struct node *)malloc(sizeof(struct node));
            head3 = head3->next;   
        }
        head2 = head2->next;
    }
    head3->next = (struct node *)malloc(sizeof(struct node));
    head3->data = ".";
    head3->next = NULL;
    head1 = tmp1;
    head2 = tmp2;
    head3 = tmp3;
}

void print_list(struct node *head)
{
    struct node *tmp = head;
    while (head->data != "."){
        printf("%s\n", head->data);
        head= head->next;
    }
    head = tmp;
}

int main(void){
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp1 = head1;
    
    printf("first list: \n");
    
    head1->data = "hello";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;
    
    head1->data = "abcd";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;
    
    head1->data = "tree";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;
    
    head1->data = "stack";
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1 = head1->next;
    
    head1->data = ".";
    head1->next = NULL;
    head1 = tmp1;
    
    
    print_list(head1);
    
    printf("\n");
    
    
    printf("second list: \n");
    
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp2 = head2;
    
    head2->data = "tree";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;
    
    head2->data = "stack";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;
    
    head2->data = "one";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;
    
    head2->data = "queue";
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2 = head2->next;
    
    head2->data = ".";
    head2->next = NULL;
    head2 = tmp2;
    
    
    print_list(head2);
    
    printf("\n");
    
    
    printf("third list: \n");
    
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp3 = head3;
    
    make_new_list(head1, head2, head3);
    
    
    print_list(head3);
    
    
    return 0;
}
}
