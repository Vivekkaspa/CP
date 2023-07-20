#include <stdio.h>
#include<stdlib.h>
int s1[5],s2[5];
int top1=-1,top2=-1;
int count=0;
void push1(int data)
 {
      if(top1 == 4)
       {
     	printf("Overflow \n");
       }
    else
      {
    
         top1++;
         s1[top1]=data;
      }
}  

void enqueue(int x)
 {
    push1(x);
    count++;
 }
 int pop1()
 {
    return s1[top1--];
 }
int pop2()
 {
    return s2[top2--];
 }
void push2(int data)
  {
      if(top2 == 4)
       {
     	printf("Overflow \n");
       }
    else
      {
        top2++;
 		s2[top2]=data;
      }
 }
void dequeue()
 {
    if(top1==-1)
    {
        printf("Queue is empty \n");
    }
    else
    {
       for(int i=0;i<count;i++)
       {
           int a=pop1();
           push2(a);
       }
       int b=pop2();
       printf("The deleted element is:%d \n",b);
       count--;
       for(int i=0;i<count;i++)
       {
           int a=pop2();
           push1(a);
           
       }
    }
    
}
void display()
{
  for(int i=0;i<top1;i++)
  {
      printf("%d \t",s1[i]);
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
    //dequeue();
   // display();
}    



