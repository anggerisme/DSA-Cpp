/*
    Program : 2D Arrays

    Konsep :
        Arrays yang sama seperti array pada umumnya tetapi dapat diakses/divisualisasikan dalam bentuk grid yg mempunyai baris dan kolom

        Pengalokasian Alamat memory-nya pun bersifat linier 

*/

#include <iostream>

using namespace std;

int main(){
    // 1. ---------------- Array inside stack ----------

    int A[3][4] = {{1, 2, 3, 4},
                   {4, 5, 6, 7},
                   {8, 9, 10, 11}};
    // 2. ---------------- Array of pointer ----------
    /*
        Dibuatlah 3 buah kolom, kemudian 3 buah kolom tersebut dibuat array lagi didalamnya yang disimpan di dalam heap.
    */
    int *B[3]; // Created inside stack
    
    int **C; // Should be declared at first
    int i, j;
    
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    // 3. ---------------- Double pointers ----------

    C = new int *[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (i = 0; i < 3;i++){
        for (j = 0; j < 4;j++){
            cout << *B[i][j];// Value are garbage cause we have not initialized.
            // cout << C[i][j] << endl;
        }
        cout << endl;
    }
}