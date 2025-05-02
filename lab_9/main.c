#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для вычисления результата операции
double calculate(double operand1, char operator, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        default:
            printf("oshibka - neizvestniy operator '%c'\n", operator);
            exit(1); // Завершаем программу с кодом ошибки
    }
}

int main() {
    char expression[256]; // Буфер для ввода выражения
    char *token;            // Указатель на токен
    char *rest;             // Указатель для strtok_r 
    double result = 0.0;    // Результат вычисления
    double operand;          // Текущий операнд
    char operator = '+';     // Текущий оператор (по умолчанию "+", для обработки первого числа)
    int first_operand = 1;   // Флаг, показывающий, что это первый операнд

    printf("enter virozgenie (naprimer, -123.5 + 4 - 456+56): ");
    fgets(expression, sizeof(expression), stdin); // Читаем выражение с клавиатуры

    // Удаляем символ новой строки, если он есть
    expression[strcspn(expression, "\n")] = 0;

    // Разбираем строку на токены
    token = strtok_r(expression, " ", &rest); // Разбиваем по пробелам

    while (token != NULL) {
        // Пытаемся преобразовать токен в число
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || token[0] == '.') {
            operand = strtod(token, NULL); // Преобразуем строку в double

            if (first_operand) {
                result = operand;
                first_operand = 0;
            } else {
                result = calculate(result, operator, operand); // Вычисляем результат
            }

        } else if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-')) {
            // Если токен - оператор
            operator = token[0];
        } else {
            printf("oshibka - nevernoe virazgenie.\n");
            return 1;
        }

        token = strtok_r(NULL, " ", &rest); // Получаем следующий токен
    }

    printf("Result: %lf\n", result);

    return 0;
}

