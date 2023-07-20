#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void linkedlisttraversal(struct Node* ptr)
{
	printf("List of elements\n");
	while(ptr!=NULL){
		printf("%d-->",ptr->data);
		ptr=ptr->next;	
	}
}
bool searchnode(struct Node* begin,int key)
{
 struct Node* ptr=head;
 
 while(ptr!=NULL){
 	if(ptr->data==key){
 	  return true;
 	  ptr=ptr->next;
 }
 return false;
}
	

struct insertAtFirst(struct Node* begin,int data)
{
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	
	ptr->next=begin;
	return ptr;	
}



int main()
{
	struct Node* begin;
	struct Node* second;
	struct Node* third;
	struct Node* fourth;
	struct Node* fifth;
	struct Node* last;
	
	begin=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	fourth=(struct Node*)malloc(sizeof(struct Node));
	fifth=(struct Node*)malloc(sizeof(struct Node));
	last=(struct Node*)malloc(sizeof(struct Node));
	
	begin->data=4;
	begin->next=second;
	
	secpnd->data=4;
	second->next=third;
	
	third->data=4;
	third->next=fourth;
	
	fourth->data=4;
	fourth->next=fifth;
	
	fifth->data=4;
	fifth->next=last;
	
	last->data=4;
	last->next=NULL;
	
	
	
}
