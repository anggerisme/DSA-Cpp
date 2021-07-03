#include <iostream>

using namespace std;

/*
    ***************
    Program : Compare 2 string - Mengandung pengulangan karakter.
    
    Method :
    
        1. Checking manual
            Menggunakan 2 iterator jika value/nilai di indeks yang 
            sedang di iterasi tidak sama maka perulangan berhenti dan menyisakan 
            karakter terakhir kali di duduki oleh kedua iterator.     


    **************
*/

void compare(char A[], char B[]){
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0';i++,j++){
        if(A[i]!=B[j]){
            /*
                Ketika A[i] != B[j] maka perulangan berhenti
                sehingga nilai A[i] dan B[j] yang terhenti akan
                digunakan sebagai conditions untuk pengkondisian setelahnya
            */
            break;
        }
    }
    if(A[i]==B[j])
        cout << "equal";
    else if(A[i]>B[j]){
        cout << "A lebih besar dari B";
    }
    else if(A[i]<B[j])
        cout << "A lebih kecil dari B";
}

int main(){
    char A[] = "Angkkgger";
    char B[] = "Angger";
    compare(A, B);

}