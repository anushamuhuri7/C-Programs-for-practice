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