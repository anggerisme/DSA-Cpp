#include <iostream>

/*
    Program : Diagonal matrix

    Konsep :
        Matriks[i, j] = 0 if {
            i != j jadi yg bernilai 0 selain matrix {1,1}, {2, 2} , {3, 3} dst. 
        }
    
    Objektif :
        Program ini akan menyimpan array/matriks dengan ordo 5x5 tetapi hanya menyimpan angka yang bukan 0 saja. Bagaimana? dengan membuat array satu dimensi yang berisi nilai bukan 0. Jadi tidak buang-buang memory.

    Ide Kunci :
        1. Cek diagonal matrix
            - Intinya semua harus bernilai 0 kecuali nilai pada posisi diagonalnya
                code : m[i,j]=0 pada posisi i!=j
            Untuk cek apakah suatu matrix merupakan diagonal matrix atau bukan cukup dengan melihat diagonalnya saja
                - nilai diagonalnya ditandai ketika i=j artinya nilai i dan j sama, jika i!=j maka bukan diagonal matrix 

    Algorithm :
        1. Perlu diketahui bahwa matriks di matematika dimulai dari indeks 1 sedangkan di pemrograman indeks pada array dimulai dari 0. 
        Sehingga ketika ingin mengakses nilai matriks {1, 1} maka di program harus kita kurangi 1
            if (i==j) // Nilai bukan 0 yg ingin kita akses
                A[i-1] // Implementasi pada program harus di kurangi satu (Konsep array)
        2. Dalam program ini dibutuhkan 2 function (bukan built-in tapi manual)
            1. Set() untuk menyimpan matrik ke array
            2. Get() untuk mengembalikan nilai yg sudah disimpan tadi.


*/

using namespace std;

struct Matrix{
    int A[5]; // Untuk menyimpan nilai pada diagonal matrix
    int n;
};

/*
    Function untuk menyimpan data diagonal matrix ke array A
    m sebagai pointer untuk struct m (main) 
    i dan j sebagai koordinat, dan x adalah nilai yg akan disimpan
*/
void Set(struct Matrix *m, int i, int j, int x){
    /* Simpan jika i==j */
    if(i==j){
        m->A[i - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j){
    if(i==j){
        return m.A[i - 1];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix m){
    int i, j;
    for (i = 0; i < m.n;i++){
        for (j = 0; j < m.n;j++){
            if(i==j){
                cout << m.A[i] << " ";
            }
            else{
                cout << "0 ";
            }
        }
            cout << endl;
    }
}

int main(){
    struct Matrix m;
    m.n = 4;// Ukuran matrix

    Set(&m, 1, 1, 5); // 5 adalah nilai yg akan disimpan
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);

    Display(m);
}