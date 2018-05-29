#include <stdio.h>
#include <process.h>

#define MAX 20

void NacitajMaticu(int r, int s, int A[MAX][MAX]){
    int i, j;
    printf("Zadajte prvky matice %d x %d:\n", r, s);
    for(i=0; i<r; i++){
        for(j=0;j<s;j++)
            scanf("%d", &A[i][j]);
    }

}

void VypisMaticu(int r, int s, int A[MAX][MAX]){
    int i, j;
    printf("Vypis matice %d x %d:\n", r, s);
    for(i=0; i<r; i++){
        for(j=0;j<s;j++)
            printf("%5d", A[i][j]);
        printf("\n");
    }


}

void ParnePrvkyPodDiag_vacsie_ako_priem(int r, int s, int A[MAX][MAX], int parne_prvky_pod_diag_f[MAX], int *p_pocet_f, int *p_suma_f, double *p_priemer_f, int parne_prvky_pod_diag_vacs_ako_priem_f[MAX], int *p_pocet_parn_vacs_ako_priem_f){
    //zavedenie premennych na docasne pouzitie
    int i, j, k=0, mod, h=0;
    double priemer;

    //cyklus, prechadzanie matice a nasledne zapisovanie udajov pri vyhovujucej pozicii v matici
    for(i=0; i<r; i++){
        for(j=0;j<s;j++) {
            mod = A[i][j] % 2;
            if (i > j & mod == 0) {
                parne_prvky_pod_diag_f[k++] = A[i][j];
                *p_pocet_f += 1;
                *p_suma_f += A[i][j];
            }
        }
    }
    priemer = *p_suma_f / (double)*p_pocet_f;
    *p_priemer_f=priemer;

    for(i=0; i<*p_pocet_f; i++) {
        if (parne_prvky_pod_diag_f[i] > priemer) {
            *p_pocet_parn_vacs_ako_priem_f += 1;
            parne_prvky_pod_diag_vacs_ako_priem_f[h++]=parne_prvky_pod_diag_f[i];
        }
    }
}

int main(int argc, char* argv[]) {
    //definovanie premennych a pointerov
    int r_a, s_a, A[MAX][MAX], parne_prvky_pod_diag_f[MAX], *p_suma_f, suma_parnych=0, pocet_parnych=0, *p_pocet_f, parne_prvky_pod_diag_vacs_ako_priem_f[MAX], *p_pocet_parn_vacs_ako_priem_f, pocet_parn_vacs_ako_priemer=0;
    double priemer_parnych=0, *p_priemer_f;

    //zavedenie pointerov
    p_pocet_f=&pocet_parnych;
    p_suma_f=&suma_parnych;
    p_priemer_f=&priemer_parnych;
    p_pocet_parn_vacs_ako_priem_f=&pocet_parn_vacs_ako_priemer;


    //zadanie rozmerov matice s kontrolou neplatnej velkosti
    do {
        printf("Zadajte rozmery matice (max 19x19):\n");
        scanf("%d %d", &r_a, &s_a);

        if (r_a>19 || s_a>19)
            printf("\n[CHYBA] Zadali ste vacsi rozmer, ako je povoleny. Zadajte rozmery znovu: \n\n");
        else if(r_a<1, s_a<1)
            printf("\n[CHYBA] Zadali ste nezmyselnu velkost matice. Zadajte rozmery znovu: \n \n");

    }while(r_a>19 || s_a>19 || r_a <1, s_a <1);


    //nacitanie a vypisanie matice
    NacitajMaticu(r_a, s_a, A);
    VypisMaticu(r_a, s_a, A);

    //spustenie algoritmu na analyzu a spracovanie matice, posielanie adries pointerov
    ParnePrvkyPodDiag_vacsie_ako_priem(r_a , s_a, A, parne_prvky_pod_diag_f, p_pocet_f, p_suma_f, p_priemer_f, parne_prvky_pod_diag_vacs_ako_priem_f, p_pocet_parn_vacs_ako_priem_f);

    //vypisanie vysledkov
    printf("Priemer parnych cisel trojuholniku pod diagonalou je: %.2f\nPocet parnych cisel je: %d\n", priemer_parnych, pocet_parnych);
    printf("Pole s parnymi prvkami pod diag su: ");
    for (int i = 0; i < pocet_parnych; i++) {
        printf("%d ", parne_prvky_pod_diag_f[i]);
    }
    printf("\nParne prvky pod diag vacsie ako priemer su: ");

    for (int i = 0; i < pocet_parn_vacs_ako_priemer; i++) {
        printf("%d ", parne_prvky_pod_diag_vacs_ako_priem_f[i]);
    }
    printf("\n\n");

    system("Pause");
    return 0;
