#include <stdio.h>
#include <stdint.h>

// Функция для подсчёта единичных битов в числе типа long
int count_bits_long(long num) {
    int count = 0;
    // Используем беззнаковое представление для корректного сдвига
    unsigned long unum = (unsigned long)num;
    
    while (unum != 0) {
        count += unum & 1; // Проверяем младший бит
        unum >>= 1;        // Сдвигаем вправо
    }
    return count;
}

// Функция для вывода двоичного представления числа типа long
void print_bits_long(long num) {
    unsigned long unum = (unsigned long)num;
    int size = sizeof(long) * 8;
    int i;
    for (i = size - 1; i >= 0; i--) {
        printf("%d", (unum >> i) & 1);
        if (i % 8 == 0) printf(" "); // Разделяем на байты
    }
}

// Функция для подсчёта единичных битов в числе типа double
int count_bits_double(double num) {
    int count = 0;
    // Интерпретируем биты double как целое число
    uint64_t *ptr = (uint64_t*)&num;
    uint64_t value = *ptr;
    int i;
    for (i = 0; i < 64; i++) {
        count += (value >> i) & 1;
    }
    return count;
}

// Функция для вывода двоичного представления числа типа double
void print_bits_double(double num) {
    uint64_t *ptr = (uint64_t*)&num;
    uint64_t value = *ptr;
    int  i;
    for (i = 63; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 63 || i == 52) printf(" "); // Разделяем знак, экспоненту и мантиссу
    }
}

int main() {
    long lnum;
    double dnum;
    
    printf("Enter chislo tipa long: ");
    scanf("%ld", &lnum);
    
    printf("Enter chislo tipa double: ");
    scanf("%lf", &dnum);
    
    printf("\nDvoichnoe predstavlenie %ld (long): ", lnum);
    print_bits_long(lnum);
    printf("\nKol-vo edinichnih bitov: %d\n", count_bits_long(lnum));
    
    printf("\nDvoichnoe predstavlenie %.2lf (double): ", dnum);
    print_bits_double(dnum);
    printf("\nKol-vo edinichnih bitov: %d\n", count_bits_double(dnum));
    
    return 0;
}
