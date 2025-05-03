#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SRZN(s, n) ((double)(s) / (n)) 

int main() {
    int n, i, s; 
    char numbers[10];
    printf("vvedite kolichestvo elementov: ");
    scanf("%d", &n);

    printf("vvedite elementi cheres probel: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0]; 
    for (i = 1; i < n; i++) {
        max = MAX(max, numbers[i]); 
    }
	s = 0;
	for(i = 0; i <n; i++){
		s += numbers[i];
	} 
	double srzn;
	srzn = SRZN(s, n);
    printf("Max element: %d\n", max);
    printf("SRZN: %.2lf\n", srzn);


    return 0;
}
