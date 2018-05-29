A3:Bez komplexnych
#include <stdio.h>
#define MAX 20
  

double add(double a, double b)
{
    double vysledok;         
    vysledok=a+b;	
    return vysledok;
  
}

double sub(double a, double b)
{
    double vysledok;
	vysledok=a-b;
    return vysledok;
}

double mult(double a, double b)
{
   double vysledok;
   vysledok=a*b;

return vysledok;	
}

double divin(double a, double b)
{
	double vysledok;
		vysledok=a/b;
	return vysledok;
}
int test_zhodnosti_prvkov(int pocet_vysledkov_f, double pole_vysledkov_f[MAX])
{
	int j, k=0, pocet_zhod=0;
	for(j=0; j<=pocet_vysledkov_f; j++)
		{k++;
		for(k; k<=pocet_vysledkov_f; k++)
	{
		if(pole_vysledkov_f[j]==pole_vysledkov_f[k])
			pocet_zhod++;
		}}
	if(pocet_zhod==0)
		return 0;
	else
		return 1;
}
void max_min(int pocet_vysledkov_f, double pole_vysledkov_f[20], double *p_min_vysledok_f, double *p_max_vysledok_f)
{
	int l;
	float max, min;
	max=min=pole_vysledkov_f[0];
	for(l=0; l < pocet_vysledkov_f; l++)
	{
		if(max < pole_vysledkov_f[l])
		max = pole_vysledkov_f[l];
		if(min > pole_vysledkov_f[l])	
			min = pole_vysledkov_f[l];
	}
	*p_min_vysledok_f=min;
	*p_max_vysledok_f=max;
}

  
int main()
{
int i=0;
float a, b, c, medzivysledok, suma=0; double vysledok[MAX];
double priemer, min, max;
double *p_min_vysledok, *p_max_vysledok;
char op1, op2;
 FILE *vstup, *vystup;;

 p_min_vysledok= &min;
 p_max_vysledok= &max;

vstup = fopen ("vstup_cisla_operatory.txt", "r");
vystup = fopen ("vystup.txt", "w");

while(fscanf(vstup,"%f %c %f %c %f", &a, &op1, &b, &op2, &c) != EOF)
{

switch (op1)
{
case '+' : 
    		medzivysledok = add(a, b);
  		break;
case '-' : 
    		medzivysledok = sub(a, b);
  		break;
case '*' : 
    		medzivysledok = mult(a, b);
  		break;
case '/':
	{medzivysledok = divin(a, b);
	if(b==0)
		{fprintf(vystup, "Prvy delitel je nulovy\n");
	continue;}}
	break;
default:
	return 1;
	break; 

};

switch (op2)
{
case '+' : 
    		vysledok[i] = add(medzivysledok, c);
  		break;
case '-' : 
    		vysledok[i] = sub(medzivysledok, c);
  		break;
case '*' : 
    		vysledok[i] = mult(medzivysledok, c);
  		break;
case '/':
	{vysledok[i] = divin(medzivysledok, c);
	if(c==0)
		{fprintf(vystup, "Druhy delitel je nulovy\n");
	continue;}}
	break;
default:
	return 1;
	break; 

};

fprintf(vystup,"%.6f  %c %.6f %c %.6f= %.10f\n", a, op1, b, op2, c, vysledok[i]);
suma+=vysledok[i];
i++;
}
priemer=suma/i;
fprintf(vystup, "Pocet platnych vysledkov: %d\n", i);
fprintf(vystup, "Suma platnych vysledkov: %.6f\n", suma);
fprintf(vystup, "Aritmeticky priemer: %.10f\n", priemer);
max_min(i, vysledok, p_min_vysledok, p_max_vysledok);
if(test_zhodnosti_prvkov(i, vysledok)==1)
	fprintf(vystup, "Neda sa urcit min\n");
else
	fprintf(vystup, "Minimum: %f\n", min);
if(test_zhodnosti_prvkov(i, vysledok)==1)
	fprintf(vystup, "Neda sa urcit max\n");
else
	fprintf(vystup, "Maximum: %f\n", max);

	
fclose (vstup);
fclose (vystup);

   	return 0;
}
