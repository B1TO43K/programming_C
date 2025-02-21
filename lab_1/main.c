#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
 run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a, b, c;
	double x1, x2, d;
	char da[4];
	while(1){
		printf("vvedite a: \n");
		scanf("%lf", &a);
		printf("vvedite b: \n");
		scanf("%lf", &b);
		printf("vvedite c: \n");
		scanf("%lf", &c);
		
		d = pow(b, 2) - 4 * a * c;
		if (d > 0){
			x1 = -b + sqrt(d)/2*a;
			x1 = -b - sqrt(d)/2*a;
			printf("x1 - %lf \n", x1);
			printf("x2 - %lf \n", x2);	
		}
		if (d == 0){
			x1 = -b + sqrt(d)/2*a;
			printf("x1 - %lf \n", x1);
		}
		if (d < 0){
			printf("net korney");
		}
		printf("Vi hotite naiti diskriminant eshe ras? \n");
		printf("Da / Net: \n");
		scanf("%3s", &da);
		if (strcmp(da, "Net") == 0){
			break;
		} else{
			continue;
		}
	return 0;
	}
}
