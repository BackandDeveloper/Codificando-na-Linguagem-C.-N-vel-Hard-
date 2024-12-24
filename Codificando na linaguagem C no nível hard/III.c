// Questão III:
// Como implementar uma fila usando duas pilhas em C?

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void push(Stack** top, int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack** top) {
    if (*top == NULL) return -1;
    Stack* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

void enqueue(Queue* q, int data) {
    push(&q->stack1, data);
}

int dequeue(Queue* q) {
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

int main() {
    Queue q = {NULL, NULL};
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}


