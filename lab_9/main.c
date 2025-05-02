#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ������� ��� ���������� ���������� ��������
double calculate(double operand1, char operator, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        default:
            printf("oshibka - neizvestniy operator '%c'\n", operator);
            exit(1); // ��������� ��������� � ����� ������
    }
}

int main() {
    char expression[256]; // ����� ��� ����� ���������
    char *token;            // ��������� �� �����
    char *rest;             // ��������� ��� strtok_r 
    double result = 0.0;    // ��������� ����������
    double operand;          // ������� �������
    char operator = '+';     // ������� �������� (�� ��������� "+", ��� ��������� ������� �����)
    int first_operand = 1;   // ����, ������������, ��� ��� ������ �������

    printf("enter virozgenie (naprimer, -123.5 + 4 - 456+56): ");
    fgets(expression, sizeof(expression), stdin); // ������ ��������� � ����������

    // ������� ������ ����� ������, ���� �� ����
    expression[strcspn(expression, "\n")] = 0;

    // ��������� ������ �� ������
    token = strtok_r(expression, " ", &rest); // ��������� �� ��������

    while (token != NULL) {
        // �������� ������������� ����� � �����
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || token[0] == '.') {
            operand = strtod(token, NULL); // ����������� ������ � double

            if (first_operand) {
                result = operand;
                first_operand = 0;
            } else {
                result = calculate(result, operator, operand); // ��������� ���������
            }

        } else if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-')) {
            // ���� ����� - ��������
            operator = token[0];
        } else {
            printf("oshibka - nevernoe virazgenie.\n");
            return 1;
        }

        token = strtok_r(NULL, " ", &rest); // �������� ��������� �����
    }

    printf("Result: %lf\n", result);

    return 0;
}

