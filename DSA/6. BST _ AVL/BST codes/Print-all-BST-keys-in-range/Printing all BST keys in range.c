#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

void Print(struct node *root, int k1, int k2)
{
if ( NULL == root )
	return;

if ( k1 < root->data )
	//Print(root->left, k1, k2);

if ( k1 <= root->data && k2 >= root->data )
	printf("%d ", root->data );

//Print(root->right, k1, k2);
}

struct node* newNode(int data)
{
struct node *temp = malloc(sizeof(struct node));
temp->data = data;
temp->left = NULL;
temp->right = NULL;

return temp;
}

int main()
{
struct node *root = malloc(sizeof(struct node));
int k1 = 10, k2 = 25;

root = newNode(20);
root->left = newNode(8);
root->right = newNode(22);
root->left->left = newNode(4);
root->left->right = newNode(12);

Print(root, k1, k2);
return 0;
}


