#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node *next;
};
// head points to first noed of the linkedlist
struct node *head;
// inserts value at the front of LinkedList head
void insertAtBegin(int value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->v = value;
    if(head==NULL){
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}
// display linkedlist
void displayLL(struct node* head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d->",temp->v);
        temp = temp->next;
    }
    printf("NULL \n\n");
}
struct node* reverseLLK(struct node* head, int k) {
    
    if(head==NULL||head->next==NULL)    return head;
    
    struct node* p;    //previous
    struct node* c;    //current
    struct node* n;    //next
    struct node* h;    
    int i = 1;
    h = head;
    c = head;
    p = NULL;
    n = c->next;
    
    while (n != NULL) {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
        ++i;
        if (i == k)
            break;
    }
    
    c->next = p;
    h->next = reverseLLK(n, k);    
    
    return c;
}
int main(){
    
    for(int i=1;i<=12;++i){
        insertAtBegin(i);
    }
    
    printf("LinkedList:\n");
    displayLL(head);
    
    head = reverseLLK(head,4);
    
    printf("LinkedList after Reverse:\n");
    displayLL(head);
    
}
