#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для удаления всех пробелов из строки
void removeSpaces(char* str) {
    char* i = str; // Указатель для записи (без пробелов)
    char* j = str;// Указатель для чтения (исходная строка)
    while (*j != '\0') { // Пока не конец строки...
        *i = *j++;// Копируем символ из `j` в `i` и двигаем `j` вперёд
        if (*i != ' ') {// Если скопированный символ НЕ пробел...
            i++;// Двигаем `i` вперёд (чтобы сохранить символ)
        }
    }
    *i = '\0';// Завершаем строку 
}

// Функция для вычисления результата операции
double calculate(double operand1, char operator, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        default:
            printf("Error: unknown operator '%c'\n", operator);
            exit(1);
    }
}

int main() {
    char expression[256];
    printf("Enter expression (-123.5 + 4 - 456+56): ");
    fgets(expression, sizeof(expression), stdin);
    
    // Удаляем символ новой строки и все пробелы
    expression[strcspn(expression, "\n")] = '\0';
    removeSpaces(expression);

    double result = 0.0;
    char operator = '+';
    char* ptr = expression;
    
    // Обрабатываем первый операнд отдельно (может быть отрицательным)
    char* end;
    double num = strtod(ptr, &end);
    if (ptr == end) {
        printf("Error: invalid expression\n");
        return 1;
    }
    result = num;
    ptr = end;

    while (*ptr != '\0') {
        // Получаем оператор
        if (*ptr != '+' && *ptr != '-') {
            printf("Error: expected operator, got '%c'\n", *ptr);
            return 1;
        }
        operator = *ptr++;
        
        // Получаем следующий операнд
        num = strtod(ptr, &end);
        if (ptr == end) {
            printf("Error: expected number after operator\n");
            return 1;
        }
        result = calculate(result, operator, num);
        ptr = end;
    }

    printf("Result: %g\n", result);
    return 0;
}
