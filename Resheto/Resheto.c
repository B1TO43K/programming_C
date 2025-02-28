unsigned char nat [10000000]; 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SETBIT(b,k) ((b) |= (1 << (k)))   
#define CLRBIT(b,k) ((b) &= ~(1 << (k)))  
#define TESTBIT(b,k) (((b) >> (k)) & 1)   

#define DEBUG  
#undef DEBUG



int main(int argc, char *argv[]) {
  int i, k;
  long N, Prime;

  printf("enter N:\n"); 
  scanf("%ld", &N);

  for (i = 0; i <= N / 8; i++)
    nat[i] = 0xFF;  

  CLRBIT(nat[0], 0);  
  CLRBIT(nat[0], 1);  
  
  #ifdef DEBUG 
  nat[0]=0;
  nat[0]=CLRBIT(nat[0],4);
  nat[0]=CLRBIT(nat[0],5);
  printf("%x\n", nat[0]);
  
for (i=0; i<8; i++)
  putchar(TESTBIT(nat[0],i)?"1":"0");
  putchar("\n");

  nat[0]=CLRBIT(nat[0],0);
  
  
  #endif

 
  for (Prime = 2; Prime <= sqrt(N); Prime++) { 
    if (TESTBIT(nat[Prime / 8], Prime % 8)) {  
      for (k = Prime * Prime; k <= N; k += Prime) { 
        CLRBIT(nat[k / 8], k % 8);  
      }
    }
  }

  printf("Prostie chisla do N %ld:\n"); 
  for (i = 2; i <= N; i++) {
    if (TESTBIT(nat[i / 8], i % 8)) { 
      printf("%d ", i); 
    }
  }
  printf("\n");

  return 0;
}

