#include<stdio.h>
int main()
{
	int a, s = 0;

	do
	{
		scanf("%d", &a);
		if (a>25)
		{
			s++;
		}
	} while (a != 0);
	printf("%d\n", s);

	return 0;
}
