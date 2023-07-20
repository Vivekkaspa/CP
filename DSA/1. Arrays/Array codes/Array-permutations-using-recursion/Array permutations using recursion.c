// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(int *A, int l, int r)
{
int i;
if (l == r)
	printf("%d\n",&A);
else
{
	for (i = l; i <= r; i++)
	{
		swap((&A+l), (&A+i));
		permute(&A, l+1, r);
		swap((&A+l), (&A+i)); //backtrack
	}
}
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {2,4,5,6};
	int n = strlen(str);
	permute(str, 0, n-1);
	return 0;
}

