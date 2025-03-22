#include <stdio.h>
#include <math.h>

int main() {

  double sum1 = 0, sum2 = 0;
  int i, j, n, N, k;

	
printf("Enter n (n * n): ");  	
scanf("%d", &n);
double a[n][n]; 
  N = pow(n, 2); 
  printf("Enter %d numbers for the array int:\n", N); 
  for (i = 0; i < n; i++)                     
    for (j = 0; j < n; j++)                    
      scanf("%lf", &a[i][j]);                 

  for (i = 0; i < n; i++) {               
    sum1 += a[i][i];                           
    sum2 += a[i][(n-1) - i];                          
  }

  printf("The sum of the main diagonal: %.2lf\n", sum1);   
  printf("The sum of the side diagonal: %.2lf\n", sum2);      
  printf("Enter n (n * n): ");
  scanf("%d", &n); 

  int b[n][n], c[n][n]; 
  N = pow(n, 2); 

  printf("\nEnter %d chisel:\n", N);
  for (i = 0; i < n; i++) {  
    for (j = 0; j < n; j++) {  
      scanf("%d", &b[i][j]); 
    }
  }

  
  for (i = 0; i < n; i++) { 
    for (j = 0; j < n; j++) { 
      c[i][j] = 0; 
      for (k = 0; k < n; k++) {
        c[i][j] += b[i][k] * b[k][j];
      }
    }
  }

  printf("\n:\n");
  for (i = 0; i < n; i++) { 
    for (j = 0; j < n; j++) { 
      printf("%d ", c[i][j]); 
    }
    printf("\n"); 
  }

  return 0;
}
