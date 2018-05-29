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

void NeparnePrvkyPodDiagonalou(int r, int s, int A[MAX][MAX],
	int neparne_prvky_pod_diag_f[MAX], int *p_pocet_neparn_prvkov_f, double *p_priemer_f, int *p_suma_f)
{
	int i, j, mod, k = 0, pocet_neparnych = 0, suma = 0, l = 0;
	double priemer = 0;

	for (i = 0; i<r; i++)
	{
		for (j = 0; j<s; j++)
		{
			mod = A[i][j] % 2;
			if ((mod != 0) && (i>j))
			{
				neparne_prvky_pod_diag_f[k] = A[i][j];
				pocet_neparnych++;
				suma += neparne_prvky_pod_diag_f[k];
				k++;
			}
		}
	}
	priemer = suma / (double)pocet_neparnych;


	*p_pocet_neparn_prvkov_f = pocet_neparnych;
	*p_priemer_f = priemer;                    ///premenna do ktorej si ulozim adresu inej premennej
	*p_suma_f = suma;            		 ///void mi vrati len prvky a ja chcem celu hodnotu cize preto som pouzil pointre
}
int main()
{
	int i, riadok, stlpec, pocet_neparn_prvkov, suma;
	int A[MAX][MAX], neparne_prvky_pod_diag[MAX];
	double priemer;

	int *p_pocet_neparn_prvkov, *p_suma;
	double *p_priemer;

	p_pocet_neparn_prvkov = &pocet_neparn_prvkov;
	p_priemer = &priemer;
	p_suma = &suma;

	scanf("%d %d", &riadok, &stlpec);

	NacitajMaticu(riadok, stlpec, A);
	printf("Matica A:\n");
	VypisMaticu(riadok, stlpec, A);

	NeparnePrvkyPodDiagonalou(riadok, stlpec, A, neparne_prvky_pod_diag, p_pocet_neparn_prvkov, p_priemer, p_suma);

	printf("\nNeparne prvky pod hlavnou diagonalou matice A su:  ");
	for (i = 0; i<pocet_neparn_prvkov; i++)
		printf("%3d", neparne_prvky_pod_diag[i]);

	printf("\nPocet neparnych prvkov pod hlavnou diagonalou matice A je: %d", pocet_neparn_prvkov);
	printf("\nPriemer neparnych prvkov pod hlavnou diagonalou matice A je: %.2f", priemer);
	printf("\nSuma neparnych prvkov pod hlavnou diagonalou matice A je: %d", suma);
	printf("\n");

	return 0;

}
