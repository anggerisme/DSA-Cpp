#include <stdio.h>

int flag[100]= {-1, -1, -1, -1, -1};

int fib(int n){
    if(n<=1){
        flag[n] = n;
        return n;
    }
    else{
        if(flag[n-2]==-1)
            flag[n - 2] = fib(n-2);
        
        else if(flag[n-1]==-1)
            flag[n - 1] = fib(n-1);
        
        return flag[n-2]+flag[n-1];
    }

}

int main(){
    printf("%d", fib(4));
}
