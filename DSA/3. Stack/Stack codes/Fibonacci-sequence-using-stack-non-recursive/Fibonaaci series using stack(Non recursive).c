#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};

struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node*tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}

int main(){
	int sum=0;
	int v;
	while(!isEmpty){
	   int v=pop(top);
	   if ((v-1)>1) push(top,v-1);
       else sum=sum+(v-1);
       if ((v-2)>1) push(top,v-2) ;
       else sum=sum+(v-2);
   }
   printf(" '%d'th term Fibonacci number is:%d\n",v,sum);
   scanf("%d",&v);
   
   
   return 0;
       
	
}
