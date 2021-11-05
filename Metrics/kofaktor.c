#include <stdio.h>

int main(){
    int baris1, kolom1,i,j;
    
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

    int B[baris1][kolom1];

    B[0][0] = 1*(A[1][1]*A[2][2]-A[1][2]*A[2][1]);
    B[0][1] = -1*(A[1][0]*A[2][2]-A[1][2]*A[2][0]);
    B[0][2] = 1*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    
    B[1][0] = -1*(A[0][1]*A[2][2]-A[2][1]*A[0][2]);
    B[1][1] = 1*(A[0][0]*A[2][2]-A[2][0]*A[0][2]);
    B[1][2] = -1*(A[0][0]*A[2][1]-A[2][0]*A[0][1]);
    
    B[2][0] = 1*(A[0][1]*A[1][2]-A[1][1]*A[0][2]);
    B[2][1] = -1*(A[0][0]*A[1][2]-A[0][2]*A[1][0]);
    B[2][2] = 1*(A[0][0]*A[1][1]-A[0][1]*A[1][0]);

    // int product[baris1][kolom1];

    printf("\n-------------\nMatriks\n-----------\n\n");
    for (i = 0; i < baris1;i++){
        printf("[ ");
        for (j = 0; j < kolom1;j++){
            printf("%d ", B[i][j]);
        }
        printf("]");
        printf("\n");
    }

}