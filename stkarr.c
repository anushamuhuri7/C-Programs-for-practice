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
