#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int birthYear;
} human;

int main() {
    human people1[4];
    human people2[4];
    int i, j;
    human temp;

    printf("vvedite people1:\n");
    for (i = 0; i < 4; i++) {
        printf("chelovek %d:\n", i + 1);
        printf("name: ");
        scanf("%s", people1[i].name); 
        printf("surname: ");
        scanf("%s", people1[i].surname); 
        printf("date bith: ");
        scanf("%d", &people1[i].birthYear);
        printf("\n");
    }

    for (i = 0; i < 4; i++) {
        strcpy(people2[i].name, people1[i].name);
        strcpy(people2[i].surname, people1[i].surname);
        people2[i].birthYear = people1[i].birthYear;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (people2[j].birthYear > people2[j + 1].birthYear) {
                temp = people2[j];
                people2[j] = people2[j + 1];
                people2[j + 1] = temp;
            }
        }
    }

    printf("\nOtsortirovanniy massiv people2 po date:\n");
    for (i = 0; i < 4; i++) {
        printf("  %s %s (%d)\n", people2[i].name, people2[i].surname, people2[i].birthYear);
    }

    return 0;
}

