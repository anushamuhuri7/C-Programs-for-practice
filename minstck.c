#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 1000
typedef struct {
    int data[MAX_SIZE];
    int min_data[MAX_SIZE];
    int top_index;
} MinStack;
void minStackCreate(MinStack* obj) {
    obj->top_index = -1;
}
void minStackPush(MinStack* obj, int x) {
    if (obj->top_index >= MAX_SIZE - 1) {
        return;
    }
}