//Permutations of array using recursion

#include<stdio.h>

void swap(int v[],int i,int j){
	int temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

//recursive function to generate permutations
void permutel(int v[],int n,int i){
	int j;
	if(i==n){
		for(j=0;j<n;j++){
			printf("%d",v[j]);
		}
	}else{
		for(j=i;j<n;j++){
			swap(v,i,j);
			permutel(v,n,i+1);
			swap(v,i,j);
		}
	}
}

int main(){
	int v[5],i;
	
	for(i=0;i<5;i++){
		v[i]=i+1;	
	}
	permutel(v,5,0);
	
	return 0;
}

















