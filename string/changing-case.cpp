#include <iostream>
#include <string>

using namespace std;

/*
    ***************
    Program : Convert uppercase to lowercase and so forth
     
    Logic = just add 32 for uppercase to lowercase or subtract it 32 for oppsite

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


/*
    ***************
    Program : Convert if there are uppercase to lowercase and so forth (with condition)
     
    Logic = Karena uppercase < lowercase (scr urutan ascii) yaitu berada di interval 65<=A<=90 maka itu berarti UPPERCASE.

    **************
*/

int main(){
    
    char A[] = "AnggeR";
    cout << A << endl; // ANGGER
    int i;
    for (i = 0; A[i] != '\0';i++){
        // bisa ditulis menggunakan nomer
        // if(A[i]>='65' && A[i]<='90') 
        if(A[i]>='A' && A[i]<='Z'){
            A[i] += 32; // A sekarang + 32
        }
        else if(A[i]>=97 && A[i]<=122){ 
            A[i] -= 32;
        }
    }
    cout << A << endl; // angger
}