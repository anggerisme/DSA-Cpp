/*
    ***************
    Program : Tower of Hanoi
    
    Konsep :
    Problem dalam kasus Tower of hanoi dapat kita pecahkan dengan menggunakan teknik rekursi. Jadi ketika ada sejumlah n yang ingin kita pindahkan dari A ke C maka kita perlu tempat penyimpanan sementara (B) sebelum pada akhirnya memindahkan semua elemen A ke C.  


    **************
*/

#include <iostream>

using namespace std;

void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n - 1, A, C, B);
        cout << "Move " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
}

int main(){
    TOH(3, 1, 2, 3);
    return 0;
}