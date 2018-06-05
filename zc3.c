#include <stdio.h>

#define LINE_LENGHT 999

typedef struct CPLX
{
    double realne;
    double imaginarne;
}CPLX;

struct CPLX add(struct CPLX a, struct CPLX b)
{
    CPLX cfg;
    cfg.realne = a.realne + b.realne;
    cfg.imaginarne = a.imaginarne + b.imaginarne;
    return cfg;
}

struct CPLX sub(struct CPLX a, struct CPLX b)
{
    CPLX cfg;
    cfg.realne = a.realne - b.realne;
    cfg.imaginarne = a.imaginarne - b.imaginarne;
    return cfg;
}
struct CPLX mult(struct CPLX a, struct CPLX b)
{
    CPLX cfg;
    cfg.realne = a.realne * b.realne - a.imaginarne * b.imaginarne;
    cfg.imaginarne = a.realne * b.imaginarne + a.imaginarne * b.realne;
    return cfg;
}

int main(int argc, char* argv[])
{
    double realne1;
    double realne2;
    double realne3;
    double imaginarne1, imaginarne2, imaginarne3;
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


    while (fscanf(readF, "%lf %*c %*c %lf %c %lf %*c %*c %lf", &realne1, &imaginarne1, &operant, &realne2, &imaginarne2) != EOF)
    {
        CPLX first, second, third, final;
        first.realne = realne1;
        first.imaginarne = imaginarne1;
        second.realne = realne2;
        second.imaginarne = imaginarne2;

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
            fprintf(writeF,"(%lf + i %lf) %c (%lf + i %lf) = %lf + i %lf\n", first.realne, first.imaginarne, operant, second.realne, second.imaginarne, final.realne, final.imaginarne);
        }
        else
        {
            fscanf(readF, "%*c %*c %lf %*c %*c %lf", &realne3, &imaginarne3);
            third.realne = realne3;
            third.imaginarne = imaginarne3;

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

            fprintf(writeF,"(%lf + i %lf) %c (%lf + i %lf) %c (%lf + i %lf) = %lf + i %lf\n", first.realne, first.imaginarne, operant, second.realne, second.imaginarne, operant, third.realne, third.imaginarne, final.realne, final.imaginarne);
        }
        printf("%lf + i %lf\n",final.realne, final.imaginarne);


    }

    fclose(readF);
    fclose(writeF);

    printf("Press 'Enter' to exit\n");
    getchar();
    return 0;
}
