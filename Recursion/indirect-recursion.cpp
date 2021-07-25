/*
    ***************
    Program : Indirect recursion
    
    Konsep :
    Recursion yang suatu function (A) di dalamnya memanggil function yang lain (B), kemudian function (B) memanggil function (C) dan kembali lagi function (C) memanggil function (A).

    Cara Kerja :
    Ketika fun(20) dikirimkan kemudian akan melewati pengkondisian, karena 20 > 0 maka akan 
    di tempilkan 20 kemudian memanggil fun B (20-1), sehingga nilai n sekarang 19. 19 ini menjadi nilai yg akan diproses oleh function B. 
    
    Function B akan menampilkan nilai n kemudian memanggil function A (19/2) - (Function awal) sehingga nilai n sekarang 9. 9 adalah nilai yang akan diproses oleh function A untuk di oleh seperti proses sebelumnya

    **************
*/

#include <iostream>

using namespace std;

void fun_B(int n);
void fun_A(int n){
    if(n>0){
        cout << n << endl;
        fun_B(n - 1);
    }
} 

void fun_B(int n){
    if(n>1){
        cout << n << endl;
        fun_A(n / 2);
    }
}

int main(){
    fun_A(20);
}