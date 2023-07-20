#include<stdlib.h>
#include<stdio.h>
void heapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0) 
    {
        
        if (arr[i] > arr[parent]) {
            int temp=arr[parent];
            arr[parent]=arr[i];
            arr[i]=temp;
            heapify(arr, n, parent);
        }
    }
}
void insertNode(int arr[], int n, int Key)
 {
    n = n + 1;
    arr[n - 1] = Key;
    heapify(arr, n, n - 1);
 }
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\t",arr[i]);
}
int main()
{
    int arr[] = { 10, 5, 3, 2, 4 };
    int n =5;
    int n1=6;
    int key = 15;
    insertNode(arr, n, key);
    //insertNode(arr,n,20);
    printArray(arr, n1);
    return 0;
}
