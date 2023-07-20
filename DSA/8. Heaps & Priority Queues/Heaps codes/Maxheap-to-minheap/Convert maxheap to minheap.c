#include <stdio.h>

void minheapify(int arr[], int i, int N)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int min = i;

	if (l < N && arr[l] < arr[i])
		min = l;
	if (r < N && arr[r] < arr[min])
		min = r;
	if (min != i) {
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		minheapify(arr, min, N);
	}
}

void convertminheap(int arr[], int N)
{
	for (int i = (N - 2) / 2; i >= 0; --i)
		minheapify(arr, i, N);
}

void displayarray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

int main()
{
	// array representing Min Heap
	int arr[] = { 20,18,10,12,9,9,3,5,6,8 };
	int N = sizeof(arr) / sizeof(arr[0]);

	printf("Max Heap array : ");
	displayarray(arr, N);
	
	convertminheap(arr,N);
     
	printf("\nMin Heap array : ");
	displayarray(arr, N);

	return 0;
}

