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
    push(&st, 4);
    printf("%d", pop(&st));
    // printf("%d", st.s[0]);

    return 0;
}
