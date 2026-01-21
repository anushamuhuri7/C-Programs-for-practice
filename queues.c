#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void simparr() {
    static int queue[MAX];
    static int front = -1, rear = -1;
    int choice, val;
    printf("Press 1 to add and 2 to delete: ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (rear == (MAX - 1)) {
            printf("[Simple] Overflow!\n");
        } else {
            if (front == -1) front = 0;
            printf("Enter value: ");
            scanf("%d", &val);
            queue[++rear] = val;
            printf("[Simple] added: %d\n", val);
        }
    } else if (choice == 2) {
        if (front == -1 || front > rear) {
            printf("[Simple] Underflow!\n");
        } else {
            printf("[Simple] Deleted: %d\n", queue[front++]);
            if (front > rear) front = rear = -1;
        }
    }
}
typedef struct Q {
    int *array;
    int init;
    int front;
    int rear;
    int capacity;
} dyn;
void dynarr(dyn *dq) {
    int choice, val, size;
    if (!dq->init) {
        printf("Enter capacity for Dynamic Queue: ");
        scanf("%d", &size);
        dq->capacity = size;
        dq->array = (int *)malloc(dq->capacity * sizeof(int));
        dq->front = -1;
        dq->rear = -1;
        dq->init = 1;
    }
    printf("Press 1 to add and 2 to delete: ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (dq->rear == (dq->capacity - 1)) {
            printf("Dynamic Overflow!\n");
        } else {
            if (dq->front == -1) dq->front = 0;
            printf("Enter value: ");
            scanf("%d", &val);
            dq->array[++dq->rear] = val;
            printf("Dynamic added: %d\n", val);
        }
    } else if (choice == 2) {
        if (dq->front == -1 || dq->front > dq->rear) {
            printf("Dynamic Underflow!\n");
        } else {
            printf("Dynamic Deleted: %d\n", dq->array[dq->front++]);
            if (dq->front > dq->rear) dq->front = dq->rear = -1;
        }
    }
}
struct qustr {
    int items[MAX];
    int front;
    int rear;
    int init;
};
void queuestr(struct qustr *qs) {
    int choice, val;
    if (!qs->init) {
        qs->front = -1;
        qs->rear = -1;
        qs->init = 1;
    }
    printf("Press 1 to add and 2 to delete: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (qs->rear == (MAX - 1)) {
            printf("[Struct] Overflow!\n");
        } else {
            if (qs->front == -1) qs->front = 0;
            printf("Enter value: ");
            scanf("%d", &val);
            qs->items[++qs->rear] = val;
            printf("[Struct] added: %d\n", val);
        }
    } else if (choice == 2) {
        if (qs->front == -1 || qs->front > qs->rear) {
            printf("[Struct] Underflow!\n");
        } else {
            printf("[Struct] Deleted: %d\n", qs->items[qs->front++]);
            if (qs->front > qs->rear) qs->front = qs->rear = -1;
        }
    }
}
int main() {
    dyn dq = {NULL, 0, -1, -1, 0};
    struct qustr qs = {{0}, -1, -1, 0};
    int choice;

    while (1) {
        printf("\nChoose how to create a queue:\n");
        printf("1. Simple array\n");
        printf("2. Dynamic array\n");
        printf("3. Structure implementation\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: simparr(); break;
            case 2: dynarr(&dq); break;
            case 3: queuestr(&qs); break;
            case 4: 
                if (dq.init) free(dq.array); 
                return 0;
            default: printf("Invalid choice!\n");
        }
        printf("-----------------------------\n");
    }
    return 0;
}