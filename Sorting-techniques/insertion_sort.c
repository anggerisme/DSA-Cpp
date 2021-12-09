#include <stdio.h>

void show(int *A, int n);
void insertion_sort(int *A, int n);

int main(){
    int A[] = {2,3,5,7,8};
    int n = sizeof(A) / sizeof(int);

    insertion_sort(A, n);

}

void show(int *A, int n){
    int i = 0;
    while(i<n){
        printf("%d", A[i]);
        i++;
    }
}

void insertion_sort(int *A, int n){
    int i, j, x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1&&A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    
    show(A, n);
}