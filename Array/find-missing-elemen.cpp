/*
    1. Program : Find missing elemen - Sorted Array 
                 Mencari elemen yang hilang/tidak ada pada sorted array.
                 {1,2,3,4........12} Total(n) = 12;
        Method : 
        1. Menggunakan Formula jumlah deret 
           n(a+Un)/2
            - Ide Kunci :
                Karena jumlah elemen (mis. 12) maka seharusnya total seluruh elemen adalah penjumlahan dari 1 -> 12. yaitu 78. Tetapi kita tahu bahwa di sorted array sekarang jumlah totalnya tidak = 78, sehingga akan ketahuan ada elemen yang hilang disana.
            - Algorithm
                1. Jumlahkan satu per satu seluruh elemen
                2. Simpah hasil penjumlahan elemen tersebut ke dalam variable sum. (Sum adalah jumlah total seluruh elemen tidak termasuk elemen yg hilang).
                3. Kemudian dengan formula deret n(a+Un)/2 masukkan masing-masing komponen (nilai awal, Suku terakhir, banyak elemen) ke formula.
                4. Kurangkan hasil dari formula deret tersebut dengan sum yang sudah dihitung sebelumya, sehingga akan ketahuan elemen yang hilang.
            - Time Taken
                O(n)
    
*/

/*
   2. Program : Find missing elemen - Sorted Array 
                 Mencari elemen yang hilang/tidak ada pada sorted array.
                 {6,7,8,9........17} Total(n) = 12 ;
        Method : 
            - Ide Kunci :
                Karena setiap elemen bertambah 1 pada tiap indeks ke 0,1,2,3.. yaitu {6,7,8...} maka kita tahu bahwa beda tiap elemen adalah 1. Sehingga selisih antara elemen ke [i] dengan indeks ke [i] haruslah 6. 
                
                Ini bisa kita gunakan untuk mencari elemen yang hilang, dengan menyelisihkan nilai ke [i] - indeks ke[i] = 6, sehingga jika berbeda/tidak = 6 maka ada elemen yang hilang

            - Algorithm
                1. Buat variable diff sebagai selisih antara elemen[i] dengan indeks[i], nilainya tetap sehingga jika !diff maka break
   
*/

#include <iostream>
using namespace std;

int main(){

    // 1. Find the missing elemen - Start from {1....}
    int i,s, sum=0;
    // int a[]{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};

    // for (i = 0; i < 11;i++){
    //     sum = sum + a[i];
    // }
    // s = (12*(1 + 12)) / 2;
    // cout << "elemen yang hilang : " << s - sum;


    // 2. Find the missing elemen - Start from {6....}

    int diff;
    int b[]{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int a = b[0];
    diff = a - 0;
    for (i = 0; i < 12;i++){
        if(b[i]-i != diff){
            cout << i+diff;
            break;
        }
    }
}