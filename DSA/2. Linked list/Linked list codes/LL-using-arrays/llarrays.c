#include <stdio.h>
#include <stdlib.h>

struct No{
 int data;
 struct Node *next;
}*first=NULL;

void create(int A[],int n){
   int i;
   struct Node *t,*last;
   first=(struct Node *)malloc(sizeof(struct Node));
   first->data=A[0];
   first->next=NULL;
   last=first;
 
 for(i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
 }
}

void Display(struct Node *p){
   while(p!=NULL){
      printf("%d ",p->data);
      p=p->next;
 }
  }

  
void RDisplay(struct Node *p){
   if(p!=NULL){
       RDisplay(p->next);
       printf("%d ",p->data);
 }
}


void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;
    
    if(index < 0 || index > p)
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    
    if(index == 0){
       t->next=first;
       first=t;
 }else{
      for(i=0;i<index-1;i++)
         p=p->next;
         t->next=p->next;
         p->next=t;
 }

}


int Delete(struct Node *p,int index){
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index >p)
        return -1;
    if(index==1){
          q=first;
          x=first->data;
          first=first->next;
          free(q);
        return x;
     }
	 else{
         for(i=0;i<index-1;i++){
               q=p;
               p=p->next;
       }
     q->next=p->next;
     x=p->data;
     free(p);
    return x;
 }
}


int main()

{

 struct Node *temp;

 int A[]={3,5,7,10,25,8,32,2};

 create(A,8);

 
 Insert(first,0,15); 

 Insert(first,0,8); 

 Insert(first,0,9); 

 Insert(first,1,10);
 

 Display(first);

 printf(“%d\n",Delete(first),2);

 Display(first);
 

 return 0;

}
