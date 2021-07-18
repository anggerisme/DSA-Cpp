#include <iostream>

using namespace std;

/*
    ***************
    Program : Static in recursion function
    
    Konsep :
    
    Static merupakan keyword untuk menjaga nilai dari suatu variable tetap ada meskipun
    suatu function telah berhenti dikerjakan. Ini dikarenakan static disimpan di dalam code section
    bukan di stack. Sama seperti global variable. Masa hidupnya (lifetime) mengikuti suatu program secara keseluruhan, jika
    program berhenti maka static/global variable juga akan selesei atau hancur. 

    **************
*/

int fun(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main(){
    int r;
    r = fun(5);
    cout << r;

    return 0;
}