#include <stdio.h>
#include <stdlib.h>

typedef struct inode {
    void *data;
    struct inode *next;
} inode;

typedef inode *queue;

typedef struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef tnode *tree;

void putqu(queue *q, void *value)
{
    queue new = (queue)malloc(sizeof(inode));
    new -> data = value;
    new -> next = NULL;
    if (*q == NULL)
    {
        *q = new;
        return;
    }
    for (; (*q) -> next != NULL; q = &((*q) -> next));
    (*q) -> next = new;
}

void *getqu(queue *q)
{
    if (*q == NULL) return NULL;
    queue old = *q;
    void *value = old -> data;
    *q = (*q) -> next;
    free(old);
    return value;
}

int sizequ(queue q)
{
    int n = 0;
    for(; q != NULL; q = q -> next) ++n;
    return n;
}

void clearqu(queue *q)
{
    queue del;
    for(del = *q; del != NULL; del = *q)
    {
        *q = del -> next;
        free(del);
    }
}

int count_level_tree(tree tr, int number)
{
    if ((number < 0) || (tr == NULL)) return 0;
    int n, last = 1, next = 0;
    queue q = NULL;
    putqu(&q, tr);
    for(n = 0; (q != NULL) && (n < number); ++n)
    {
        tree buff;

        for(; last > 0; --last)
        {
            buff = (tree)getqu(&q);
            if (buff -> left != NULL)
            {
                ++next;
                putqu(&q, buff -> left);
            }
            if (buff -> right != NULL)
            {
                ++next;
                putqu(&q, buff -> right);
            }
        }
        if (next == 0) break;
        last = next;
        next = 0;
    }
       clearqu(&q);
    return last;
}

/*void printqu(queue q)
{
    for(; q != NULL; q = q -> next) printf("%d ", ((tree)(q -> data)) -> data);
    printf("\n");
}*/

void printtr(tree tr)
{
    int last = 1, next = 0;
    queue q = NULL;
    putqu(&q, tr);
    for(;;)
    {
        tree buff;
        for(; last > 0; --last)
        {
            buff = (tree)getqu(&q);
            printf("%d ", buff -> data);
            if (buff -> left != NULL)
            {
                ++next;
                putqu(&q, buff -> left);
            }
            if (buff -> right != NULL)
            {
                ++next;
                putqu(&q, buff -> right);
            }
        }
        if (next == 0) break;
        printf("\n");
        last = next;
        next = 0; 
    }
    printf("\n");
    clearqu(&q);
}

void addtr(tree *tr, int value)
{
    if (*tr == NULL)
    {
        *tr = (tree)malloc(sizeof(tnode));
        (*tr) -> data = value;
        (*tr) -> left = NULL;
        (*tr) -> right = NULL;
        return;
    }
    if ((*tr) -> data > value)
    {
        addtr(&((*tr) -> left), value);
    } 
    else 
    {
        addtr(&((*tr) -> right), value);
    }
}

void cleartr(tree *tr)
{
    if (*tr == NULL) return;
    cleartr(&((*tr) -> left));
    cleartr(&((*tr) -> right));
    free(*tr);
}

int main()
{
    tree tr = NULL;
    printf("Enter the number of items: ");
    int n;
    int value;
    scanf("%d", &n);
    printf("\n");
    for (; n > 0; --n)
    {
        printf("Enter new elem: ");
        scanf("%d", &value);  
        addtr(&tr, value);
    }
    printf("----------\n");
    printtr(tr);
    printf("----------\n");
    n = count_level_tree(tr, 2);
    printf("%d\n", n);
    cleartr(&tr);
    return 0;

}
