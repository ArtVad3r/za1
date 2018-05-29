#include<stdio.h>
int main()
{
    int k = 1, i, n = 0;

    do
    {
        printf("Zadajte %d. hodnotu: ", k++);
        scanf("%d", &i);
        if (i>25)
        {
            n++;
        }
    } while (i != 0);
    printf("Dokopy hodnoty prekracujuce 25 mA: ");
    printf("%d\n", n);

    return 0;
}
