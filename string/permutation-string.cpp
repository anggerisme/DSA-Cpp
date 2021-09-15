/*
    ***************
    Program : Membuat permutation dari sebuah string.
    
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

