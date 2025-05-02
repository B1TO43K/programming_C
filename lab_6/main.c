#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
FILE *f1, *f2;
int i, k, t, j, otv = 0;
char g[80];
int main(int argc, char *argv[]) {
	f1 = fopen("vvod.txt", "rt");
	f2 = fopen("otv.txt", "wt");
	for (j=0; j<9; j++){
		fgets(g, 79, f1);
		otv = 0;
		k = 0;
		for (i = strlen(g) - 2; i > strlen(g)-6; i--){
			otv = otv + ((int)(g[i] - '0') * (pow(10, k)));
			k++;
			
		}
		if (otv > 1980) fprintf(f2, g);

	}
	fgets(g, 79, f1);
	
	k = 0;
	otv = 0;
	for (i = strlen(g) - 1; i > strlen(g)-5; i--){
			otv = otv + ((int)(g[i] - '0') * (pow(10, k)));
			k++;
			
		}
	if (otv > 1980) fprintf(f2, g);
	
	
	
	
	return 0;
}
