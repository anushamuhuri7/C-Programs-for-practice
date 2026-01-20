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
void solve(int n, Stack *src, Stack *dst, Stack *aux, Stack *a, Stack *b, Stack *c) {
    if (n == 0) return;
    solve(n - 1, src, aux, dst, a, b, c);
    int d = pop(src);
    push(dst, d);
    printf("Move %d from %c to %c\n", d, src->name, dst->name);
    display(a, b, c);
    solve(n - 1, aux, dst, src, a, b, c);
}
int main() {
    Stack sA = {{0}, -1, 'A'}, sB = {{0}, -1, 'B'}, sC = {{0}, -1, 'C'};
    for (int i = 7; i >= 1; i--) push(&sA, i);
    display(&sA, &sB, &sC);
    solve(7, &sA, &sC, &sB, &sA, &sB, &sC);
    return 0;
}