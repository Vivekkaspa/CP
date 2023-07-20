#include<stdio.h>
#include<stdlib.h>

typedef struct TN{
	int data;
	struct TN* left,*right;
}TNP;


void display(TNP);

void main(){
	int a[15]={7,3,12,1,5,10,15,0,2,4,6,9,11,14,18};
	TNP pa[15];
	TNP root=(TNP) malloc(sizeof(struct TN));
	root->data=a[0];
	root->left=root->right=NULL;
	pa[0]=root;
	//TNP node=root;
	
	for(int i=1;i<7;i++){
		TNP node=pa[i];
		int leftpos=i*2;
		node->left=(TNP) malloc(sizeof(struct TN));
		node->left->data=a[leftpos];
		node->left->left=node->left->right=NULL;
		int rightpos=i*2+1;
		node->right=(TNP) malloc(sizeof(struct TN));
		node->right->data=a[rightpos];
		node->right->left=node->right->right=NULL;
		pa[leftpos]=node->left;
		pa[rightpos]=node->right;
		display(root);
		
		
	}
}

void display(TNP node){
	if(node==NULl){
		printf("NULL\n");
		return;
	}
	display(node->left);
	printf("%d\n",node->data);
	display(node->right);
}

    
