#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[] = {1, 2, 3, 4, 5};
    int i, *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    // printf("%d", sizeof(p));
    q = (int *)malloc(10 * sizeof(int));
    for (i = 0; i<5;i++){
        p[i] = A[i];
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;
    for (i = 0; i<5;i++){
        printf("%d", p[i]);
        // printf("%d", q[i]);
    }

}