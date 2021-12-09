/*
****************************************************
Analysis : Not Adaptif | Not stable | Perform minimum numb of swap 
Time Complexity : O(N^2)
****************************************************

*/

#include <stdio.h>

void selection_sort(int *A, int n);
void show(int *A, int n);
void swap(int *x, int *y);

int main(){
    int A[] = {3,2,7,6,9};
    int n = sizeof(A) / sizeof(int);

    selection_sort(A, n);

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void show(int *A, int n){
    int i = 0;
    while(i<n){
        printf("%d", A[i]);
        i++;
    }
}

void selection_sort(int *A, int n){
    int i, j, k;
    for(i=0;i<n;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k])
            k = j;
        }
        swap(&A[i], &A[k]);
    }
    
    show(A, n);
}