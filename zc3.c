#include <stdio.h>

#define LINE_LENGHT 999

typedef struct CPLX
{
	double real;
	double imaginary;
}CPLX;

struct CPLX add(struct CPLX a, struct CPLX b)
{
	CPLX ret;
	ret.real = a.real + b.real;
	ret.imaginary = a.imaginary + b.imaginary;
	return ret;
}

struct CPLX sub(struct CPLX a, struct CPLX b)
{
	CPLX ret;
	ret.real = a.real - b.real;
	ret.imaginary = a.imaginary - b.imaginary;
	return ret;
}
struct CPLX mult(struct CPLX a, struct CPLX b)
{
	CPLX ret;
	ret.real = a.real * b.real - a.imaginary * b.imaginary;
	ret.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return ret;
}

int main(int argc, char* argv[])
{
	double real1; 
	double real2;
	double real3;
	double imaginary1, imaginary2, imaginary3;
	char operant, end, end2, end3;
	FILE *readF, *writeF;
	readF = fopen("vstup_2_3_komplex_cisla_operatory.txt", "r");
	writeF = fopen("vystup.txt", "w");

	if (readF == NULL)
	{
        printf ("File not found\n");
		printf("Press 'Enter' to exit\n");
		getchar();
        return 1;
    }


	while (fscanf(readF, "%lf %*c %*c %lf %c %lf %*c %*c %lf", &real1, &imaginary1, &operant, &real2, &imaginary2) != EOF)
	{
		CPLX first, second, third, final;
		first.real = real1;
		first.imaginary = imaginary1;
		second.real = real2;
		second.imaginary = imaginary2;

		switch (operant)
		{
			case '+':
			{
				final = add(first, second);
				break;
			}
			case '-':
			{
				final = sub(first, second);
				break;
			}
			case '*':
			{
				final = mult(first, second);
				break;
			}
			default:
			{
				break;
			}
		}

		end = getc(readF);
		if (end == '\n' || end == EOF)
		{
			fprintf(writeF,"(%lf + i %lf) %c (%lf + i %lf) = %lf + i %lf\n", first.real, first.imaginary, operant, second.real, second.imaginary, final.real, final.imaginary);	
		}
		else 
		{
			fscanf(readF, "%*c %*c %lf %*c %*c %lf", &real3, &imaginary3);
			third.real = real3;
			third.imaginary = imaginary3;

			switch (operant)
			{
				case '+':
				{
					final = add(final, third);
					break;
				}
				case '-':
				{
					final = sub(final, third);
					break;
				}
				case '*':
				{
					final = mult(final, third);
					break;
				}
				default:
				{
					break;
				}
			}

			fprintf(writeF,"(%lf + i %lf) %c (%lf + i %lf) %c (%lf + i %lf) = %lf + i %lf\n", first.real, first.imaginary, operant, second.real, second.imaginary, operant, third.real, third.imaginary, final.real, final.imaginary);	

		}
		printf("%lf + i %lf\n",final.real, final.imaginary);
		

	}

	fclose(readF);
	fclose(writeF);

	printf("Press 'Enter' to exit\n");
	getchar();
	return 0;
}

