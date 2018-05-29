#include <stdio.h>
#define MAX 20

void NacitajMaticu(int r, int s, int A[MAX][MAX]){
    int i, j;
    printf("Zadajte prvky matice:\n");
    for(i=0; i<r; i++){
        for(j=0;j<s;j++)
            scanf("%d", &A[i][j]);
    }

}

void VypisMaticu(int r, int s, int A[MAX][MAX]){
    int i, j;
    printf("Vypis matice: \n");
    for(i=0; i<r; i++){
        for(j=0;j<s;j++)
            printf("%5d", A[i][j]);
        printf("\n");
    }


}

void ParnePrvkyNadDiagonalou(int r, int s, int A[MAX][MAX], int parne_prvky_nad_diag_f[MAX], int *p_pocet_f, int *p_suma_f, double *p_priemer_f){
    //zavedenie premennych na docasne pouzitie
    int i, j, k=0, mod=0;

    //cyklus, prechadzanie matice a nasledne zapisovanie udajov pri vyhovujucej pozicii v matici
    for(i=0; i<r; i++){
        for(j=0;j<s;j++) {
            mod = A[i][j] % 2;
            k++;
            if (i < j & mod == 0) {
                parne_prvky_nad_diag_f[k] = A[i][j];
                *p_pocet_f += 1;
                *p_suma_f += A[i][j];
            }
        }
    }
    *p_priemer_f = *p_suma_f / (double)*p_pocet_f;

}

int main(int argc, char* argv[]) {
    //definovanie premennych a pointerov
    int r_a, s_a, A[MAX][MAX], parne_prvky_nad_diag_f[MAX], *p_suma_f, suma_parnych = 0, pocet_parnych = 0, *p_pocet_f;
    double priemer_parnych = 0, *p_priemer_f;

    //zavedenie pointerov
    p_pocet_f = &pocet_parnych;
    p_suma_f = &suma_parnych;
    p_priemer_f = &priemer_parnych;


    //zadanie rozmerov matice s kontrolou neplatnej velkosti
    do {
        printf("Zadajte rozmery matice: \n");
        scanf("%d %d", &r_a, &s_a);

        if (r_a > 19 || s_a > 19)
            printf("\n[CHYBA] Zadali ste vacsi rozmer, ako je povoleny. Zadajte rozmery znovu: \n\n");
        else if (r_a < 1, s_a < 1)
            printf("\n[CHYBA] Zadali ste nezmyselnu velkost matice. Zadajte rozmery znovu: \n \n");

    } while (r_a > 19 || s_a > 19 || r_a < 1, s_a < 1);


    //nacitanie a vypisanie matice
    NacitajMaticu(r_a, s_a, A);
    VypisMaticu(r_a, s_a, A);

    //spustenie algoritmu na analyzu a spracovanie matice, posielanie adries pointerov
    ParnePrvkyNadDiagonalou(r_a, s_a, A, parne_prvky_nad_diag_f, p_pocet_f, p_suma_f, p_priemer_f);

    //vypisanie vysledkov
    printf("Priemer parnych cisel trojuholniku nad diagonalou je: %.2f\nSuma parnych cisel trojuholniku nad diagonalou je: %d\nPocet parnych cisel nad diagonalou je: %d\n",
           priemer_parnych, suma_parnych, pocet_parnych);

    return 0;
}
