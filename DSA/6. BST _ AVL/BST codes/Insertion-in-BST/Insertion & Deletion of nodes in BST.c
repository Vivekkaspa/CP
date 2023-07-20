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

void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = createNode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }

}


struct node *Predecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* Pre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    else{
        Pre = Predecessor(root);
        root->data = Pre->data;
        root->left = deleteNode(root->left, Pre->data);
    }
    return root;
}
int main(){
     
    
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
   
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 16);
    printf("%d\n", p->right->right->data);
    display(p);
    deleteNode(p, 3);
    printf("/Data is %d/",p->data);
    display(p);
    
    
    return 0;
}

