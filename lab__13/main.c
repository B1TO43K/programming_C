#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void signal_processing(int signal) {
    switch(signal) {
        case SIGABRT:   
			printf("Received SIGABRT signal\n");  
			break;  //Аварийное завершение
        case SIGFPE:   
			printf("Received SIGFPE signal\n");    
			break;  //Ошибка арифметической операции (деление на ноль)
        case SIGILL:   
			printf("Received SIGILL signal\n");   
			break;  //Недопустимая инструкция
        case SIGINT:   
			printf("Received SIGINT signal\n");   
			break;  //Прерывание с клавиатуры (Ctrl+C)
        case SIGSEGV:   
			printf("Received SIGSEGV signal\n");   
			break;  //Нарушение сегментации (ошибка доступа к памяти)
        case SIGTERM:   
			printf("Received SIGTERM signal\n");   
			break;  //Запрос на завершение программы
        default:     
			printf("Received unknown signal\n");   
			break;
    }
}
int main() {
    signal(SIGABRT, signal_processing);
    signal(SIGFPE, signal_processing);
    signal(SIGILL, signal_processing);
    signal(SIGINT, signal_processing);
    signal(SIGSEGV, signal_processing);
    signal(SIGTERM, signal_processing);
    int input;
    printf("Enter 1 to get SIGABRT signal, 2 for SIGFPE, 3 for SIGILL, 4 for SIGINT, 5 for SIGSEGV, or 6 for SIGTERM: ");
    scanf("%d", &input);
    switch(input) {
        case 1: 
			raise(SIGABRT);          
			break;
        case 2:
			raise(SIGFPE);           
			break;
        case 3: 
			raise(SIGILL);           
			break;
        case 4: 
			raise(SIGINT);           
			break;
        case 5: 
			raise(SIGSEGV);         
			break;
        case 6: 
			raise(SIGTERM);         
			break;
        default: 
			printf("Invalid input.\n");   
			break;
    }
    return 0;
}

