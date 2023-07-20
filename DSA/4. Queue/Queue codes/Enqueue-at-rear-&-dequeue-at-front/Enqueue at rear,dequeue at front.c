#include <stdio.h>
#include <stdlib.h>
 
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(f==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(r==NULL){
            f=r=n;
        }
        else{
            f->next = f;
            f=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = r;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        r = r->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
 
int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}

