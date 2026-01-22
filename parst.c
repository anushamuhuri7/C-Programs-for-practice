#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 100
bool match(char c1, char c2) {
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '{' && c2 == '}') return true;
    if (c1 == '[' && c2 == ']') return true;
    return false;
}
bool bln(char *expr){
    char stack[MAX];
    int top=-1;
 for (int i = 0; i < strlen(expr); i++) {
        char curr = expr[i];

        if (curr == '{' || curr == '(' || curr == '[') {
            if (top >= MAX - 1) return false; 
            stack[++top] = curr;
        }
        else if (curr == '}' || curr == ')' || curr == ']') {
            if (top == -1 || !match(stack[top], curr)) {
                return false;
            }
            top--;
        }
    }
    return (top == -1);
}
int main(){
    char in1[MAX];
    char in2[MAX];
    printf("Enter first sequence of brackets (don't close a bracket before it is opened): ");
    scanf("%s", in1);
    printf("Enter second sequence of brackets (don't close a bracket before it is opened): ");
    scanf("%s", in2);
    printf("Testing 1st one: \n");
    if(bln(in1)){
        printf("Output: Balanced\n");
    }
    else{
        printf("Output: Unbalanced\n");
    }
    printf("Testing 2nd one: \n");
    if(bln(in2)){
        printf("Output: Balanced\n");
    }
    else{
        printf("Output: Unbalanced\n");
    }
    return 0;
}