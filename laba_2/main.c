#include <stdio.h>
#include <stdlib.h>

/*������� 2
	�������� ������ ������ ���� double �������� 3 �� 3.
	������ � ������� ��� ��������, 
	������� �� ������� ����� ��� ���������, ������������� �� ������� �����-���� � ����� ���������, ������������� �� �������� ���������.
	�������� ������ ������ ���� int �������� 2 �� 2. ������ � ������� ��� �����-���, ������� �� ������� ������� ������ �������.

 run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double mat[3][3], sumG, sumP;
	int i, j, p, matr[2][2];
	printf("Vvedite 1i element matrici\n");
	scanf("%lf", &mat[0][0]);
	
	printf("Vvedite 2i element matrici\n");
	scanf("%lf", &mat[0][1]);
	
	printf("Vvedite 3i element matrici\n");
	scanf("%lf", &mat[0][2]);
	
	printf("Vvedite 4i element matrici\n");
	scanf("%lf", &mat[1][0]);
	
	printf("Vvedite 5i element matrici\n");
	scanf("%lf", &mat[1][1]);
	
	printf("Vvedite 6i element matrici\n");
	scanf("%lf", &mat[1][2]);
	
	printf("Vvedite 7i element matrici\n");
	scanf("%lf", &mat[2][0]);
	
	printf("Vvedite 8i element matrici\n");
	scanf("%lf", &mat[2][1]);
	
	printf("Vvedite 9i element matrici\n");
	scanf("%lf", &mat[2][2]);

	printf("Vasha matrica imeet sleduihii vid:\n");
    for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
            printf("%.2lf ", mat[i][j]);
        }
    printf("\n");
    }


	sumG = mat[0][0] + mat[1][1] + mat[2][2];
	printf("\nSumma glavnoi diagonali = %.2lf", sumG);
	
	sumP = mat[0][2] + mat[1][1] + mat[2][0];
	printf("\nSumma pobochnoi diagonali = %.2lf", sumP);
	

	printf("\nVvedite element[0][0] matrici\n");
	scanf("%d", &matr[0][0]);
	printf("Vvedite  element[0][1] matrici\n");
	scanf("%d", &matr[0][1]);
	printf("Vvedite  element[1][0] matrici\n");
	scanf("%d", &matr[1][0]);
	printf("Vvedite  element[1][1] matrici\n");
	scanf("%d", &matr[1][1]);
	
	printf("Kvadrat vashei matrici imeet sleduihii vid:\n");
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			p = matr[i][j] * matr[i][j];
			printf("%d ", p);
        }
    	printf("\n");
    }
	return 0;
}
