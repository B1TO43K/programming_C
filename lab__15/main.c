#include <stdio.h>

// ������� ��� ������ ���� ����� � ������� ������� (� while)
void printDigits(int n) 
{
    // ������� ������: ���� ����� ������ 10, ������ �������� ���
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // ������� ������� 10, ��������������� ������ �����
    int divisor = 1;
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    
    // �������� ����� ����� �������
    while (divisor > 0) {
        printf("%d ", n / divisor);
        n %= divisor;
        divisor /= 10;
    }
}

// ������� ��� ������ ���� ����� � �������� ������� (� while)
void printReverseDigits(int n) 
{
    // ������� ������: ���� ����� ������ 10, ������ �������� ���
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // �������� ��������� �����
    printf("%d ", n % 10);
    
    // ���������� �������� ��� ���������� ����� �����
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

