#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct{
    int items[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s, char val) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = val;
    }
}
