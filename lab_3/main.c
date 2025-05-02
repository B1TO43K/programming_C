#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[80];
	int i, len;
	printf("vvedi stroky do 80ti simvolov:\n");
	scanf("%s", s);
	len = sizeof(s) / sizeof(s[0]);
	for(i = 0; i < len; i++){
		if(s[i]== 'a'){
		s[i] = 'A';
	}
		if(s[i]=='b'){		
		s[i] = 'B';
	}
	}
	printf(s);
	return 0;
}
