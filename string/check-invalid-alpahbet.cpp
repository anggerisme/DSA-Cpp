#include <iostream>
#include <regex>

using namespace std;

/*
    ***************
    Program : Find special characters (non-alphabet).
    
    Method :
    
    1. Manual 
        Menggunakan tabel ascii character sehingga string yang dimasukkan apabila tidak memenuhi syarat (A[i]>=65 && A[i]<=90) && !(A[i]>=97 && A[i]<=122) 
        Maka invalid. Mengembalikan nilai false (return 0)
    2. Regex
        Buat objek regex yang memuat special character (selain alfabet).
    
    **************
*/

/* 

    **************
    1. Manual

int check(char A[]){
    int i;
    for (i = 0; A[i] != '\0';i++){
        if(!(A[i]>=65 && A[i]<=90) && !(A[i]>=97 && A[i]<=122)){

            return 0; 
        }
        return 1;
    }
}
    **************
*/

/*
    **************
    2. Regex


*/

int check(char A[]){
    /*
        spec_char adalah objek dari regex.
    */
    regex spec_char("[@_!#$%^&*()<>?/|}{~:]");

/*
    Jika string pada A cocok dengan spec_char (yg disimpan dalam regex)
*/
    if(regex_search(A, spec_char)==0)
        cout << "String accepted!";
    else{
        cout << "String not accepted!";
    }
}

int main(){
    char A[]{};
    cin.getline(A, 100);
    check(A);
}