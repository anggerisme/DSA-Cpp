#include <stdio.h>

/*
    1. Program : Determinan matriks, 2x2, 3x3, 4x4

*/


int main(){
    int baris;
    int kolom;
    printf("Matriks ordo : ");
    scanf("%d", &baris);
    
    int matriks[baris][baris], i, j;

    // ------------ Determinan 2x2 --------------
    if(baris && kolom ==2){
        printf("2");
        printf("Masukkan elemen matriks :\n");
        for (i = 0; i < baris;i++){
            for (j = 0; j < kolom;j++){
                // masukkan elemen
                scanf("%d", &matriks[i][j]);
            }
        }
        
        int det1 = matriks[0][0] * matriks[1][1];
        int det2 = matriks[1][0] * matriks[0][1];
        int det3 = det1 - det2;
        
        printf("determinan : %d", det3);

    }

    // ------------ Determinan 3x3 --------------
    else if( baris && kolom == 3){
        int det;
        printf("Masukkan elemen matriks :\n");
        for (i = 0; i < baris;i++){
            for (j = 0; j < kolom;j++){
                // masukkan elemen
                scanf("%d", &matriks[i][j]);

            }
        }
        det =matriks[0][0]*matriks[1][1]*matriks[2][2]
            +matriks[0][1]*matriks[1][2]*matriks[2][0]
            +matriks[0][2]*matriks[1][0]*matriks[2][1]
            -matriks[0][2]*matriks[1][1]*matriks[2][0]
            -matriks[0][0]*matriks[1][2]*matriks[2][1]
            -matriks[0][1]*matriks[1][0]*matriks[2][2];
        printf("determinan : %d", det);
    }


    // ------------ Determinan 4x4 --------------
    else if(baris && kolom ==4){
        printf("Masukkan elemen matriks :\n");
        for (i = 0; i < baris;i++){
            for (j = 0; j < kolom;j++){
                // masukkan elemen
                scanf("%d", &matriks[i][j]);

            }
        }

        int det1, det2, det3, det4;
        det1 = matriks[1][1] * (matriks[2][2] * matriks[3][3] - matriks[2][3] * matriks[3][2]) 
        - matriks[1][2] * (matriks[2][1] * matriks[3][3] - matriks[2][3] * matriks[3][1]) 
        + matriks[1][3] * (matriks[2][1] * matriks[3][2] - matriks[2][2] * matriks[3][1]);


        det2 = matriks[1][0] * (matriks[2][2] * matriks[3][3] - matriks[2][3] * matriks[3][2]) 
        - matriks[1][2] * (matriks[2][0] * matriks[3][3] - matriks[2][3] * matriks[3][0]) 
        + matriks[1][3] * (matriks[2][0] * matriks[3][2] - matriks[2][2] * matriks[3][0]);

        det3 = matriks[1][0] * (matriks[2][1] * matriks[3][3] - matriks[2][3] * matriks[3][1]) 
        - matriks[1][1] * (matriks[2][0] * matriks[3][3] - matriks[2][3] * matriks[3][0]) 
        + matriks[1][3] * (matriks[2][0] * matriks[3][1] - matriks[2][1] * matriks[3][0]);
        // printf("%d", det3);

        det4 = matriks[1][0] * (matriks[2][1] * matriks[3][2] - matriks[2][2] * matriks[3][1]) 
        - matriks[1][1] * (matriks[2][0] * matriks[3][2] - matriks[2][2] * matriks[3][0]) 
        + matriks[1][2] * (matriks[2][0] * matriks[3][1] - matriks[2][1] * matriks[3][0]);

        int determinan = (1*(matriks[0][0] * det1)) + (-1*(matriks[0][1] * det2)) + (1*(matriks[0][2] * det3)) + (-1*(matriks[0][3]*det4));

        printf("Determinan :%d", determinan);
    }


    
}