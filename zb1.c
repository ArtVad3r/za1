#include<stdio.h>

int main()
{
    int pocitadlo = 1;
    float i, suma=0;
    do {
        printf("%d. sladkost.\n", pocitadlo++);
        scanf("%f", &i);
        suma += i;
    }while(suma<=10);
    suma -= i;
    printf("Nakup bol vycisleny na: %2f eur", suma);
    return 0;
}
