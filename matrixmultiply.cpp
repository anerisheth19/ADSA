//Matrix Chain Multiplication code - Dynamic Programming
#include<stdlib.h>
#include<stdio.h>
 
#define MAX_INT 100000

int matrixMultiply(int p[], int N){
 
  int L,i, j, a;
 
  int M[N][N];
 
  for(i=0; i<N; i++){
  	for(j=0; j<N; j++){
       M[i][j] = 0;
  	}
  }       
 
  for(L=2; L<N; L++){

    for(i=1; i<N-L+1; i++){
 
        j = i+L-1;
        M[i][j] = MAX_INT;
        
            for(int k=i; k<j; k++){
                a = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
               
                if(a < M[i][j]){
                    M[i][j] = a;                 
                }
            }
        }
    }
    for(i=1; i<N; i++){
    	for(int k=1; k<N; k++){
    		printf("%d ", M[i][k]);
    	}
    	printf("\n");
    }
 
 return M[1][N-1];
}
int main(){
 
    int p [] ={10, 20, 30, 40, 30};
    int n = sizeof(p)/sizeof(p[0]);
 
    printf("%d\n", matrixMultiply(p,n));
 
    return 0;
}
