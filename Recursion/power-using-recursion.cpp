/*
    ***************
    Program : Power using recursion technique
    
    Konsep :
    Kita bisa memanfaatkan teknik rekursi untuk menghitung masalah perpangkatan. Dengan mengetahui prinsip kerja rekursi yaitu 
        1. Fungsi yg memanggil dirinya (disertai parameter decreamentnya)  = (m, n-1)*m
        2. Kondisi terminasi. if(n==0)
    
    **************
*/

#include <iostream>

using namespace std;

int pow(int m, int n){
    // Pangkat 0 = 1
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return pow((m * m), n / 2);
    }
    else{
        return m * pow(m * m, (n - 1) / 2);
    }

}

int main(){
    int r;
    r = pow(2, 9);
    cout << r << endl;
}