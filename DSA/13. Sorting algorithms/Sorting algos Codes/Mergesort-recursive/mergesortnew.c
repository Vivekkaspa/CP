#include<stdio.h>

void merge(int A[],int left, int mid_1,int mid_2,int right);

void merge_sort(int A[], int left, int right)
{
    if (left < right) {
        
        int mid_1 = left + (mid_1 - left) / 2;
        int mid_2 = mid_1 +(right -mid_1) / 2;
        
        merge_sort(A, left, mid_1);
        merge_sort(A, mid_1+1, mid_2);
        merge_sort(A,mid_2+1,right);
        merge(A, left, mid_1,mid_2,right);
    }
}

void merge(int A[],int left, int mid_1,int mid_2,int right)
{
    int i, j,p,k;
    int s1 = mid_1 - left + 1;
    int s2 = mid_2 - mid_1 +1;
    int s3 = right - mid_2;
 
    int arr_1[s1],arr_2[s2],arr_3[s3];
 

    for (i = 0; i < s1; i++)
        arr_1[i] = A[left + i];
    
    for (j = 0; j < s2; j++)
        arr_2[j] = A[mid_1+1+j];
     
    for (j = 0; j < s2; j++)
        arr_3[p] = A[mid_2+1+p];
     
    i =0, j =0;p=0;
    k = left; 
    while (i < s1 && j < s2 && k < s3) {
        if (arr_1[i] <= arr_2[j]) {
            A[k] = arr_1[i];
            i++;
        }
        else if (arr_2[j] <= arr_3[p]){
            A[k] = arr_2[j];
            j++;
        }
        else{
            A[k] = arr_3[p];
            p++;
            }
        k++;
    }
 
 
    while (i < s1) {
        A[k] = arr_1[i];
        i++;
        k++;
    }
 
  
    while (j < s2) {
        A[k] = arr_2[j];
        j++;
        k++;
    }
    
    
    while (p < s3) {
        A[k] = arr_3[p];
        p++;
        k++;
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {90, 66, 67, 32, 12,9};
    int n=sizeof(A)/sizeof(A[0]);
    printArray(A,n);
    merge_sort(A,0,5);
    printArray(A,n);
}

