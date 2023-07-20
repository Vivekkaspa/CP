#include<stdio.h>

void find(int data[],int next[],int start,int x);

void main()
{
	int data[5]={5,13,10,20,8};
	int next[5]={3,4,0,1,-1};
	int start=2;
	find(data,next,start,25);
	find(data,next,start,20);
}

void find(int data[],int next[],int start,int x)
{
	int pos=start;
    for(pos;pos!=-1 && data[pos]!=x;pos=next[pos])
    {
	}
	   
	if(pos<0){
		printf("Data item is not found in the linked list\n");
	}else{
		printf("Data item %d is found at the position %d\n",x,pos);
	}

}





