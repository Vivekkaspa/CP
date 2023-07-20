#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 struct node *front,*rare;
void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->data=x;
    if(front==0 && rare==0)
    {
        front=rare=newnode;
    }
    else
    {
        rare->next=newnode;
        rare=newnode;
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0 && rare==0)
    {
        printf("Queue is empty \n");
    }
    else
    {
       front=front->next;
       free(temp);
       
    }
}
void display()
{
    struct node *temp;
    temp=front;
    if(front==0 &&rare==0)
    {
        printf("Queue is empty \n");
    }
    else
     {
        while(temp!=0)
        {
            printf("%d \t",temp->data);
            temp=temp->next;
        }
     } 
     printf("\n");
}
void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
}
    
