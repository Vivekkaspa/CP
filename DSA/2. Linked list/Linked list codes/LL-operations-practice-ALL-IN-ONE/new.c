#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void linkedlisttraversal(struct node* ptr){
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

struct node* insertatfirst(struct node* header,int data){
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=header;
	return header;
}

struct node* insertinbetween(struct node* header,int data,int index){
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	struct node* p=header;
	int i=0;
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return header;
}

struct node* insertatend(struct node* header,int data){
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	struct node* p=header;
	ptr->data=data;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=ptr->next;
	ptr->next=NULL;
	return header;
	
}

struct node* insertafternode(struct node* header,struct node* prevnode,int data){
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=prevnode->next;
	prevnode->next=ptr;
	return header;
}

struct node* deleteatbeginning(struct node* header){
	struct node* ptr=header;
	header=header->next;
	free(ptr);
	return header;
}

struct node* deleteatindex(struct node* header,int index){
	struct node* p=header;
	struct node* q=header->next;
	for(int i=0;i<index-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return header;
}

struct node* deleteatlast(struct node* header){
	struct node* p=header;
	struct node* q=header->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return header;
}

struct node* deleteatvalue(struct node* header,int value){
	struct node* p=header;
	struct node* q=header->next;
	while(q->data!= value && q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	if(q->data==value){
		p->next=q->next;
		free(q);
	}return header;
}

void max(struct node* p){
	int max=7;
	while(p){
	if(p->data>max){
		max=p->data;
		p=p->next;
		}return max;
		}
		
}


void main(){
	int data[6]={10,5,20,13,8,25};
	struct node* header=(struct node*)malloc(sizeof(struct node));
	header->next=NULL;
	struct node*p=header;
	for(int i=0;i<6;i++){
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=data[i];
		newnode->next=NULL;
		p->next=newnode;
		p=p->next;
	}
	linkedlisttraversal(header);
}
