#include "func.h"
#include <limits.h>
int i;  
int sum(int count, ...) {       
    va_list args;                          
    va_start(args, count);           
    int total = 0;      
    for (i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int max(int count, ...) {
    va_list args;           
    va_start(args, count);
    int max_val = INT_MIN;     
    for (i = 0; i < count; i++) {
        int a = va_arg(args, int);   
        if (a > max_val) max_val = a;
    }
    va_end(args);
    return max_val;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int min_val = INT_MAX;        
    for (i = 0; i < count; i++) {
        int b = va_arg(args, int);
        if (b < min_val) min_val = b;
    }
    va_end(args);
    return min_val;
}

double average(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return (double)total / count;
}

