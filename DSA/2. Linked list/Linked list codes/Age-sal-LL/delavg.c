#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode
{
    struct Tnode* left;
    int data;
    struct Tnode* right;
}Tnode;

Tnode* root;
float average;
int count;

void display (Tnode *ptr){
    if(ptr==NULL){
        return;
    }
    display(ptr->left);
    printf("%d ",ptr->data);
    display(ptr->right);
}
void insert(int x)
{
    Tnode *temp = root;
    Tnode *new = (Tnode *)malloc(sizeof(Tnode));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    if(count==0){
        root=new;
        average=((average*count) + new->data);
        count++;    average=average/count;
        return;
    }
    while (1)
    {
        if (x > temp->data)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new;
                average=((average*count)+new->data);
                count++;    average=average/count;
                break;
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new;
                average=((average*count)+new->data);
                count++;    average=average/count;
                break;
            }
        }
    }
    
}
void delete(int);
int synctoavg(void);

int main()
{
    int ele,choice;
    while (1)
    {
        printf("1.insert\n2.delete\n3.display\n4.nearer to average\n5.exit\n6.check avg and count\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("value?\n");
            scanf("%d",&ele);
            insert(ele);
        }
        else if (choice==2){
            printf("value?\n");
            scanf("%d",&ele);
            delete(ele);
        }
        else if (choice==3){
            printf("displaying tree\n");
            display(root);
            printf("\n");
        }
        else if(choice==4){
            ele=synctoavg();
            printf("the average is %f\n value near to average is %d\n",average,ele);
        }
        else if (choice==5){
            break;
        }
        else if(choice==6){
            printf("the average is %f, count is %d\n",average,count);
        }
        else {
            printf("enter correct option\n");
        }
    }
}

void delete(int x){
    Tnode *del,*bnode,*rsmall;     bnode=NULL;
    del=root;
    while( del!=NULL && ((del->data!=x) || (del->data<x))){
        if(del->data>x){
            bnode=del;
            del=del->left;
        }
        else if(del->data<x){
            bnode=del;
            del=del->right;
        }
        else{
            break;
            }
    }
    if(del==NULL){
        printf("not found\n");  return;
    }
    if(del->data!=x){
        printf("not found\n");  return;
    }
    printf("deleting %d\n",del->data);
    average=((average*count)-x);    count--;
    if(count==0){average=0;}
    else{
    average=(average)/count;}
    if(del->left==NULL && del->right==NULL){
        printf("no child\n");
        if(bnode==NULL){
            free(root);
            root=NULL; return;
        }
        if(bnode->right==del){  bnode->right=NULL; return; }
        bnode->left=NULL;  free(del); return;
    }
    else if(del->left==NULL||del->right==NULL){
        printf("one child\n");
        if(bnode==NULL){
            if(del->right==NULL){
                root=del->left;
                free(del);
                return; 
            }
            root=del->right;    free(del);  return;
        }
        if(bnode->right==del){
            if(del->right==NULL){
                bnode->right=del->left;     free(del);  return;
            }
            bnode->right=del->right;    free(del);  return;
        }
        if(del->right==NULL){
            bnode->left=del->left;     free(del);  return;
        }
        bnode->left=del->right;    free(del);  return;
    }
    else{
        printf("two child\n");
        bnode=NULL;
        rsmall=del->right;
        while (rsmall->left!=NULL)
        {
            bnode=rsmall;
            rsmall=rsmall->left;
        }
        if(bnode==NULL){
            del->data=rsmall->data;
            del->right=rsmall->right;
            free(rsmall);
        }
        else{
            del->data=rsmall->data;
                bnode->left=NULL;
                free(rsmall);
        }
        
    }
}

int synctoavg(void){
    if(root==NULL){
        return -1;
    }
    Tnode *ptr,*bptr;
    ptr=root;
    while(1){
        bptr=ptr;
        if(average>ptr->data){
            if(ptr->right==NULL){
                return ptr->data;
            }
            ptr=ptr->right;
        }
        else{
            if(ptr->left==NULL){
                return ptr->data;
            }
            ptr=ptr->left;
        }
        if((average-bptr->data)>0 && (average-ptr->data)<0){
            if((average-bptr->data)>-(average-ptr->data)){
                return ptr->data;
            }
            else{
                return bptr->data;
            }
        }

    }
}

