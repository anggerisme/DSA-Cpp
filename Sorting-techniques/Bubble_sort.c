#include <stdio.h>

void Bubble_sort(int *A, int n);
void show(int *A, int n);
void swap(int *x, int *y);

int main(){
    int A[] = {2,3,5,7,8};
    int n = sizeof(A) / sizeof(int);

    Bubble_sort(A, n);

}

void show(int *A, int n){
    int i = 0;
    while(i<n){
        printf("%d", A[i]);
        i++;
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_sort(int *A, int n){
    int i,j, flag=0;
    for (i = 0; i < n - 1;i++){
        // Comparation loop
        for (j = 0; j < n - 1 - i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        // Jika pada komparasi pertama swap = 0 maka elemen telah terurut
        if(flag==0){
            printf("Elemen sorted!");
            break;
        }
    }

    show(A, n);
}