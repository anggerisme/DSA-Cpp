#include <iostream>
#include <cstring>

using namespace std;

/*
    ***************
    Program : Mencari length/panjang string
    Length : Number of character except null

    Metode
    1. Built-in function
        1. length() - <cstring> -> more readable, more intuitive
        2. size() -> to be consistent with other stl container.

    2. Using for or while loop
    **************
*/

int main(){
    char *s = "welcome";
    string si = "welcome";
    // cout << size;
    // -------- Built-in function -----------
    cout << "Length : " << si.length() << endl;
    cout << "Size : " << si.size() << endl;
    
    // -------- For Loop or while ---------
    int i;
    for(i=0; s[i]!='\0'; i++){
        
    }
    cout << i << endl;
    while(s[i]!=0){

    }
    cout << i << endl;
    
    cout << s << endl;
}