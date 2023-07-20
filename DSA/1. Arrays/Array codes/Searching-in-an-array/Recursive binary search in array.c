//Recursive binary search in an array

#include<stdio.h>
 
int RBinSearch(int a[],int l,int h,int key)
{
 
 int mid=0;
 if(l<=h)
 {
 mid=(l+h)/2;
 if(key==a[mid])
 return mid;
 else if(key<a[mid])
 return RBinSearch(a,l,mid-1,key);
 }
 else
 return RBinSearch(a,mid+1,h,key);
return -1;
}


int main()
{
 int a[]={2,3,9,16,18,21,28,32,35};
 printf("%d",RBinSearch(a,0,,16));
 return 0;
}
