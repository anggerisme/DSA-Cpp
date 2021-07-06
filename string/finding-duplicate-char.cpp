#include <iostream>

using namespace std;

int main(){
    char A[] = "angeer";
    int i;
    int H[26];

    for (i = 0; A[i] != '\0'; i++){
        /*
            Setiap kali character yg ter-iterasi akan di kurangi 97 
            sehingga diketahui indeksnya pada saat itu (ter-iterasi). Sehingga selanjutnya akan diberi kan
            nilai 1. Dan akhirnya ketahuan berapa kali penambahan nilai 1 ini dilakukan pada tiap-tiap 
            karakter. Yang double akan bertambah banyak tentunya sejumlah karakter tersebut muncul dalam perulangan.
        */
        H[A[i]-97] += 1; // += Operator yg mengisikan nilai 1 ke variable H[i]; untuk setiap perulangan.
    }

    // for(int j : H){
    //     if(H[j]>1){
    //     cout << H[j] << endl;
    //     }
    // }

    for (i = 0; i<26 ;i++){

    if(H[i]>1){
        printf("%c", i + 97);
        cout << endl;

        printf("%d", H[i]);
    }
    }
    
}
