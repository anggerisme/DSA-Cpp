#include <stdio.h>
#include <stdlib.h>

struct stack{
  int top;
  int size;
  int *s;
};

void push(struct stack *st, int x){
    if(st->top == st->size-1){
        printf("full");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int main()
{
    struct stack st;
    st.top = -1;
    printf("Masukkan ukuran array :");
    scanf("%d", &st.size);
    // ptr = (float*) malloc(100 * sizeof(float));
    
    st.s = (int*) malloc(st.size);
    push(&st, 18);
    printf("%d", st.s[0]);

    return 0;
}
