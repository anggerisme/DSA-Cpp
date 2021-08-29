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

/*
   3. Program : Find missing elemen - Sorted Array 
                 Mencari BEBERAPA elemen yang hilang/tidak ada pada sorted array.
                 {6,7,8,9,11,15,16,17..} 
        Method : 
            - Ide Kunci :
                Jika selisih elemen ke[i] - beda (6) tidak sama dengan 6 maka ada indikasi elemen yang hilang disana. 

            - Algorithm
                1. Buat variable diff sebagai selisih antara elemen[i] dengan indeks[i].
                2. Buat penyaringan (if) kalau elemen ke[i] tidak sama dengan diff(6) maka tampilkan elemen itu.
   
*/

/*
   4. Program : Find missing elemen - using hash method 
                  
        Method : 
            - Ide Kunci :
                Dengan menggunakan array bantuan [B] dengan ukuran = banyaknya elemen dari array [A], Inisialisasi [B] dengan value 0, kemudian lakukan looping pada [A], nilai A[i] berperan sebagai indeks untuk [B] 
   
*/

/*
   5. Program : Find duplicate elements
                  
        Method : 
            - Ide Kunci :
                Dengan membandingkan elemen ke[i] dengan elemen ke[i+1] (next element) kita dapat mengetahui apakah elemen tersebut memiliki duplikat atau tidak. Jika ada duplikasi maka simpan duplikat itu ke dalam variable lastDuplicate. nilai lastDuplicate akan terus diperbarui seiring ditemukanya duplikasi elemen.  
            
   
*/
/*
   6. Program : Find duplicate elements using hash table + counting how many duplications occur.
                  
        Method : 
            - Ide Kunci :
                Dengan array bantuan [B] kemudian dilakukan inisialisasi semua elemenya 0, pada array A dilakukan looping dan nilainya pada saat itu A[i] akan berperan sebagai indeks pada array B.

                Menghitung berapa banyak duplikasi :
                    Lakukan perulangan jika perulangan terjadi lebih dari 1 kali maka ada indikasi terjadi duplikasi elemen
            
   
*/

#include <iostream>
using namespace std;

int main(){

    // ----- 1. Find the missing elemen - Start from {1....} -----
    int i,s, sum=0;
    // int a[]{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};

    // for (i = 0; i < 11;i++){
    //     sum = sum + a[i];
    // }
    // s = (12*(1 + 12)) / 2;
    // cout << "elemen yang hilang : " << s - sum;


    // ----- 2. Find the missing elemen - Start from {6....} ------
    
    // int diff;
    // int b[]{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    // int a = b[0];
    // diff = a - 0;
    // for (i = 0; i < 12;i++){
    //     if(b[i]-i != diff){
    //         cout << i+diff;
    //         break;
    //     }
    // }

    // ----- 3. Find the missing elements - Start from {6....} -----
    // int a[]{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    // int diff = a[0] - 0;
    // for (i = 0; i < 11;i++){
    //     if(a[i]-i !=diff){
    //         while(diff<a[i]-i){
    //             cout << i + diff << " ";
    //             diff++;
    //         }
    //     }
    // }

    // ----- 4. Find the missing element using hash method ----- 

    // int a[]{3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    // int b[12];
    // int l = 1;
    // int h = 12;
    // for (i = 0; i < 12;i++){
    //     /*
    //         Value pada saat a[i] berperan sebagai indeks pada [b], [b] yg tadinya 0 setelah looping bernilai 1. 
    //     */
    //     b[a[i]]++;
    // }
    // for (i = l; i <= h;i++){
    //     if(b[i]==0)
    //         cout << i;
    // }

    // ----- 5. Find duplicate elements -----
    // int lastDuplicate = 0;
    int A[]{3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(int);
    // for (i = 0; i < 10; i++){
    //     if(A[i]==A[i+1] && A[i]!=lastDuplicate){
    //         cout << A[i];
    //         // Update lastDuplicate
    //         lastDuplicate = A[i];
    //     }
    // }

    // How to count the duplication?
    /*
        Ide Kunci : Dengan bantuan iterator j, pada saat i=i+1 maka iterator j mulai di posisi i+1 kemudian increment dan bandingkan apakah nilai j = i, lakukan sampai j != i. Maka dengan begitu kita tahu ada berapa duplikat elemen disana dengan mengurangkan indeks j - indeks i pada saat itu. Setelah tidak terjadi duplikasi lagi maka interator i melakukan increament lagi.
    */

    // for (i = 0; i < 11;i++){
    //     if(A[i]==A[i+1]){
    //         int j = i + 1;
    //         while(A[j]==A[i])
    //             j++;
    //         cout << "Elemen " << A[i] << " muncul " << j - i << " kali" << endl;

    //         i = j - 1;
    //     }
    // }

    // ----- 6. Find duplicate elemen using hash table -----

    int B[20]{0};
    for (i = 0; i < n;i++){
        /*
            Setiap nilai dari A akan menjadi indeks pada B yang akan meng-increment nilainya tergantung dari seberapa sering elemen A itu muncul.
        */
        B[A[i]]++;
    }
    for (i = 0; i < 20;i++){
        if(B[i]>1){
            cout << "Element " << i << " muncul " << B[i] << " kali" << endl;
            
        }
    }
}