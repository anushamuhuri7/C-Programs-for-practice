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
void pop(Stack *s) {
    if (!isEmpty(s)) {
        s->top--;
    }
}
int calculateNestingDepth(const char *code) {
    Stack s;
    initStack(&s);
    int current_depth = 0;
    int max_depth = 0;
     for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '{') {
            push(&s, '{');
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
     }
     else if (code[i] == '}') {
            if (isEmpty(&s)) {
                printf("Error: Unbalanced braces detected!\n");
                return -1;
            }
            pop(&s);
            current_depth--;
    }
    if (!isEmpty(&s)) {
        printf("Error: Unclosed braces detected!\n");
        return -1;
    }

    return max_depth;
}
}
int main(){
    const char *sampleCode = "if(a) { while(b) { if(c) { d=1; } } }";

    printf("Code string: %s\n", sampleCode);
    
    int depth = calculateNestingDepth(sampleCode);
    
    if (depth != -1){ 
        printf("The maximum nesting depth is: %d\n", depth);
    }

    return 0;
}