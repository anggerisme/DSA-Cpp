#include <iostream>

using namespace std;

/*
    ***************
    Program : Recursion function
    
    Konsep :
    Function yg memanggil dirinya sendiri. Sedangkan function yg memuat rekursi disebut recursive function. 
    
    2 urutan :
        1. rekursif function -> print
        2. print -> rekursif function
    


    **************
*/

// --------- Rekursif function -> print ---------
/*
    Function akan dikerjakan/dipanggil sampai habis baru kemudian kembali lagi dan menampilkan value-nya
*/
int fun_1(int n){
    if(n>0){
        fun_1(n - 1);
        cout << "Urutan ke "<< n << endl;
    }
}

// --------- print -> rekursif function ---------
/*
    Function akan dikerjakan/dipanggil setelah menampilkan value. Step by step.
*/
int fun_2(int n){
    if(n>0){
        cout << "Urutan ke "<< n << endl;
        fun_2(n - 1);
    }
}

int main(){
    int x = 3;
    fun_1(x);
    fun_2(x);
}
