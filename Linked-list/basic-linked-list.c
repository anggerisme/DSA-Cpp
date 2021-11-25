#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second=NULL, *third=NULL;

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

void create2(int A[], int n){
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
///////////////////////////// 0. Display Elemen /////////////////////////////
void Display(struct Node *p){
    /////// using if ///////////
    // if(p!=NULL){
    //     printf("%d ", p->data);
    //     // Recursive display
    //     Display(p->next);
    // }

    /////// while ///////////
    while(p!=0){
        printf("%d ", p->data);
        p = p->next;
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
    int x;
    int min = 0;
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
        // else : move q to the next node (p) and p to the next node
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

///////////////////////////// 6. Inserting at last /////////////////////////////
void insert_last(int x){
    //// 1. Create node for t ////
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first==NULL){
        first = last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

///////////////////////////// 7. Inserting at sorted linked list /////////////////////////////
void insert_sorted(int x){
    //// 1. Create node for t ////
    struct Node *q, *p, *t;
    q = p = first;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    //// 2. Traversing the node using p & q ////
    while(p&&p->data<x){
        q=p;
        p = p->next;
    }

    //// 3. Ubah structure node ////
    t->next = q->next;
    q->next = t;
}

///////////////////////////// 8. Deleting node /////////////////////////////
int delete(struct Node *p,int pos){
    struct Node *q;
    int i,x=-1;
    // Ada 3 kemungkinan posisi yang harus di check
    if(pos<1||pos>count(p))
        return -1;
    if(pos==1){
        q = first;
        x = first->data;
        first = first->next;
        free(p);
        return x;
    }
    else{
        for (i = 0; i < pos-1;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

}
///////////////////////////// 9. Check sorted or not /////////////////////////////
int check_sorted(struct Node *p){
    int x = -32768;
    while(p!=NULL){
        if(p->data<x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

///////////////////////////// 10. Remove duplicate node (Sorted Linked list) /////////////////////////////
void remove_duplicate(struct Node *q){
    struct Node *p=q->next;
    while(p!=NULL){
        if(q->data!=p->data){
            q = p;
            p = p->next;
        }
        else{
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }

}

///////////////////////////// 11. Remove duplicate node (Unsorted Linked list) /////////////////////////////
// void remove_unsorted(struct Node *p){
//     struct Node *q;
//     int H[max(first)];
//     int i;
//     for(i = 0; i < max(first);i++)
//         H[i] = 0;
//     for (i = 0;i<max(first);i++)
//         H[p->data]++;
//     while(p!=NULL){
//         if()
//     }
// }

///////////////////////////// 12. Reverse linked list /////////////////////////////
void reverse(struct Node *q, struct Node *p){
    //////// 1. Metode reverse elemen //////////
    /* int i=0;
    int H[count(p)];
    while(p){
        H[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while(p){
        p->data = H[i--];
        p = p->next;   
    } */

    //////// 2. Metode reverse link //////////
    /* struct Node *q, *r;
    while(p){
        r = q;
        q = p;
        p=p->next;
        q->next = r;
    }
    first = q; */

    //////// 3. Metode recursive //////////
    if(p){
        reverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

///////////////////////////// 13. Merge 2 sorted Array /////////////////////////////
void merge(struct Node *f, struct Node *s){
    struct Node *last;
    if(f->data<s->data){
        third = last = f;
        f = f->next;
        third->next = NULL;
    }
    else{
        third = last = s;
        s = s->next;
        third->next = NULL;
    }
    while(f && s){
        if(f->data<s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else{
            last->next = s;
            last = s;
            s=s->next;
            last->next = NULL;
        }
    }
    if(f)
        last->next = f;
    if(s)
        last->next = s;
}

int main(){
    int A[] = {10, 7, 30, 40, 50};
    int B[] = {5, 6, 252, 352, 452};
    struct Node *p;
    create(A, 5);
    create2(B, 5);

    // Display(first);
    // printf("\n");
    // Display(second);
    merge(first, second);
    printf("\n\nMerge list : ");
    Display(third);
}