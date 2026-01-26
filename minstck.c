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
     obj->top_index++;
    obj->data[obj->top_index] = x;
    
    if (obj->top_index == 0) {
        obj->min_data[obj->top_index] = x;
    } else {
        int current_min = obj->min_data[obj->top_index - 1];
        obj->min_data[obj->top_index] = (x < current_min) ? x : current_min;
    }
}