#include<stdio.h>
int main()
{
    int i, suma = 0;

    do
    {
        scanf("%d", &i);
        suma += i;
    } while (i != 0);

    printf("\nsuma: %d \n", suma);
    return 0;
}
