#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_LEN 30
typedef struct {
    char words[MAX_WORDS][WORD_LEN];
    int front;
    int rear;
    int count;
} Queue;
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}