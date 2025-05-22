#include <stdio.h>

// Ôóíêöèÿ äëÿ âûâîäà öèôð ÷èñëà â îáû÷íîì ïîðÿäêå (ñ while)
void printDigits(int n) 
{
    // Áàçîâûé ñëó÷àé: åñëè ÷èñëî ìåíüøå 10, ïðîñòî ïå÷àòàåì åãî
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // Íàõîäèì ñòåïåíü 10, ñîîòâåòñòâóþùóþ ïåðâîé öèôðå
    int divisor = 1;
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    
    // Ïå÷àòàåì öèôðû ñëåâà íàïðàâî
    while (divisor > 0) {
        printf("%d ", n / divisor);
        n %= divisor;
        divisor /= 10;
    }
}

// Ôóíêöèÿ äëÿ âûâîäà öèôð ÷èñëà â îáðàòíîì ïîðÿäêå (ñ while)
void printReverseDigits(int n) 
{
    // Áàçîâûé ñëó÷àé: åñëè ÷èñëî ìåíüøå 10, ïðîñòî ïå÷àòàåì åãî
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // Ïå÷àòàåì ïîñëåäíþþ öèôðó
    printf("%d ", n % 10);
    
    // Ðåêóðñèâíî âûçûâàåì äëÿ îñòàâøåéñÿ ÷àñòè ÷èñëà
    printReverseDigits(n / 10);
}

int main() {
    int N;
    printf("Enter number: ");
    scanf("%d", &N);
    
    printf("The number %d in the usual order: ", N);
    printDigits(N);
    printf("\n");
    
    printf("The number %d in reverse order: ", N);
    printReverseDigits(N);
    printf("\n");
    
    return 0;
}

