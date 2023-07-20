#include <stdio.h>

void insertionSort(int a[],int n)
{
	int i=0,j=0;
	for(i=1;i<n;i++){
		int k=a[i];
		j=i-1;
		while(j>=0 & k<a[j]){
			a[j+1]=a[j];
			j=j-1;
		}	
	    a[j+1]=k;
	}
}

void printArr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("%d ,",a[i]);
	}
}

int main()
{
	int a[]={12,31,34,8,25,17};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Before sorting,array elements are :\n");
	printArr(a,n);
	insertionSort(a,n);
	printf("\nAfter sorting ,array elements are :\n");
	printArr(a,n);
	
	return 0;
}

