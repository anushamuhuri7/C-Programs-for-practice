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

MultiStack* create_stacks(int n, int m) {
    MultiStack* ms = (MultiStack*)malloc(sizeof(MultiStack));
    ms->capacity = m;
    ms->num_stacks = n;

    ms->data = (int*)malloc(m * sizeof(int));
    ms->next = (int*)malloc(m * sizeof(int));
    ms->top = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ms->top[i] = -1;
    }

    ms->free_top = 0;
    for (int i = 0; i < m - 1; i++) {
        ms->next[i] = i + 1;
    }
    ms->next[m - 1] = -1;

    return ms;
}

int is_full(MultiStack* ms) {
    return ms->free_top == -1;
}

int is_empty(MultiStack* ms, int sn) {
    return ms->top[sn] == -1;
}

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

int pop(MultiStack* ms, int sn) {
    if (sn < 0 || sn >= ms->num_stacks) {
        printf("Invalid stack number!\n");
        return INT_MIN;
    }
    if (is_empty(ms, sn)) {
        printf("Stack %d Underflow!\n", sn);
        return INT_MIN;
    }

    int i = ms->top[sn];
    ms->top[sn] = ms->next[i];
    ms->next[i] = ms->free_top;
    ms->free_top = i;

    int val = ms->data[i];
    printf("Popped %d from Stack %d\n", val, sn);
    return val;
}

void display_status(MultiStack* ms) {
    printf("\n--- Current System State ---\n");
    for (int i = 0; i < ms->num_stacks; i++) {
        printf("Stack %d: ", i);
        int curr = ms->top[i];
        if (curr == -1) printf("[Empty]");
        while (curr != -1) {
            printf("%d ", ms->data[curr]);
            curr = ms->next[curr];
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

int main() {
    int n, m;
    printf("Enter number of stacks: ");
    scanf("%d", &n);
    printf("Enter total capacity of array: ");
    scanf("%d", &m);

    MultiStack* ms = create_stacks(n, m);
    int choice, sn, val;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Stack number (0 to %d): ", n - 1);
                scanf("%d", &sn);
                printf("Value to push: ");
                scanf("%d", &val);
                push(ms, val, sn);
                break;
            case 2:
                printf("Stack number (0 to %d): ", n - 1);
                scanf("%d", &sn);
                pop(ms, sn);
                break;
            case 3:
                display_status(ms);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}