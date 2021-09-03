/*
    ***************
    Program : Check if 2 strings are anagram.
    
    Ide Kunci : 
        1. Syarat anagram 1 : Memiliki jumlah karakter yang sama. (Ukuranya sama)
        2. Syarat anagram 2 ; Memiliki karakter yang sama
    
    Note :  - Tidak ada duplicate karakter
            - Hanya berlaku untuk Lower Case (26) 

    Method :

    Ide Kunci : Jika kedua karakter jumlahnya SAMA maka lakukan prosedur dibawah ini, jika keduanya TIDAK SAMA maka otomatis BUKAN anagram
    
    1. Check karakter satu per satu.
        Ide Kunci : Check karakter pada Array A, dan bandingkan satu persatu dengan karakter Array B. 
        - Lakukan perbandingan karakter B[j] pada karakter A[i], jika A[0] != B[0] maka increment B[j] sampai B[j]=A[i], 
          jika demikian maka break dan lakukan increment A[i].
        Time taken (O(n^2)) - time consumnig.

          
    2. Hash table
        Ukuran table : 26.
        - Set all value pada hash table = 0
        - Mulai lakukan scanning pada Array A[i], lakukan increment pada hash table pada indeks ke (mis). 100 (d) - 97 (a) = 3, 
          Lakukan sampai akhir Array A.
        - Lakukan hal yg sama pada Array B, Jika ditemukan karakter yang sama dengan Array A, lakukan DECREMENT. 
          sehingga nilai yg tadinya 1 menjadi 0.
        - Ide Kunci : Jika semua value pada hash table bernilai 0, maka = Anagram, sebaliknya jika ada value yg bukan 0 maka BUKAN anagram

        Time Taken = O(n)  

    **************
*/

#include <iostream>

using namespace std;

int main(){
    char A[]{"decimal"}; // Ukuran 7 byte karena type char = 1 byte
    char B[]{"medical"};

    // ------------ 1. Method 1 : Manual ------------
    /* Karena kita membandingkan satu per satu maka kita butuh 2 iterator */
    // int i, j;

    // /* Sebagai penanda/flag apakah memnuhi syarat anagram/tidak */
    // int found = 0;
    
    // int not_found = 0;

    /*
    if(sizeof(A)==sizeof(B)){
        for (i = 0; i<sizeof(A);i++){
            for (j = 0; j<sizeof(A);j++){
                found = 0;
                // Jika ditemukan maka berhenti dan lakukan increment A[i] //
                if(A[i]==B[j]){
                    found = 1;
                    break;
                }
            }
                if(found==0){
                    not_found = 1;
                    break;
                }
        }
    */

    // Jika ada indikasi 1 karakter saja yang tidak sama maka sudah dipastikan bukan anagram //
    /*  if(not_found==1){
            cout << "Bukan anagram";
        }
        else{
            cout << "Yea! string anagram!";
        }
    }
    else{
        cout << "Bukan anagram!";
    }
    */

    // ------------ 2. Method 2 : Hash table ------------
    
    int i, H[26] = {0};

    if(sizeof(A)==sizeof(B)){
        // Lakukan increment pada H indeks ke (A[i]-97) // 
        for (i = 0; A[i] != '\0';i++){
            H[(A[i] - 97)]++;
        }
        for (i = 0; B[i] != '\0';i++){
            H[(B[i] - 97)] -= 1; // Nilai H pada saat itu dikurangi 1H = H - 1
            // Jika nilai H - 1 = -1 (seharusnya 1-1=0) maka meng-indikasikan bukan anagram
            if(H[(B[i] - 97)]<0){
                cout << "Bukan Anagram!";
                // Hentikan looping karena 1 karakter saja tidak cocok maka bukan anagram, walaupun berhenti di tengah iterasi
                break;
            }
        }
                /* Jika memang benar anagram, maka harusnya proses scanning/iterasi sampai pada '\0' yg menandakan semua karakter telah di cek dan tidak ada penghentian scanning akibat ketidakcocokan karakter */ 
            if(B[i]=='\0'){
                cout << "Yeah! it's anagram";
            }
    }

    else{
        cout << "Bukan anagram!";
    }
}