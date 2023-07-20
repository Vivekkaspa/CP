#include <stdio.h>


void printarray(int V[],int n){
    for(int i= 0 ; i<n ; i++)
       printf("%d ", V[i]);
     printf("\n");
      }

int main()
{
   int V[] ={2,56,78,34,12,203,45};
   int n=sizeof(V)/sizeof(V[0]);
   int temp[30];
   int i,j,k;

	 
  printf("Unsorted list is : ");
  printarray(V,n);
	
  int size,low_1,high_1,low_2,high_2;
  for(size=1; size < n; size=size*2){
      low_1=0;
      k=0; //for temp arr
      
   while(low_1+size < n){
	 high_1=low_1+size-1;
	 low_2=high_1+1;
	 high_2=low_2+size-1;
     //checking base case if h2 exceeds
	if( high_2>=n) 
	   high_2=n-1;//merge with lower limits
	   i=low_1;
	   j=low_2;
	while(i<=high_1 && j<=high_2 ){
	   if( V[i] <= V[j] )
		temp[k++]=V[i++];
	   else
		temp[k++]=V[j++];
	}
			
	while(i<=high_1)
	   temp[k++]=V[i++];
	while(j<=high_2)
	   temp[k++]=V[j++];
	low_1=high_2+1; 
		}

      for(i=low_1; k<n; i++) 
	   temp[k++]=V[i];

      for(i=0;i<n;i++)
	    V[i]=temp[i];

      /*printf("\nSize=%d \nElements are : ",size);
      for( i = 0 ; i<n ; i++)
	 printf("%d ", V[i]);
	*/
	}
	
	printf("Sorted list is :\n");
        printarray(V,n);
	
	return 0;
}

