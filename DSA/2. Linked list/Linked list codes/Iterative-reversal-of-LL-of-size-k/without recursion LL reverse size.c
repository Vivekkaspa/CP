#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node *next;
};
// head points to first node of the linkedlist
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
    struct node *temp1, *temp2, *temp3;    
    temp1 = temp2 = temp3 = NULL;
    int i;
    n = head;
    
    while(n!=NULL){
        
        // Reversing K-nodes from n (including node n)
        i = 1;
        temp1 = n;
        c = n;
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
        
        // temp 3 store address of first node of K-group reversed list
        if(temp3==NULL)    temp3 = c;
        
        // temp2 stores last node of previous reversed K-nodes
        if(temp2!=NULL)    temp2->next = c;
        
        temp2 = temp1;
        
    }
    
    return temp3;
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
