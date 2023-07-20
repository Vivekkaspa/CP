#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};

void linkedlisttraversal(struct Node* ptr)
{
	printf("\nList elements are :\n");
	while(ptr!=NULL){
		printf("%d--->",ptr->data);
		ptr=ptr->next;
	}
}

struct Node* insertAtFirst(struct Node* head,int data)
{
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=head;
	return ptr;
}

struct Node* insertAtIndex(struct Node* head,int data,int index)
{
	struct Node* ptr =(struct Node*)malloc(sizeof(struct Node));
	struct Node* p = head;
	
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	ptr->data=ptr;
	ptr->next=p->next;
	p->next=ptr;
	return head;
}

struct Node* insertAfterNode(struct Node* head,struct Node* prevnode,int data)
{
	struct Node* ptr =(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=prevnode->next;
	prevnode->next=ptr;
	return head;
}

struct Node* insertAtEnd(struct Node*head,int data)
{
	struct Node* ptr =(struct Node*)malloc(sizeof(struct Node));
	struct Node* p =head;
	ptr->data=data;
	
	while(p->next!=NULL){
		p=p->next;
	}
	
	p->next=ptr;
	ptr->next=NULL;
	return head;
}

int main()
{
	struct Node* head;
	struct Node* second;
	struct Node* third;
	struct Node* fourth;
	
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	fourth=(struct Node*)malloc(sizeof(struct Node));
	
	head->data=21;
	head->next=second;
	
	second->data=65;
	second->next=third;
	
	third->data=53;
	third->next=fourth;
	
	fourth->data=77;
	fourth->next=NULL;
	
	printf("Linked list b4 insertion\n");
	linkedlisttraversal(head);
	printf("\nLinked list after insertion after a node\n");
	insertAfterNode(head,third,87);
	linkedlisttraversal(head);
	
	return 0;
}
