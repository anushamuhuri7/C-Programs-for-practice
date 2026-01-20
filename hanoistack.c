#include <stdio.h>
typedef struct {
    int disks[7];
    int top;
    char name;
} Stack;
void push(Stack *s, int disk) {
    s->disks[++(s->top)] = disk;
}
int pop(Stack *s) {
    return s->disks[(s->top)--];
}
void display(Stack *a, Stack *b, Stack *c) {
    Stack* p[3] = {a, b, c};
    for(int i = 0; i < 3; i++) {
        printf("%c: ", p[i]->name);
        for(int j = 0; j <= p[i]->top; j++) printf("%d ", p[i]->disks[j]);
        printf("\n");
    }
    printf("----\n");
}

int main() {
    Stack sA = {{0}, -1, 'A'}, sB = {{0}, -1, 'B'}, sC = {{0}, -1, 'C'};
    
    for (int i = 7; i >= 1; i--) push(&sA, i);

    display(&sA, &sB, &sC);
    solve(7, &sA, &sC, &sB, &sA, &sB, &sC);

    return 0;
}