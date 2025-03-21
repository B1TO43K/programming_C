#include <stdio.h>
#include <stdbool.h>
#include "myLib.h"
/* 1.Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. 
2. Разместить их в отдельном модуле (отличном от того, где распо-лагается функция main( )).
3. Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника)
4. выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади. */

int main()
{
    double s1;
	double s2;
	double s3;
	
    printf("Enter the first side: ");
    scanf("%lf", &s1);
    
    printf("Enter the second side: ");
    scanf("%lf", &s2);
    
    printf("Enter a third party: ");
    scanf("%lf", &s3);
    
    if (valid(s1,s2,s3))
	{
        printf("Perimeter: %lf\nArea: %lf", perimeter(s1, s2, s3), area(s1, s2, s3));
    } 
	else 
        printf("Mistake");
    return 0;
}
