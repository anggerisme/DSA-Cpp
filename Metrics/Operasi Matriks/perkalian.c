#include <stdio.h>

int main(){
    int baris1, kolom1, baris2, kolom2,i,j,k;
    
    // Matriks A
    printf("Baris matriks A : ");
    scanf("%d", &baris1);
    printf("Kolom matriks A : ");
    scanf("%d", &kolom1);
    int A[baris1][kolom1];
    // int B[baris2][kolom2];
    printf("Masukkan elemen matriks A :\n");
    for (i = 0; i < baris1;i++){
        for (j = 0; j < kolom1;j++){
            scanf("%d", &A[i][j]);
        }
    }

    // Matriks B

    printf("Baris matriks B : ");
    scanf("%d", &baris2);
    printf("Kolom matriks B : ");
    scanf("%d", &kolom2);
    int B[baris2][kolom2];
    printf("Masukkan elemen matriks B :\n");
    for (i = 0; i < baris2;i++){
        for (j = 0; j < kolom2;j++){
            scanf("%d", &B[i][j]);
        }
    }

    // Perkalian matriks A dan B

    int product[baris1][kolom2];
    int sum=0;
    for (i = 0; i < baris1;i++){
        for (j = 0; j < kolom2;j++){
            for(k=0;k<baris2;k++){
                sum += A[i][k] * B[k][j];

            }
            product[i][j] = sum;
            sum = 0;
        }
        // printf("\n");
    }

    printf("\n-------\nHasil :\n-------\n");
    for (i = 0; i < baris1;i++){
        for (j = 0; j < kolom2;j++){
            printf("[%d]", product[i][j]);
        }
        printf("\n");
    }   
}