#include<stdio.h>
#include<stdlib.h>

struct node_st{
int data;
struct node_st *link;
};
struct queue{
struct node_st *front;
struct node_st *rear;
};
void push1(struct node_st **s, int item)
{
struct node_st *q1=malloc(sizeof(struct node_st));
q1->data=item;
q1->link=*s;
*s=q1;
printf("[Stack] Pushed: %d\n", item);
}
struct node_st* push2(struct node_st *s, int item){
struct node_st *q2=malloc(sizeof(struct node_st));
q2->data=item;
q2->link=s;
printf("[Stack] Pushed: %d\n", item);
return q2;
}
void pop1(struct node_st **s){
if(*s == NULL) {
            printf("[Struct] Underflow!\n");
            return;
        }
        struct node_st *temp = *s;
        printf("[Stack] Deleted: %d\n", temp->data);
        *s = (*s)->link;
        free(temp);
}
int pop2(struct node_st **s) {
    if (*s == NULL) {
        printf("[Stack] Underflow!\n");
        return -1;
    }
    struct node_st *temp = *s;
    int x = temp->data;
    *s = (*s)->link;
    free(temp);
    return x;
}
struct node_st* enqueue1(struct queue *q, int a) {
    struct node_st *temp = malloc(sizeof(struct node_st));
    temp->data = a;
    temp->link = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->link = temp;
        q->rear = temp;
    }
    printf("[Queue] Enqueued: %d\n", a);
    return q->rear;
}
void enqueue2(struct queue *q, int a) {
    struct node_st *temp = malloc(sizeof(struct node_st));
    temp->data = a;
    temp->link = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->link = temp;
        q->rear = temp;
    }
    printf("[Queue] Enqueued: %d\n", a);
}
int dequeue1(struct queue *q) {
    if (q->front == NULL) {
        printf("[Queue] Underflow!\n");
        return -1;
    }
    struct node_st *temp = q->front;
    int val = temp->data;
    q->front = q->front->link;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}
void dequeue2(struct queue *q) {
    if (q->front == NULL) {
        printf("[Queue] Underflow!\n");
        return;
    }
    struct node_st *temp = q->front;
    printf("[Queue] Dequeued: %d\n", temp->data);
    q->front = q->front->link;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}
int main() {
    struct node_st *stack = NULL;
    struct queue q = {NULL, NULL};
    int choice, val;
    while (1) {
        printf("\n1. Push (void) 2. Push (return) 3. Pop (void) 4. Pop (return)\n");
        printf("5. Enq (void) 6. Enq (return) 7. Deq (void) 8. Deq (return) 9. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Val: "); scanf("%d", &val); push1(&stack, val); break;
            case 2: printf("Val: "); scanf("%d", &val); stack = push2(stack, val); break;
            case 3: pop1(&stack); break;
            case 4: val = pop2(&stack); if(val != -1) printf("Returned: %d\n", val); break;
            case 5: printf("Val: "); scanf("%d", &val); enqueue2(&q, val); break;
            case 6: printf("Val: "); scanf("%d", &val); enqueue1(&q, val); break;
            case 7: dequeue2(&q); break;
            case 8: val = dequeue1(&q); if(val != -1) printf("Returned: %d\n", val); break;
            case 9: exit(0);
          }
    }
return 0;
}
