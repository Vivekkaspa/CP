#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node* next;
} Node;

struct Node* newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(struct Node* head)
{
	while (head != NULL) {
		printf("%d ", head->key);
		head = head->next;
	}
	printf("\n");
}

void detectAndRemoveLoop(Node* head)
{
	if (head == NULL || head->next == NULL)
		return;

	struct Node *p1 = head, *p2 = head;
	
	p1 = p1->next;
	p2 = p2->next->next;

	while (p2 && p2->next) {
		if (p1 == fast)
			break;
		p1 = p1->next;
		fast = fast->next->next;
}

	if (p1 == fast) {
		p1 = head;

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
	Node* head = newNode(50);
	head->next = head;
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = head;

	detectAndRemoveLoop(head);

	printf("Linked List after removing loop \n");
	printList(head);

	return 0;
}


