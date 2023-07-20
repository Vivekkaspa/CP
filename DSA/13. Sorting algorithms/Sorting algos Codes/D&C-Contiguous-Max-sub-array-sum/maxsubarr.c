#include <stdio.h>

int max(int a, int b, int c) { 
  if(a>b && a>c)
     return a;
 else if(b>a && b>c)
     return b;
  else
     return c;     
}
 
int maxcrossingsum(int A[], int left, int mid, int right)
{
 //left of mid
    int sum = 0;
    int l_sum= 0;
    for (int i = mid; i >= left; i--) {
       sum = sum + A[i];
       if (sum > l_sum)
          l_sum = sum;
    }
 
 //right of mid
    sum = 0;
    int r_sum = 0;
    for (int i = mid; i <= right; i++) {
         sum = sum + A[i];
         if (sum > r_sum)
           r_sum = sum;
    }
 return 
    max(l_sum + r_sum - A[mid], l_sum, r_sum);
}
 
int maxsubarraysum(int A[], int left, int right){
     if (left > right)  return 0;
     if (left == right) return A[left];
     int mid = (left + right) / 2;
     
     return max(
        maxsubarraysum(A, left, mid - 1),
        maxsubarraysum(A, mid + 1, right),
        maxcrossingsum(A, left, mid, right));
}
 

int main(){
      int A[] = { 22, 3, 4, 5, 7 };
      int n = sizeof(A)/sizeof(A[0]);
      int max_sum = maxsubarraysum(A, 0, n - 1);
 printf("Maximum sub array sum is %d\n", max_sum);
     return 0;
}
