#include <iostream>

using namespace std;

/*
    ***************
    Program : Reverse string - membalik karakter.
    
    Method :
    
    1. Reverse copying string  
        Menggunakan 2 iterator untuk saling mengambil-menyimpan value dari indeks array yang dilalui keduanya.
    2. Swapping position of character in one string
        Menggunakan 2 iterator dari dua arrah, (depan - belakang, belakang- depan). Menggunakan metode swapping.


    **************
*/


/*
    ***************
    Method : 1. Reverse copying string
    **************
*/
/* void reverse_string(char A[]){
    char B[10];
    int i, j;
    
    // 1. Iterator i diletakkan di akhir string untuk memulai pembalikan string.
    
    for (i = 0; A[i] != '\0';i++){} // Kosongkan saja karena loop ini hanya untuk ke karakter terakhir dari string saja.
    i = i - 1; // Penghitungan dimulai dari i-1 karena akhir string tentu saja null character.

    // 2. Iterator J berperan untuk menangkap value yang di kirim oleh iterator i.
    
    for (j = 0; i >= 0; i--, j++){
            B[j] = A[i];
        }
    B[j] = '\0';
    
    cout << B << endl;
} 

*/

/*
    ***************
    Method : 2. Swapping character
    **************
*/

void reverse_string(char A[]){
    int i, j, t;

    for (j = 0; A[j] != '\0';j++){}
    j = j - 1; // Tidak menyertakan null character

    for (i = 0; i < j; i++, j--){ // Bergerak maju (i--) dan mundur (j--)
        /*
            Nilai iterator A[i] saat ini disimpan di dalam var. t (temporary) untuk 
            kemudian nilai A[i] diisi dengan nilai A[j] dan terakhir nilai A[j] itu sendiri
            diisi dengan nilai t yang memuat nilai A[i] tadi diawal. 
        */
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    cout << A << endl;
}

int main(){
    char A[] = "Angger";
    reverse_string(A);
}