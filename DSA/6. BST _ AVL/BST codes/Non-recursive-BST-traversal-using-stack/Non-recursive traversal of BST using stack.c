#include<stdio.h>
#include<stdlib.h>
#define bool int

struct treenode
{
int data;
struct treenode* left;
struct treenode* right;
};


struct Stacknode
{
struct treenode *t;
struct Stacknode *next;
};


void push(struct Stacknode** top_ref, struct treenode *t);
struct treenode *pop(struct Stacknode** top_ref);
bool isEmpty(struct Stacknode *top);


void display(struct treenode *root)
{

struct treenode *current = root;
struct Stacknode *s = NULL;
bool done = 0;

while (!done)
{

	if(current != NULL)
	{
	
	push(&s, current);											
	current = current->left;
	}
		
	else															
	{
	if (!isEmpty(s))
	{
		current = pop(&s);
		printf("%d ", current->data);
		current = current->right;
	}
	else
		done = 1;
	}
} 
}	


void push(struct Stacknode** top_ref, struct treenode *t)
{

struct Stacknode* new_treenode =
			(struct Stacknode*) malloc(sizeof(struct Stacknode));

if(new_treenode == NULL)
{
	printf("Stack Overflow \n");
	getchar();
	exit(0);
}			


new_treenode->t = t;
new_treenode->next = (*top_ref);
(*top_ref) = new_treenode;
}

bool isEmpty(struct Stacknode *top)
{
return (top == NULL)? 1 : 0;
}


struct treenode *pop(struct Stacknode** top_ref)
{
struct treenode *res;
struct Stacknode *top;


if(isEmpty(*top_ref))
{
	printf("Stack Underflow \n");
	getchar();
	exit(0);
}
else
{
	top = *top_ref;
	res = top->t;
	*top_ref = top->next;
	free(top);
	return res;
}
}


struct treenode* newtreenode(int data)
{
struct treenode* treenode = (struct treenode*)
					malloc(sizeof(struct treenode));
treenode->data = data;
treenode->left = NULL;
treenode->right = NULL;

return(treenode);
}


int main()
{
struct treenode *root = newtreenode(1);
root->left	 = newtreenode(2);
root->right	 = newtreenode(3);
root->left->left = newtreenode(4);
root->left->right = newtreenode(5);

display(root);


return 0;
}

