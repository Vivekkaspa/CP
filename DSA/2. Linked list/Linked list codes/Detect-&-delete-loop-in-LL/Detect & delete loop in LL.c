#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* node(int data)
{
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void traversal(struct Node* head)
{
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void iscycleremove(struct Node* head)
{
	if (head == NULL || head->next == NULL)
		return;

	struct Node * p1 = head, * p2 = head;
	p1 = p1->next;
	p2 = p2->next->next;
	while (p2 && p2->next) {
		if (p1== p2)
			break;
		p1 = p1->next;
		p2 = p2->next->next;
	}

	
	if (p1== p2) {
		p1= head;
		printf("Cycle exists\n");

		if (p1 == p2)
			while (p2->next != p1)
				p2 = p2->next;
		else {
			while (p1->next != p2->next) {
				p1 = p1->next;
				p2 = p2->next;
			}
		}

		p2->next = NULL; 
	}
}


int main()
{
	struct Node* head = node(50);
	head->next = head;
	head->next = node(20);
	head->next->next = node(15);
	head->next->next->next = node(4);
	head->next->next->next->next = node(10);
	
	head->next->next->next->next->next = head;

	iscycleremove(head);

	printf("Linked List after removing loop \n");
	traversal(head);

	return 0;
}


