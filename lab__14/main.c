#include <stdio.h>
#include <setjmp.h>

jmp_buf env; // Буфер для сохранения состояния

// Рекурсивная функция для вычисления суммы чисел Фибоначчи
void fib_sum(int n, int a, int b, int *sum) {
    if (n == 0) {
        longjmp(env, 1); // Выходим из рекурсии
    }
    
    *sum += a;
    fib_sum(n - 1, b, a + b, sum); // Рекурсивный вызов
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to sum: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n  >= 1\n");
        return 1;
    }

    int sum = 0;

    // Устанавливаем точку возврата
    if (setjmp(env) == 0) {
        // Первый вызов (рекурсия начнётся здесь)
        fib_sum(n, 1, 1, &sum);
    } 
	else {
        // Сюда попадём после longjmp
        printf("Sum of first %d Fibonacci numbers: %d\n", n, sum);
    }

    return 0;
}
