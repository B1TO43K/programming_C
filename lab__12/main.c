#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Функция для проверки високосного года
bool is_leap_year(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

// Функция для определения дня недели (0-воскресенье, 1-понедельник и т.д.)
int day_of_week(int year, int month, int day) {
    // Алгоритм Зеллера
    if (month < 3) {
        month += 12;
        year--;
    }
    int q = day;
    int m = month;
    int K = year % 100; // год века 
    int J = year / 100; // номер века
    int h = (q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;
    return (h + 5) % 7; // корректировка для соответствия 
}

// Функция для получения количества дней в месяце
int days_in_month(int year, int month) {
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

// Функция для вывода календаря на месяц
void print_month_calendar(int year, int month) {
	int i, day;
    const char *month_names[] = {"Yanvar", "Fevral", "Mart", "Aprel", "May", "Iyun", "Iyul", "Avgust", "Sentyabr", "Oktyabr", "Noyabr", "Dekabr"};
    const char *day_names[] = {"Pn", "Vt", "Sr", "Cht", "Pt", "Sb", "Vs"};
    
    printf("\n     %s %d\n", month_names[month - 1], year);
    for (i = 0; i < 7; i++) {
        printf("%3s", day_names[i]);
    }
    printf("\n");
    
    int first_day = day_of_week(year, month, 1);
    int days = days_in_month(year, month);
    
    // Выравнивание первого дня
    for (i = 0; i < first_day; i++) {
        printf("   ");
    }
    
    // Печать дней месяца
    for (day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((day + first_day) % 7 == 0 || day == days) {
            printf("\n");
        }
    }
}

// Функция для вывода календаря на год
void print_year_calendar(int year) {
	int month;
    printf("\nKalendar na %d god:\n", year);
    for (month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
        printf("\n");
    }
}

// Функция для вывода текущей даты
void print_current_date() {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("Tekuschaya data: %04d.%02d.%02d\n", 
           local->tm_year + 1900, 
           local->tm_mon + 1, 
           local->tm_mday);
    printf("Den nedeli: ");
    switch(day_of_week(local->tm_year + 1900, local->tm_mon + 1, local->tm_mday)) {
        case 0: printf("Ponedelnik\n"); break;
        case 1: printf("Vtornik\n"); break;
        case 2: printf("Sreda\n"); break;
        case 3: printf("Chetverg\n"); break;
        case 4: printf("Pyatnica\n"); break;
        case 5: printf("Subbota\n"); break;
        case 6: printf("Voskresene\n"); break;
    }
}

// Основная функция
int main() {
    char input[20];
    int year, month, day;
    
    printf("Vvedite datu v formate:\n");
    printf("  gggg.mm.dd - den nedeli dlya daty\n");
    printf("  gggg.mm    - kalendar na mesyac\n");
    printf("  gggg       - kalendar na god\n");
    printf("  now        - tekuschaya data\n");
    printf("> ");
    
    scanf("%19s", input);
    
    if (strcmp(input, "now") == 0) {
        print_current_date();
    }
    else if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
        // Проверка корректности даты
        if (month < 1 || month > 12 || day < 1 || day > days_in_month(year, month)) {
            printf("Nekorrektnaya data!\n");
            return 1;
        }
        
        printf("Den nedeli: ");
        switch(day_of_week(year, month, day)) {
            case 0: printf("Ponedelnik\n"); break;
            case 1: printf("Vtornik\n"); break;
            case 2: printf("Sreda\n"); break;
            case 3: printf("Chetverg\n"); break;
            case 4: printf("Pyatnica\n"); break;
            case 5: printf("Subbota\n"); break;
            case 6: printf("Voskresene\n"); break;
        }
    }
    else if (sscanf(input, "%d.%d", &year, &month) == 2) {
        if (month < 1 || month > 12) {
            printf("Nekorrektnyy mesyac!\n");
            return 1;
        }
        print_month_calendar(year, month);
    }
    else if (sscanf(input, "%d", &year) == 1) {
        print_year_calendar(year);
    }
    else {
        printf("Nekorrektnyy vvod!\n");
        return 1;
    }
    
    return 0;
}
