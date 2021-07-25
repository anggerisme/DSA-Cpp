/*
    ***************
    Program : Nested recursion
    
    Konsep :
    Function Recursive yg di dalam parameternuya adalah dirinya sendiri yg berarti recursion di dalam recursion. 

    Cara Kerja :
    Ketika fun(95) dikirimkan kemudian akan melewati pengkondisian, karena 95 < 100 maka akan masuk ke else yang kemudian memproses 95 + 11 untuk dikirimkan lagi ke function fun(). Begitu dan seterusnya.
    

    **************
*/

#include <iostream>

using namespace std;

int fun(int n){
    if(n>100)
        return n - 10;


    return fun(fun(n + 11));
} 

int main(){
    int r;
    r = fun(95); 
    cout << r << endl;
}