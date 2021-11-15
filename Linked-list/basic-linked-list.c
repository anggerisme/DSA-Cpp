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

///////////////////////////// 1. Counter Elemen /////////////////////////////

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

///////////////////////////// 2. Adding Elemen /////////////////////////////
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
///////////////////////////// 3. Find Max Element /////////////////////////////

int max(struct Node *p){
    int min=2;
    int x;
    /*
        Selama data lebih besar dari M, simpan nilai data ke M
        loop selama p != NULL
    
    */
    // 1. Looping method
    /* while(p){
        if(p->data>min)
            min = p->data;
            
        p = p->next;
    }
    return min; */
    
    // 2. Recursive method
    if(p==NULL)
        return min;
        
    x = max(p->next);
    return x>p->data?x:p->data;
    
}

///////////////////////////// 4. Find Min Element /////////////////////////////
int min(struct Node *p){
    int min;
    min = p->data;
    // printf("\n\n%d", x);
    while(p!=0){
        if(min>p->data){
            min = p->data;
            return min;
        }
        p = p->next;
    }
}

///////////////////////////// 5. Searching Element /////////////////////////////
struct Node *search(struct Node *p, int key){
    // 1. Looping method
    struct Node *q;
    while(p!=NULL){
        if(key==p->data){
            /* Bring the elemen to the forefront*/
            q->next = p->next;
            p->next = first;
            first = p;
            return (p);
        }
        q = p;
        p = p->next;
    }
    return NULL;


    // 2. Recursive method
    // if(p==NULL)
    //     return NULL;
    // if(key==p->data)
    //     return p;
    // return search(p->next, key); 

}

///////////////////////////// 6. Inserting Element /////////////////////////////
int insert(int pos, int x){
    struct Node *t, *p;
    int i = 0;
    if(pos==0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos>0){
        p = first;
        for (; i < pos - 1 && p;i++)
            p = p->next;
        if(p){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}


int main(){
    int A[] = {3, 4, 2, 6, 7};
    struct Node *p;
    create(A, 5);
    // printf("\nBanyak elemen : %d", count(first));
    // printf("\nJumlah elemen : %d", add(first));
    // printf("\nMax elemen : %d", max(first));5
    // printf("\nMin elemen : %d", min(first));
    // printf("\nElemen ditemukan : %d", search(first, 7));
    // min(first);

    /* p = search(first, 7);
    if(p!=0)
        printf("Elemen ditemukan : %d", p->data);
    else
        printf("Elemen tidak ditemukan!"); */
    insert(4, 9);
    Display(first);
}