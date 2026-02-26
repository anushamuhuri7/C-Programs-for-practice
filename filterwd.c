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
void enqueue(Queue *q, const char *word) {
    if (q->count < MAX_WORDS) {
        q->rear = (q->rear + 1) % MAX_WORDS;
        strncpy(q->words[q->rear], word, WORD_LEN);
        q->count++;
    }
}
int isFiltered(Queue *q, const char *word) {
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX_WORDS;
        if (strcmp(q->words[index], word) == 0) {
            return 1; // Found in filter list
        }
    }
    return 0; // Not found
}
void filterText(const char *inputText, Queue *filterQueue) {
    char text[500];
    strcpy(text, inputText);
    
    char result[500] = "";
    char *token = strtok(text, " ");
    int first = 1;

    printf("Filtering text...\n");