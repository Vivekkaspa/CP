#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node)); 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
}


void display(struct  node* root){
    if(root!=NULL){
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main(){
     

    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    
    display(p);
    
    return 0;
}

