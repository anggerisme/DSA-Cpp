#include <stdio.h>

/*
    1. Program : Transpose Matriks

*/


int main(){
    int baris;
    int kolom;
    printf("Matriks Baris : ");
    scanf("%d", &baris);
    printf("Matriks Kolom : ");
    scanf("%d", &kolom);
    
    int M[baris][kolom], i, j;
    int T[baris][kolom];

    // ------------ Determinan 2x2 --------------
        printf("Masukkan elemen Matriks :\n");
        for (i = 0; i < baris;i++){
            for (j = 0; j < kolom;j++){
                // masukkan elemen
                scanf("%d", &M[i][j]);
            }
        }

        for (i = 0; i < baris;i++){
            for (j = 0; j < kolom;j++){
                T[j][i] = M[i][j];
            }
        }
        printf("\nTranspose matriks\n");
        for (i = 0; i < kolom;i++){
            printf("[ ");
            for (j = 0; j < baris;j++){
                printf("%d ", T[i][j]);
            }
            printf("]");
            printf("\n");
        }
}