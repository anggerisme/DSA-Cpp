#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void show(struct Node *p){
    int i = 0;
    while(p){
    printf("%c - ", p->data);
    p = p->next;
    }
}

void push(char x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack overflow");
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    struct Node *p;
    char x = -1;

    if(p==NULL)
        printf("stack overflow");
    else{
        // while(top) --> use while if you want delete all elemen
        p = top;
        top = top->next;
        x = p->data;
        free(p);
        
    }
    return x;
}

int is_Balance(char *exp){
    int i;
    for (i = 0; i < exp[i] != '\0';i++){
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    return 0;
}

int main(){
    char *A;
    A = "((a+b)*(c+d))";

    printf("%d",is_Balance(A));
}