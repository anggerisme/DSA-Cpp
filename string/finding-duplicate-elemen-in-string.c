#include <stdio.h>

int main(){
    char A[] = "findingsss";
    /*
        int = 4 bytes * 8 bits = 32 bits. Ada sebanyak 32 bits cukup untuk menampung sampai huruf z, 122-97 = 25 bits 
    */
    int h=0;
    int x=0;
    int i;
    
    for(i=0;A[i]!='\0';i++){
        x = 1; // 00000000 00000000 00000000 00000001
        /*
            Misal : A[i] sekarang = 'f' (102-97=5) maka x akan bergeser sebanyak 5 bits ke arah kiri. 
            00000000 00000000 00000000 00100000
            kemudian akan mengecheck apakah pada bit h poisisi 5 menunjukkan 1 atau 0, 
            dengan teknik masking kita tahu hasilnya
        */
        x = x << (A[i]-97); 
        /* Masking : check apakah nilai pada h 
        menunjukkan angka 1 (on) atau 0 (off), Jika >0 maka dikatakan
        ada duplikasi elemen disana*/
        if((x&h)>0){
            printf("duplicate elemen %c\n", A[i]);
        }
        /* Merging : meng-set/mengaktifkan bit pada h
        menjadi 1 (on)/increment. Ini sebagai penanda bahwa elemen
        tersebut sudah dicatat
        */
        else
           h =  x|h;
            
    }
}