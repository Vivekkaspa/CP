//Checking if Array is Sorted 

#include<stdio.h>
#include<stdlib.h>

struct Array
{
 int A[10];
 int size;
 int length;
};

 void Display(struct Array arr)
 {
 int i;
 printf("Elements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
 
int isSorted(struct Array arr)
{
 int i;
 for(i=0;i<arr.length-1;i++)
 {
 if(arr.A[i]>arr.A[i+1])
 return 0;
 }
 return 1;
}

int main()
{
 struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 printf("%d\n",isSorted(arr1));
 if(isSorted(arr1)==1){
 	printf("The array is sorted\n");
 }else{
 	printf("The array is unsorted\n");
 }
 Display(arr1);
 return 0;
}
