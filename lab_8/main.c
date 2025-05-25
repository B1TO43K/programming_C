#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

typedef struct{
		char firstname[50];
		char lastname[50];
		int birth_date;
		char sex[10];
		float height;
		int index;
	}human;
	
int compare_by_birth_date(const void *x, const void *y){
	const human *person_x = (const human *)x;
    const human *person_y = (const human *)y;
    int k = (person_x->birth_date > person_y->birth_date) - (person_x->birth_date < person_y->birth_date);
	return k != 0 ? k : (person_x->index - person_y->index);
}

int compare_by_firstname(const void *x, const void *y){
	const human *person_x = (const human *)x;
	const human *person_y = (const human *)y;
	int k = strcmp(person_x->firstname, person_y->firstname);
	return k != 0 ? k : (person_x->index - person_y->index);
}

int compare_by_lastname(const void *x, const void *y){
	const human *person_x = (const human *)x;
	const human *person_y = (const human *)y;
	int k = strcmp(person_x->lastname, person_y->lastname);
	return k != 0 ? k : (person_x->index - person_y->index);
}

int compare_by_sex(const void *x, const void *y){
	const human *person_x = (const human *)x;
	const human *person_y = (const human *)y;
	int k = strcmp(person_x->sex, person_y->sex);
	return k != 0 ? k : (person_x->index - person_y->index);
}

int compare_by_height(const void *x, const void *y){
	const human *person_x = (const human *)x;
	const human *person_y = (const human *)y;
	int k = (person_x->height > person_y->height) - (person_x->height < person_y->height);
	return k != 0 ? k : (person_x->index - person_y->index);
}

int main() {
	FILE *ln;
	ln = fopen("text.txt", "r");
	int i, j, size = 0;
	char *input = malloc(N * sizeof(char));
	char str[N];
	while(fgets(str, N, ln) != NULL){
		size++;
	}
	rewind(ln);
	human original[size];
	human sorted[size];
	
	for(i = 0; i < size; i++){
		fscanf(ln, "%s %s %d %s %f", 
			original[i].firstname, 
			original[i].lastname, 
			&original[i].birth_date,
			original[i].sex,
			&original[i].height);
	}
	fclose(ln);	
	
	for (i = 0; i<size; i++){
		sorted[i] = original[i];
		sorted[i].index = i;
	}
	
	printf("vvedite zapros na sortirovky: f if firstname, l if lastname, b if birth_date, s if sex, h if height\n");
	scanf("%s", input);
	for(i=strlen(input)-1; i>=0; i--){
		switch (input[i]){
			case 'f': 
				qsort(sorted, size, sizeof(human), compare_by_firstname);
				break;
			case 'l': 
				qsort(sorted, size, sizeof(human), compare_by_lastname);			
				break;
			case 'b': 
				qsort(sorted, size, sizeof(human), compare_by_birth_date);			
				break;
			case 's': 
				qsort(sorted, size, sizeof(human), compare_by_sex);	
				break;
			case 'h': 
				qsort(sorted, size, sizeof(human), compare_by_height);	
				break;
		}
		for (j = 0; j<size; j++){
			sorted[j].index = j;
		}
	}
	
	for(i=0; i<size; i++){
		printf("%s %s %d %s %.2f\n", sorted[i].firstname, sorted[i].lastname, sorted[i].birth_date, sorted[i].sex, sorted[i].height);
	}
	
	free(input);
	return 0;
}

