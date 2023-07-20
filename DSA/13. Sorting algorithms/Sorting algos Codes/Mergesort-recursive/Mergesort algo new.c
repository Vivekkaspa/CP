//Merge sort algo

#include<stdio.h>


void Merge(int A[],int mid,int low,int high){
	int i,j,k,B[100];
	i=low;
	j=mid+1;
	k=low;
	//size=high-low+1;
	while(i<=mid && j<=high){
	  if(A[i]<=A[j]){
		  B[k]=A[i];
		  i=i+1;
		  k=k+1;
		  }
	  else{
	      B[k]=A[j];
	      j=j+1;
		  k=k+1;
		  }	   
	}
	
	while(i<=mid){
		 B[k]=A[i];
		  k=k+1;
		  i=i+1;
	}
	
	while(j<=high){
		  B[k]=A[j];
		  k=k+1;
		  j=j+1;
	}
	for(int i=low;i<=high,i++;){
		A[i]=B[i];
	}
}

void Mergesort(int A[],int low,int high){
	int mid;
	if(high>low){
	mid=(low+high)/2;
	Mergesort(A,low,mid);
	Mergesort(A,mid+1,high);
	Merge(A,mid,low,high);
  }
}


void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    Mergesort(A,0,6);
    printArray(A, n);
    return 0;
}
