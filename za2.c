#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void NacitajMaticu(int r, int s, int A[MAX][MAX])
{
	int i, j;
	for (i = 0; i<r; i++)
	{
		for (j = 0; j<s; j++)
			scanf("%d", &A[i][j]);
	}
}

void VypisMaticu(int r, int s, int A[MAX][MAX])
{
	int i, j;

	for (i = 0; i<r; i++)
	{
		for (j = 0; j<s; j++)
			printf("%5d", A[i][j]);
		printf("\n");
	}
}

void ParnePrvkyNadDiagonalou(int r, int s, int A[MAX][MAX],
	int parne_prvky_pod_diag_f[MAX], int *p_pocet_parn_prvkov_f, double *p_priemer_f, int *p_suma_f)
{
	int i, j, mod, k = 0, pocet_parnych = 0, suma = 0, l = 0;
	double priemer = 0;

	for (i = 0; i<r; i++)
	{
		for (j = 0; j<s; j++)
		{
			mod = A[i][j] % 2;
			if ((mod == 0) && (i<j))
			{
				parne_prvky_pod_diag_f[k] = A[i][j];
				pocet_parnych++;
				suma += parne_prvky_pod_diag_f[k];
				k++;
			}
		}
	}
	priemer = suma / (double)pocet_parnych;


	*p_pocet_parn_prvkov_f = pocet_parnych;
	*p_priemer_f = priemer;
	*p_suma_f = suma;
}
int main()
{
	int i, riadok, stlpec, pocet_parn_prvkov, suma;
	int A[MAX][MAX], parne_prvky_pod_diag[MAX];
	double priemer;

	int *p_pocet_parn_prvkov, *p_suma;
	double *p_priemer;

	p_pocet_parn_prvkov = &pocet_parn_prvkov;
	p_priemer = &priemer;
	p_suma = &suma;

	scanf("%d %d", &riadok, &stlpec);

	NacitajMaticu(riadok, stlpec, A);
	printf("Matica A:\n");
	VypisMaticu(riadok, stlpec, A);

	ParnePrvkyNadDiagonalou(riadok, stlpec, A, parne_prvky_pod_diag, p_pocet_parn_prvkov, p_priemer, p_suma);

	printf("\nParne prvky nad hlavnou diagonalou matice A su:  ");
	for (i = 0; i<pocet_parn_prvkov; i++)
		printf("%3d", parne_prvky_pod_diag[i]);

	printf("\nPocet parnych prvkov nad hlavnou diagonalou matice A je: %d", pocet_parn_prvkov);
	printf("\nPriemer parnych prvkov nad hlavnou diagonalou matice A je: %.2f", priemer);
	printf("\nSuma parnych prvkov nad hlavnou diagonalou matice A je: %d\n", suma);
	printf("\n");

	return 0;

}
