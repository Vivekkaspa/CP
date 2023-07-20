#include <stdio.h>
#include <stdlib.h>

// node creation
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insert node at the front
void insertFront(struct Node* head, int data) {
  struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;

  ptr->next = head;
  ptr->prev = NULL;
  
  if (head != NULL)
    head->prev =ptr;
    head= ptr;
}

// insert a node after a specific node
void insertAfter(struct Node* head,struct Node* prev_node, int data) {
  if (prev_node == NULL) {
    printf("previous node cannot be null");
    return;
  }
  
  struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;

  ptr->next = prev_node->next;
  prev_node->next = ptr;
  ptr->prev = prev_node;

  if (ptr->next != NULL)
    ptr->next->prev =ptr;
}

// insert a newNode at the end of the list
void insertEnd(struct Node* head, int data){
  struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node* p= head;
  
  ptr->next = NULL;

  if (head == NULL) {
    ptr->prev = NULL;
    head = ptr;
    return;
  }

  while (p->next != NULL)
    p = p->next;
    p->next = ptr;
    ptr->prev =p;
}

// delete a node from the doubly linked list
void deleteNode(struct Node* head, struct Node* del_node) {
	
  if (head == NULL || del_node == NULL)
    return;

  if (head == del_node)
     head = del_node->next;

  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  free(del_node);
}

// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {

  
  /* Initialize nodes */
struct Node *head=NULL;
struct Node *one = NULL;
struct Node *two = NULL;
struct Node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct Node));
two = malloc(sizeof(struct Node));
three = malloc(sizeof(struct Node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data = 3;

/* Connect nodes */
one->next = two;
one->prev = NULL;

two->next = three;
two->prev = one;

three->next = NULL;
three->prev = two;

/* Save address of first node in head */
head = one;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

  // insert 11 after head
  insertAfter(head,two,11);

  // insert 15 after the seond node
  insertAfter(head,head->next,15);

  displayList(head);

  // delete the last node
  deleteNode(&head, head->next->next->next->next->next);

  displayList(head);
  return 0;
}
