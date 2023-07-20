#include<stdio.h>
#include<stdlib.h>

struct MinHeap {

	int size;
	int* arr;
};

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int arr[], int N, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int N)
{
	// Index of last non-leaf node
	int startIdx = (N / 2) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}

void FirstKelements(int arr[],int size,int k){
	// Creating Min Heap for given
	// array with only k elements
	struct MinHeap* m = new MinHeap(k, arr);

	// Loop For each element in array
	// after the kth element
	for (int i = k; i < size; i++) {

		// if current element is smaller
		// than minimum element, do nothing
		// and continue to next element
		if (arr[0] > arr[i])
			continue;

		// Otherwise Change minimum element to
		// current element, and call heapify to
		// restore the heap property
		else {
			arr[0] = arr[i];
			m->heapify(0);
		}
	}
	// Now min heap contains k maximum
	// elements, Iterate and print
	for (int i = 0; i < k; i++) {
	     printf("%d",arr[i] );
	}
}
// Driver Program
int main()
{

	int arr[] = { 11, 3, 2, 1, 15, 5, 4,
						45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	// Size of Min Heap
	int k = 3;

	FirstKelements(arr,size,k);

	return 0;
}
// This code is contributed by Ankur Goel

