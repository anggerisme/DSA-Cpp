#include <stdio.h>
#include <stdlib.h>

struct stack{
  int top;
  int size;
  int *s;
};

//////////////// 1. Pushing elemen //////////////////

void push(struct stack *st, int x){
    if(st->top == st->size-1){
        printf("full");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

//////////////// 2. Deleting elemen //////////////////

int pop(struct stack *st){
    int x = -1;
    if(st->top==-1){
        printf("Stack is underflow");
    }
    else{
        x = st->s[st->top--];
        // st->top--;
    }
    return x;
}

//////////////// 3. Peek elemen //////////////////
int peek(struct stack st, int pos){
    int x = -1;
    if(st.top-pos+1<0)
        printf("Invalid position");
    else
        x = st.s[st.top-pos + 1];
    return x;
}

//////////////// 4. Stack is full //////////////////
void stackFull(struct stack st){
    if(st.top==st.size-1||st.top>st.size-1){
        printf("Stack is full\n");
        printf("Posisi stack teratas telah terisi oleh %d.\nKurang : %d slot\n", st.s[st.top], -1*(st.s[st.top]-(st.size-1)));
    }
    else
        printf("Posisi stack teratas telah terisi oleh %d.\nMasih tersedia %d slot\n", st.s[st.top], (st.size-1)-st.top);
}

//////////////// 5. Stack is empty //////////////////
void empty(struct stack st){
    int x = -1;
    if(st.top==-1){
        printf("Stack kosong");
    }
}

//////////////// 6. Stack Top //////////////////
void Top(struct stack st){
    int x = -1;
    if(st.top==-1){
        printf("Stack kosong");
    }
    else
        printf("Posisi stack teratas telah terisi oleh %d", st.s[st.top]);
}


int main()
{
    struct stack st;
    st.top = -1;
    printf("Masukkan ukuran array :");
    scanf("%d", &st.size);

    st.s = (int*) malloc(st.size);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 3);
    push(&st, 3);
    push(&st, 9);
    printf("%d\n", st.top);
    stackFull(st);
    empty(st);
    Top(st);
    // printf("%d\n", peek(st,1));
    // printf("%d", pop(&st));
    // printf("%d", st.s[0]);

    return 0;
}
