/*
    Program : Static & Dynamic memory allocation (Stack & Heap)

    Konsep :
        Stack 
            1. Menyimpan variable sementara yg dibuat oleh function
            2. Di-inisialisasi pada saat runtime
            3. Memory dari variable akan otomatis dihapus pada saat function selesei dijalankan.
            4. Bersifat linier data structures
            5. Stack tidak dapat diresize
            6. Stack menyimpan variable dengan alamat memory yang berurutan. Inilah mengapa array yang disimpan disini tidak dapat diresize
            7. Pengaksesan lebih cepat.

        Heap
            1. Menyimpan semua variable yg berada di global (diluar function).
            2. Heap bersifat hierarchical data structure
            3. Heap dapat diresize 
            4. Heap menyimpan variable dalam urutan alamat memory yang acak.
            5. Pengaksesan relatif lebih lama
    
*/

#include <iostream>

using namespace std;

int main(){
    int *p;

    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i = 0; i < 5; i++){
        cout << p[i] << endl;
    }

    return 0;
}