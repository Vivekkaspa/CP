#include<stdio.h>

void insert(int data[],int next[],int start,int x,int len);
void display(int data[],int next[],int start);


void main()
{
	int data[6]={5,13,10,20,8};
	int next[6]={3,4,0,1,-1,-1};
	int start=2;
	insert(data,next,start,25,6);
	display(data,next,start);
	insert(data,next,start,100,6);
}

void display(int data[],int next[],int start)
{
	for(int pos=start;pos!=-1;pos=next[pos]){
		printf("%d-->",data[pos]);
	}
	printf("NULL\n");
}

void insert(int data[],int next[],int start,int x,int len)
{
	int pos=start;
	int count=0;
	int last_pos=0;
	
	for(pos;pos!=-1;pos=next[pos]){
		count++;
		last_pos=pos;
	}
		
		
	int available=0;	
	for(available;available<len;available++){
		if((next[available]==-1)&& (available!=last_pos))
		{
			break;
		}
	}
	
    if(available==len){
	    printf("Array hosting the linkedlist is full\n");
	}else{
	    next[last_pos]=available;
		data[available]=x;
	   }
}




