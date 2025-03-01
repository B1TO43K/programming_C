#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон.
   Разместить их в отдельном модуле (отличном от того, где распо-лагается функция main( )).
   Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычислен-ные с помощью написанных функций значения его периметра и площади.
  run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	float a, b, c, p, P, S;
	printf("Vvedite pervuy storony:\n");
	scanf("%f", &a);
	printf("Vvedite vtoryy storony:\n");
	scanf("%f", &b);
	printf("Vvedite tretiy storony:\n");
	scanf("%f", &c);
	P = a + b + c;
	p = P/2;
	S = sqrt(p) * (p - a) * (p - b) * (p - c);
/*	printf("%.2f\n", a);
	printf("%.2f\n",b);
	printf("%.2f\n",c);
	printf("%.2f\n",p);
	printf("%.2f\n",P);
	printf("%.2f\n", S); */
	
	return 0;
}
