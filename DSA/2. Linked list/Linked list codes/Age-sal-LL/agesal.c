#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int age;
    int sal;
    struct node* anode;
    struct node* snode;
}node;

node* head;

void displayage(void);
void displaysal(void);
void insertinage(int,int);
void linkinsalary(node*);
void delete(int,int);
void deleteinsal(node*);

int main(){
    head=(node*)malloc(sizeof(node));
    head->age=NULL; head->sal=NULL; head->anode=NULL;   head->snode=NULL;
    int age,salary;
    int choice;
while(1){
    printf("enter \n1 for insertion\n2 for deletion\n3 for diaplaying as per salary\n4 for displaying as per age\n5 to exit\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("enter the elements age,salary\n");
        scanf("%d %d",&age,&salary);
        insertinage(age,salary);
    }
    else if(choice==2){
        printf("enter the age and salary u wish to delete\n");
        scanf("%d %d",&age,&salary);
        delete(age,salary);
    }
    else if (choice==3)
    {
        displaysal();
    }
    else if (choice==4)
    {
        displayage();
    }
    else if(choice==5){
        break;
    }
    else{printf("enter a valid choice");}   
}
}

void insertinage(int age,int salary){
    node* new=(node*)malloc(sizeof(node));
    new->age=age;   new->sal=salary;    new->anode=NULL;    new->snode=NULL;
    node*ptr;   ptr=head;
    while(ptr->anode){
        if(ptr->anode->age<=new->age){
            ptr=ptr->anode;
        }
        else{
            new->anode=ptr->anode;
            ptr->anode=new;
            linkinsalary(new);
            return;
        }
    }
    ptr->anode=new;
    linkinsalary(new);
}

void displayage(void){
    printf("displaying as per age\n");
    node*ptr=head->anode;
    if(ptr==NULL){  
        printf("empty\n");
        return;}
    while(ptr){
        printf("age %d,salary %d\n",ptr->age,ptr->sal);
        ptr=ptr->anode;
    }
}

void linkinsalary(node*new){
    node*ptr;   ptr=head;
    while(ptr->snode){
        if(ptr->snode->sal<=new->sal){
            ptr=ptr->snode;
        }
        else{
            new->snode=ptr->snode;
            ptr->snode=new;
            return;
        }
    }
    ptr->snode=new;
}
void displaysal(void){
    printf("displaying an per salary\n");
    node*ptr=head->snode;
    if(ptr==NULL){  
        printf("empty\n");
        return;
        }
    while(ptr){
        printf("age %d,salary %d\n",ptr->age,ptr->sal);
        ptr=ptr->snode;
    }
}
void delete(int age,int salary){
    node *ptr,*del;  ptr=head;
    while(ptr->anode){
        if(ptr->anode->age==age){
            if(ptr->anode->sal==salary){
                del=ptr->anode;
                ptr->anode=ptr->anode->anode;
                deleteinsal(del);
                free(del);
                return;
            }
            else{
                ptr=ptr->anode;
            }
        }
        else{ptr=ptr->anode;}
    }
    printf("attribute doesn't exist\n");
}
void deleteinsal(node *del){
    node *ptr=head;
    while(ptr->snode!=del){
        ptr=ptr->snode;
    }
    ptr->snode=ptr->snode->snode;
}
