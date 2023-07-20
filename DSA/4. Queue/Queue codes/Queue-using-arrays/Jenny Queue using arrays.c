#include <stdio.h>
#include <stdlib.h>
void dequeue();
int queue[5];
int front=-1;
int rare=-1;
void enqueue(int x)
{
    if(rare==4)
    {
        printf("Overflow \n");
    }
    else if(front ==-1 &rare == -1)
    {
        front=rare=0;
        queue[rare]=x;
    }
    else
    {
        rare++;
        queue[rare]=x;
    }
}
void dequeue()
{
      if(front ==-1 && rare ==-1)
        {
          printf("Underflow \n");
        }
      else if (front == rare)
         {
            front=rare=-1;
         }
      else
         {
        
          front++;
          }
       
       
        
    
 }
void display()
{
    if(front==rare==-1)
    {
        printf("Queue is empty \n");
        
    }
    else
    {
        for(int i=front;i<rare+1;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    printf("\n");
}
void main()
{
    enqueue(11);
    enqueue(2);
    enqueue(13);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    display();
    
    
}

