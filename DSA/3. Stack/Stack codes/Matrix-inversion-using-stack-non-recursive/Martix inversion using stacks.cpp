#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
struct Node{
    float data;
    struct Node * next;
};

struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, float x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node*tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}



float determinent(float matrix[25][25], float size)

{

    int c;
    float det=0,s=1;
    float b[25][25];
    int i,j;
    int m,n;
    if(size == 1){
      return (matrix[0][0]);}
    else{
        det=0;
        for(c=0; c<size; c++){
		    m=0;
            n=0;
            for(i=0; i<size; i++){
                for(j=0; j<size; j++){
                    b[i][j] = 0;
					if(i!=0 && j!=c){
                        b[m][n] = matrix[i][j];
						if(n<(size-2)){
                            n++;
						}else{
                             n=0;
							 m++;
							 }
                    }
                }
            }
            det = det + s*(matrix[0][c]*determinent(b,size-1));
            s = -1*s;
        }
    }
    return det;
}

int main(){
	
    float k;
    printf("Enter the size n*n of the matrix ");
    scanf("%f",&k);
    
    int i,j;
    float matrix[25][25];

    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            printf("Enter the %d%d element of the matrix ",i,j);
            scanf("%f", &matrix[i][j]);
        }
    }
    float result=determinent(matrix,k);
    printf("\nThe determinant of the matrix is %f",result);
    
    
    float cofactor[25][25];
    
    if(result == 0)
        printf("\nMatrix is singular, the inverse of the matrix does not exist\n");
    else
    {
        int c,d,p,q;
        int m,n;
        int size = k;
        float b[25][25];
        for(c=0; c<size; c++)
        {
            for(d=0; d<size; d++)
            {
                m=0;
                n=0;
                for(p=0; p<size; p++)
                {
                    for(q=0; q<size; q++)
                    {
                        if(p!=c && q!=d)
                        {
                            b[m][n] = matrix[p][q];
                            if(n<(size-2))
                            {
                                n++;
                            }
                            else
                            {
                                n=0;
                                m++;
                            }
                        }

                top= push(top,pow(-1,(c+d))*determinent(b,k-1));
                float ram=pop(top);
                cofactor[c][d]=ram;
                printf("Cofactor is %f ",ram);
                printf("\n");
                    }
                }
           }
         }

        float Adjoint[25][25];

        int s,t;
        for(s=0; s<k; s++)
        {
            printf("\n");
            for(t=0; t<k; t++)
            {
                top=push(top,cofactor[t][s]);
                float w=pop(top);
                Adjoint[s][t]=w;
                printf("Adjoint is %f",w);
                printf("\n");
            }
        }
    
        float Inverse[25][25];

        int l,z;
        for(l=0; l<k; l++)
        {
            for(z=0; z<k; z++)
            {
                top =push(top,(Adjoint[l][z]/result));
                float vivu=pop(top);
                printf("Value in Computation of Inverse of the matrix is %f:",vivu);
                printf("\n");
            }
        }
        int e,f;
        printf("The inverse of the matrix is");

        for(e=0; e<k; e++)
        {
            printf("\n");
            for(f=0; f<k; f++)
            {
                top =push(top,(Adjoint[e][f]/result));
                float satya=pop(top);
                Inverse[e][f]=satya;
                printf("%f ",satya);
            }
        }
    }
    printf("\n");
    return 0;
}
