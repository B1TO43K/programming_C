#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int sum, raz, proi, del, ost_del;
	int a, b;
	printf("Vvedite a \n");
	scanf("%d", &a);
	printf("Vvedite b \n");
	scanf("%d", &b);
	
	sum = a + b;
	
	printf("a + b = %d\n",sum);
	
	raz = a - b;
	
	printf("a - b = %d\n",raz);
	
	proi = a * b;
	
	printf("a * b = %d\n",proi);
	
	ost_del = a % b;
	
	printf("a // b = %d ",ost_del);
	return 0;
}
