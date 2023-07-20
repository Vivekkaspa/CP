//Insertion sort using binary search

#include<stdio.h>

int binarysearch(int a[],int k,int low,int high){
	while(low<=high){
		int mid=low+(high-low)/2;
		if (k==a[mid])
		   return mid+1;
	    else if(k>a[mid])
	       low=mid+1;
	    else
	       high=mid-1;
	   }
	    return low;
	}
	
void insertionsort(int a[],int n){
	int i,bin,j,k,v;
	for(i=1;i<n;i++){
		j=i-1;
		v=a[i];
		bin=binarysearch(a,v,0,j);
		
		while(j>=bin){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
}

int main()
{
	int a[]={37,23,0,17,12,72,31,46,100,88,54};
	int n=sizeof(a)/sizeof(a[0]);
	insertionsort(a,n);
	printf("sorted array:\n");
	for(int i=0;i<n;i++){
		printf("%d,",a[i]);
	}
return 0;
	}


