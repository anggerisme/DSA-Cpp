#include <stdio.h>

int flag[10];

int fib(int n){
    if(n<=1){
        flag[n] = n;
        return n;
    }
    else{
        if(flag[n-2]==-1)
            flag[n - 2] = fib(n-2);
        
        if(flag[n-1]==-1)
            flag[n - 1] = fib(n-1);
        
        return flag[n-2]+flag[n-1];
    }

}

int main(){
    for (int i = 0; i < 10;i++){
        flag[i] = -1;
    }
        printf("%d", fib(6));
}
