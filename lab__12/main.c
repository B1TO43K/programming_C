#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Проверка високосного года
bool is_leap_year(int year) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = 1;
    timeinfo.tm_mday = 29;
    timeinfo.tm_hour = 12;
    
    return mktime(&timeinfo) != -1 && timeinfo.tm_mday == 29;
}

// Определение дня недели 
int day_of_week(int year, int month, int day) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 12;
    
    if (mktime(&timeinfo) == -1) {
        return -1;
    }
    return (timeinfo.tm_wday + 6) % 7;
}

// Количество дней в месяце
int days_in_month(int year, int month) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month;
    timeinfo.tm_mday = 0; // 0 день = последний день предыдущего месяца
    timeinfo.tm_hour = 12;
    
    mktime(&timeinfo);
    return timeinfo.tm_mday;
}

// Вывод календаря на месяц
void print_month_calendar(int year, int month) {
	int i, day;
    const char *month_names[] = {"Yanvar", "Fevral", "Mart", "Aprel", "May", "Iyun",
                               "Iyul", "Avgust", "Sentyabr", "Oktyabr", "Noyabr", "Dekabr"};
    const char *day_names[] = {"Pn", "Vt", "Sr", "Ch", "Pt", "Sb", "Vs"};
    
    printf("\n     %s %d\n", month_names[month - 1], year);
    for (i = 0; i < 7; i++) {
        printf("%3s", day_names[i]);
    }
    printf("\n");
    
    int first_day = day_of_week(year, month, 1);
    int days = days_in_month(year, month);
    
    for (i = 0; i < first_day; i++) {
        printf("   ");
    }
    
    for (day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((day + first_day) % 7 == 0 || day == days) {
            printf("\n");
        }
    }
}

// Вывод календаря на год
void print_year_calendar(int year) {
	int month;
    printf("\nKalendar na %d god:\n", year);
    for (month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
        printf("\n");
    }
}

// Вывод текущей даты
void print_current_date() {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    
    printf("Tekuschaya data: %02d.%02d.%04d\n", 
           local->tm_mday, 
           local->tm_mon + 1, 
           local->tm_year + 1900);
    
    const char *weekdays[] = {"Ponedelnik", "Vtornik", "Sreda", "Chetverg", 
                             "Pyatnica", "Subbota", "Voskresene"};
    int wday = (local->tm_wday + 6) % 7;
    printf("Den nedeli: %s\n", weekdays[wday]);
}

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
        if (month < 1 || month > 12 || day < 1 || day > days_in_month(year, month)) {
            printf("Nekorrektnaya data!\n");
            return 1;
        }
        
        const char *weekdays[] = {"Ponedelnik", "Vtornik", "Sreda", "Chetverg", 
                                 "Pyatnica", "Subbota", "Voskresene"};
        int wday = day_of_week(year, month, day);
        printf("Den nedeli: %s\n", weekdays[wday]);
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

 /*struct tm {
    int tm_sec;     Секунды [0-59]
    int tm_min;     Минуты [0-59]
    int tm_hour;    Часы [0-23]
    int tm_mday;    День месяца [1-31]
    int tm_mon;     Месяц [0-11] (0 = январь)
    int tm_year;    Год (текущий год - 1900)
    int tm_wday;    День недели [0-6] (0 = воскресенье)
    int tm_yday;    День года [0-365]
    int tm_isdst;   Флаг летнего времени (DST)
};*/
