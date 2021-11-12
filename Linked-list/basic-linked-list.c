#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL; //First pointer 

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        // Recursive display
        Display(p->next);
    }
}

///////////////////////////// Counter Elemen /////////////////////////////

int count(struct Node *p){
    int i, c;
    
    /* Looping method */
    
    // while(p!=0){
    //     c++;
    //     p = p->next;
    // }

    /* Recursive method  */
    // if(p==0)
    //     return 0;
    // else
    //     return count(p->next) + 1;

    /* Bentuk lain */
    int x = 0;
    if(p){
        x = count(p->next);
        return x + 1;
    }
    else
        return 0;

}

///////////////////////////// Adding Elemen /////////////////////////////
int add(struct Node *p){
    // 1. Looping method
    /*int sum=0;
    while(p){
        sum = sum + p->data;
        p = p->next;
    }
    return sum;*/

    // 2. Recursive method
    if(p)
        return add(p->next) + p->data;
    else
        return 0;
}



int main(){
    int A[] = {3, 4, 5, 6, 7};
    struct Node p;
    create(A, 5);
    Display(first);
    printf("\nBanyak elemen : %d", count(first));
    printf("\nJumlah elemen : %d", add(first));
}