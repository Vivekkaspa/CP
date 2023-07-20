#include<stdio.h>

void display(int data[],int next[],int start);


void main()
{
	int data[5]={5,13,10,20,8};
	int next[5]={2,-1,3,1,0};
	int start=4;
	display(data,next,start);
}

void display(int data[],int next[],int start)
{
	for(int pos=start;pos!=-1;pos=next[pos]){
		printf("%d-->",data[pos]);
	}
	printf("NULL\n");
}


