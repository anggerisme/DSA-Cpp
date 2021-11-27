#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int top;
    int *s;
}stack;

////////////////////////// 1. display stack //////////////////////////
void show(stack st){
    for(int i = st.size-1; i >= 0;i--)
        printf("%d\n", st.s[i]);
}   

////////////////////////// 2. push() //////////////////////////
void push(stack *st, int x){
    if(st->top==st->size-1)
        printf("Stack overflow");
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

////////////////////////// 3. pop() //////////////////////////
int pop(stack *st, int pos){
    int x = -1;
    if(st->top==-1)
        printf("stack is empty");
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
////////////////////////// 4. peek() //////////////////////////
int peek(stack st, int pos){
    int x = -1;
    if(st.top-pos+1<0)
        printf("invalid position");
    else
        x = st.s[st.top-pos+1];
    return x;
}

////////////////////////// Stack using linked list //////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct node{
    int data;
    struct node *next;
}*top = NULL;

////////////////////////// 1. push_node() //////////////////////////
void show_node(struct node *p){
    while(p){
        printf("%d - ", p->data);
        p = p->next;
    }
}

////////////////////////// 2. push_node() //////////////////////////
void push_node(int x, stack st){
    struct node *t;
    t = (struct node *)malloc(st.size);
    if(t==NULL)
        printf("stack overflow");
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

////////////////////////// 3. peek() //////////////////////////
int peek_node(int pos){
    int i;
    struct node *t;
    t = top;
    
    for (i = 0; t != 0 && i < pos - 1;i++)
        t = t->next;
    if(t)
        return t->data;
    else
        return -1;
    
}

int main(){
    stack st;
    st.size = 5;
    st.s = (int*)malloc(st.size);
    st.top = -1;
    push(&st, 10); // 5
    push(&st, 15); // 4
    push(&st, 8); // 3
    push(&st, 20); // 2
    push(&st, 1); // 1

    /////////// stack using linked list /////////
    push_node(10, st); // 4
    push_node(15, st); // 3
    push_node(18, st); // 2
    push_node(20, st); // 1 - last in become first node
    // show_node(top);
    printf("%d", peek_node(4));
}