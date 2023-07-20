//Linked list traversal & creation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;	
};

void linkedlisttraversal(struct Node *temp)
{
	while (temp!=NULL){
	   printf("Element is : %d\n",temp->data);
	   temp=temp->next;
}
}

int main()
{
	struct Node*begin;
	struct  Node*first;
	struct  Node*second;
	struct  Node*third;
	
	begin=(struct Node*)malloc(sizeof(struct Node));
	first=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	
	begin->data=7;
	begin->next=first;
	
	first->data=14;
	first->next=second;
	
	second->data=21;
	second->next=third;
	
	third->data=28;
	third->next=NULL;
	
	linkedlisttraversal(begin);
	return 0;
}
	   
	  
