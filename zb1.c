#include <stdio.h>
int main()
{
	float a, suma = 0;
	do
	{
		scanf("%f", &a);
		suma += a;
	} while (suma <= 10);
	suma -= a;
	printf("%.2f", suma);
	return 0;
}
