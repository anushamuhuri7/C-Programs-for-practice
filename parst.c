#include<stdio.h>
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
        char current = expr[i];

        if (current == '{' || current == '(' || current == '[') {
            if (top >= MAX - 1) return false; 
            stack[++top] = current;
        }
        else if (current == '}' || current == ')' || current == ']') {
            if (top == -1 || !is_matching_pair(stack[top], current)) {
                return false;
            }
            top--;
        }
    }
}