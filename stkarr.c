#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int *next;
    int *top;
    int free_top;
    int capacity;
    int num_stacks;
} MultiStack;


void push(MultiStack* ms, int val, int sn) {
    if (sn < 0 || sn >= ms->num_stacks) {
        printf("Invalid stack number!\n");
        return;
    }
    if (is_full(ms)) {
        printf("Stack Overflow: No space left in the shared array!\n");
        return;
    }

    int i = ms->free_top;
    ms->free_top = ms->next[i];
    ms->next[i] = ms->top[sn];
    ms->top[sn] = i;
    ms->data[i] = val;

    printf("Pushed %d to Stack %d\n", val, sn);
}