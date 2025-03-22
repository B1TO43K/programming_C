#include <stdio.h>
#include <math.h>

int main() {

  double sum1 = 0, sum2 = 0;
  int i, j, n, N;

	
printf("Enter n (n * n): ");  	
scanf("%d", &n);
double a[n][n]; 
  N = pow(n, 2); 
  printf("Enter %d chisel:\n", N); 
  for (i = 0; i < n; i++)                     
    for (j = 0; j < n; j++)                    
      scanf("%lf", &a[i][j]);       
	  
	            
printf("Enter n (n * n): ");  	
scanf("%d", &n);
  double b[n][n]; 
  N = pow(n, 2); 
  printf("\nEnter %d chisel:\n", N);
  for (i = 0; i < n; i++) {  
    for (j = 0; j < n; j++) {  
      scanf("%lf", &b[i][j]); 
    }
  }
  return 0;
}
