/*
    ***************
    Program : Membuat permutation dari sebuah string.
    
    Ide Kunci : 
        1. Huruf 
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

void perm(char s[], int k){
  /*
    Keyword static : Setelah variable diinisialisasi maka nilainya akan terjaga sampai akhir program
  */
  static char A[10]{0}; // Penanda/flag
  static char res[10]; // Untuk menampung hasil

  /*
    Kondisi 1 : Jika s[k] mencapai null artinya karakter sudah di scan seluruhnya
  */
  if(s[k]=='\0'){
    res[k] = '\0'; // Karena char butuh null character maka selalu tambahkan null di akhir string
    cout << res <<", ";
  }

  /*
    Kondisi 2 : Jika s[k] belum mencapai null char maka jalankan program di bawah
  */
  else{
    for (int i = 0; s[i]!='\0';i++){
      /* Artinya : Selama penanda(flag) A masih tersedia (0) maka copy char s ke res pada posisi iterator saat itu*/
      if(A[i]==0){
        /* Copy char s ke res*/
        res[k] = s[i];
        /* Setelah di copy, tandai posisi S (yg diwakili oleh A) bahwa char S posisi i telah di copy */
        A[i] = 1;
        /* setelah res menerima copyy-an dari s selanjutnya lakukan pemanggilan lagi dengan k+1*/
        perm(s, k + 1);
        /* Jangan lupa untuk mengubah penanda A yg tadinya 1 menjadi 0 sebelum melakukan incerement lagi */
        A[i] = 0;
      }
    }
  }

}

int main(){
  char s[10] = "ABCD";
  perm(s, 0);
}

