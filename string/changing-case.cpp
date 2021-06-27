#include <iostream>
#include <string>
#include <array>

using namespace std;

/*
    ***************
    Program : Convert uppercase to lowercase and so forth
    
    Method :
    
    1. Manual 
        just add 32 for uppercase to lowercase or subtract it 32 for oppsite
    2. Built-in function
        1. toupper
        2. tolower


    **************
*/

// int main(){
    
//     char A[] = "ANGGER";
//     cout << A << endl; // ANGGER
//     int i;
//     for (i = 0; A[i] != '\0';i++){
//         A[i] = A[i] + 32; // The Logic here
//     }
//     cout << A << endl; // angger
// }

// --------- Built in function ---------

// int main(){
//     char A[] = "angger";
//     char B[30];
//     int i;
//     for (i = 0; A[i] != '\0';i++){
//         B[i] = toupper(A[i]);
//     }
//     cout << A;
//     cout << B;
// }

/*
    ***************
    Program : Convert if there are uppercase to lowercase and so forth (with condition)
     
    Metode
         1. Manual
         Karena uppercase < lowercase (scr urutan ascii) yaitu berada di interval 65<=A<=90 maka itu berarti UPPERCASE.
         2. Built-in function
            1. tolower
            2. toupper

    **************
*/

// ---------- Manual ------------

// int main(){
    
//     char A[] = "AnggeR";
//     cout << A << endl; // ANGGER
//     int i;
//     for (i = 0; A[i] != '\0';i++){
//         // bisa ditulis menggunakan nomer
//         // if(A[i]>='65' && A[i]<='90') 
//         if(A[i]>='A' && A[i]<='Z'){
//             A[i] += 32; // A sekarang + 32
//         }
//         else if(A[i]>=97 && A[i]<=122){ 
//             A[i] -= 32;
//         }
//     }
//     cout << A << endl; // angger
// }

// -------------- Built in function ------------

int main(){
    
    char A[] = "AnggeR";
    int i;
    for (i = 0; A[i] != '\0';i++){
        // bisa ditulis menggunakan nomer
        // if(A[i]>='65' && A[i]<='90') 
        if(A[i]>='A' && A[i]<='Z'){
            A[i] = tolower(A[i]); // A sekarang + 32
        }
        else if(A[i]>=97 && A[i]<=122){
            A[i] = toupper(A[i]);
        }
    }
    cout << A << endl; // angger
}