#include <stdio.h>
#include "func.h"
int main() {
    printf("Sum: %d\n", sum(2, 15, 30));
    printf("Maximum: %d\n", max(4, 100, 30, 10, 45));
    printf("Minimum: %d\n", min(3, 5, 55, 25.5));
    printf("Average: %.2f\n", average(3, 15, 5, 10));
    return 0;
}

