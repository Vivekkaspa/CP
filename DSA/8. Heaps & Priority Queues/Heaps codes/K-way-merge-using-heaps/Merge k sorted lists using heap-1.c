// C++ program to merge k sorted arrays of size n each
#include <stdio.h>
#include<stdlib.h>

// A Linked List node
struct Node {
	int data;
	struct Node* next;
};

/* Function to print nodes in a given linked list */
void display(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Function to merge K sorted linked list.
struct	Node* mergeKLists(struct Node* arr[], int K){
	struct	Node* head = NULL;
		while (1) {
			int a = 0;
			int z;
			struct Node* curr;
			int min = INT_MAX;
			for (int i = 0; i < K; i++) {
				if (arr[i] != NULL) {
					a++;
					if (arr[i]->data < min) {
						min = arr[i]->data;
						z = i;
					}
				}
			}
			if (a != 0) {
				arr[z] = arr[z]->next;
				struct Node* temp = newNode(min);
				if (head == NULL) {
					head = temp;
					curr = temp;
				}
				else {
					curr->next = temp;
					curr = temp;
				}
			}
			else {
				return head;
			}
		}
	}

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
	int k = 3; // Number of linked lists
	int n = 4; // Number of elements in each list

	// an array of pointers storing the head nodes
	// of the linked lists
	struct Node* arr[k];

	arr[0] = newNode(1);
	arr[0]->next = newNode(3);
	arr[0]->next->next = newNode(5);
	arr[0]->next->next->next = newNode(7);

	arr[1] = newNode(2);
	arr[1]->next = newNode(4);
	arr[1]->next->next = newNode(6);
	arr[1]->next->next->next = newNode(8);

	arr[2] = newNode(0);
	arr[2]->next = newNode(9);
	arr[2]->next->next = newNode(10);
	arr[2]->next->next->next = newNode(11);
	
	struct Node* head = mergeKLists(arr, k);

	display(head);
	return 0;
}


