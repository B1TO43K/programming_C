#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hum {
    char a[100];
    char b[100];
    char c[100];
    int d;
};

int main() {
    FILE *fp;
    fp = fopen("text.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int kolvo = 0;
    char stroka[256];


    while (fgets(stroka, sizeof(stroka), fp)) {
        kolvo++;
    }
    rewind(fp);

    struct Hum chel1[kolvo];
    struct Hum chel2[kolvo];

    int i;
    for (i = 0; i < kolvo; i++) {
        if (fgets(stroka, sizeof(stroka), fp) != NULL) {
            sscanf(stroka, "%s %s %s %d", chel1[i].a, chel1[i].b, chel1[i].c, &chel1[i].d);
        }
    }

    fclose(fp);

    for (i = 0; i < kolvo; i++) {
        printf("fName: %s\n", chel1[i].a);
        printf("Name: %s\n", chel1[i].b);
        printf("Middle name: %s\n", chel1[i].c);
        printf("Birth: %d\n", chel1[i].d);
        printf("\n");
        chel2[i] = chel1[i];
    }

    int tmp;
    int k, j, g;

    for(k = 0; k < kolvo; k++)
        for(j=0; j < kolvo -1; j++)
           {
              if (chel2[j].d>chel2[j+1].d){
                     tmp = chel2[j].d;
                     chel2[j].d = chel2[j+1].d;
                     chel2[j+1].d = tmp;
                  }
           }

           printf("RESULT: \n");


        for (i = 0; i < kolvo; i++) {
            printf("fName: %s\n", chel2[i].a);
            printf("Name: %s\n", chel2[i].b);
            printf("Middle name: %s\n", chel2[i].c);
            printf("Birth: %d\n", chel2[i].d);
            printf("\n");
        }

    return 0;
}
