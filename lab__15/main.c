#include <stdio.h>

// Функция для вывода цифр числа в обычном порядке (с while)
void printDigits(int n) 
{
    // Базовый случай: если число меньше 10, просто печатаем его
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // Находим степень 10, соответствующую первой цифре
    int divisor = 1;
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    
    // Печатаем цифры слева направо
    while (divisor > 0) {
        printf("%d ", n / divisor);
        n %= divisor;
        divisor /= 10;
    }
}

// Функция для вывода цифр числа в обратном порядке (с while)
void printReverseDigits(int n) 
{
    // Базовый случай: если число меньше 10, просто печатаем его
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // Печатаем последнюю цифру
    printf("%d ", n % 10);
    
    // Рекурсивно вызываем для оставшейся части числа
    printReverseDigits(n / 10);
}

int main() {
    int N;
    printf("Enter number: ");
    scanf("%d", &N);
    
    printf("The number %d in the usual order: ", N);
    printDigits(N);
    printf("\n");
    
    printf("The number %d in reverse order: ", N);
    printReverseDigits(N);
    printf("\n");
    
    return 0;
}

