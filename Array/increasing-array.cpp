/*
    Program : Increaseing array

    Konsep :
        Note : Hanya dapat dimungkinkan apabila array disimpan di dalam heap. 

        idenya adalah dengan membuat array baru (q) sehingga elemen yang ada di array lama (p)
        dapat dipindahkan ke array yang baru. 

    Algorithm :
        1. Buat pointer p, kemudian buat array p di dalam heap dengan operator new, isikan elemen - elemen ke dalamnya.
        2. Buat pointer q, buat array p di dalam heap, biarkan kosong sementara.
        3. Pindahkan semua elemen p ke q.
        4. Hapus memory p di dalam heap.
        5. Buat p pointing to q. sehingga p memiliki alamat memory yang sama dengan q.
        6. Buat q pointing to NULL.


*/

#include <iostream>

using namespace std;

int main(){
    int *p;
    int *q;

    p = new int[5];
    q = new int[10];

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i = 0; i < 5; i++){
        q[i] = p[i];

    }
    delete p;

    p = q; // p dan q mempunyai alamat memory yang sama, sehingga p dapat mengambil alih q
    cout << p << endl;
    cout << q << endl;
    q = NULL; // q tidak dapat digunakan sekarang.

    for (int i = 0; i < 5; i++){
        cout << p[i] << endl;
    }
}