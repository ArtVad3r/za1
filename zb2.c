#include <stdio.h>
#define MAX 20  


void NacitajMaticu(int r, int s, int A[MAX][MAX])
{
	int i, j; //'i' je riadkovy a 'j' stlpcovy index prvkov matice A ukladanych do pola A[MAX][MAX] 
	for (i = 0; i<r; i++)
		for (j = 0; j<s; j++)
			scanf("%d", &A[i][j]);
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

void ParnePrvkyPodDiag_vacsie_ako_priem(int r, int s, int A[MAX][MAX], int parne_prvky_pod_diag_f[MAX],
	int *p_pocet_parnych_prvkov_f, double *p_priemer_f, int parne_prvky_pod_diag_vacs_ako_priemer_f[MAX],
	int *p_pocet_parn_vacs_ako_priemer_f){


	int i, j, k = 0, suma = 0, pocet = 0, p_pocet_parn_vacs_ako_priemer = 0;
	double priemer = 0;


	for (i = 0; i<r; i++)
		for (j = 0; j<s; j++)
			if (i > j){
		if (A[i][j] % 2 == 0){
			parne_prvky_pod_diag_f[k] = A[i][j];
			suma += A[i][j];
			k++; pocet++;
		}
			}
	priemer = suma / (double)pocet;
	*p_priemer_f = priemer;

	k = 0;
	for (i = 0; i<pocet; i++){
		if (parne_prvky_pod_diag_f[i]>priemer){
			parne_prvky_pod_diag_vacs_ako_priemer_f[k++] = parne_prvky_pod_diag_f[i];
			p_pocet_parn_vacs_ako_priemer++;
		}
	}

	*p_pocet_parnych_prvkov_f = pocet;
	*p_pocet_parn_vacs_ako_priemer_f = p_pocet_parn_vacs_ako_priemer;

}



int main()
{
	int riadok, stlpec, A[MAX][MAX], parne_prvky_pod_diag_f[MAX], parne_prvky_pod_diag_vacs_ako_priemer_f[MAX];
	int i, j, k = 0;
	int *p_pocet_parnych_prvkov, *p_pocet_parn_vacs_ako_priemer;
	double *p_priemer;

	int p_pocet_parnych_prvkov_f = 0, p_pocet_parn_vacs_ako_priemer_f = 0;
	double p_priemer_f = 0;

	p_pocet_parnych_prvkov = &p_pocet_parnych_prvkov_f;
	p_pocet_parn_vacs_ako_priemer = &p_pocet_parn_vacs_ako_priemer_f;
	p_priemer = &p_priemer_f;



	scanf("%d %d", &riadok, &stlpec);
	NacitajMaticu(riadok, stlpec, A);

	printf("Matica A:\n");
	VypisMaticu(riadok, stlpec, A);

	ParnePrvkyPodDiag_vacsie_ako_priem(riadok, stlpec, A, parne_prvky_pod_diag_f, p_pocet_parnych_prvkov, p_priemer,
		parne_prvky_pod_diag_vacs_ako_priemer_f, p_pocet_parn_vacs_ako_priemer);

	printf("\n Parne prvky pod diagonalou: ");
	for (i = 0; i<p_pocet_parnych_prvkov_f; i++)
		printf("%d ", parne_prvky_pod_diag_f[i]);
	printf("\n Pocet parnych prvkov pod hlavnou diagonalou matice A je: %d", p_pocet_parnych_prvkov_f);
	printf("\n Priemer parnych prvkov pod hlavnou diagonalou matice A je: %.2f", p_priemer_f);
	printf("\n Parne prvky pod hlavnou diagonalou matice vacsie ako je priemer: %d \n ", parne_prvky_pod_diag_vacs_ako_priemer_f[k]);
	return 0;
}
