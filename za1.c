#include<stdio.h>
#define max 100
int main()
{
	int cisla[max], i = 0, suma = 0;

	do
	{
		scanf("%d", &cisla[i]);
		suma += cisla[i];
	} while (cisla[i++] != 0);

	printf("\nsuma: %d \n", suma);
	return 0;
}
