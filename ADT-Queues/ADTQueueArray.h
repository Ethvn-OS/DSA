#include <stdio.h>
#include <stdbool.h>
#define MAX 8

//Data type definitions
typedef struct {
    char elem[MAX];
    int front;
    int rear;
} Queue;

//Function prototypes
void initializeQueue(Queue* A);
void enqueue(char elem, Queue* A);
void dequeue(Queue* A);
bool isEmpty(Queue A);
bool isFull(Queue A);
char front(Queue A);
void printQueue(Queue* A);

//Function definitions
void initializeQueue(Queue* A) {
    A->front = 1;
    A->rear = 0;
}

void enqueue(char elem, Queue* A) {
    if (!isFull(*A)) {
        A->rear = (A->rear + 1) % MAX;
        A->elem[A->rear] = elem;
    } else {
        printf("The queue is full. Can't insert element %c\n", elem);
    }
}

void dequeue(Queue* A) {
    if (!isEmpty(*A)) {
        A->front = (A->front + 1) % MAX;
    }
}

bool isEmpty(Queue A) {
    return ((A.rear + 1) % MAX == A.front) ? true : false;
}

bool isFull(Queue A) {
    return ((A.rear + 2) % MAX == A.front) ? true : false;
}

char front(Queue A) {
    return (!isEmpty(A)) ? A.elem[A.front] : '\0';
}

//print queue for when elements are unique
void printQueue(Queue* A) {
    char temp = front(*A);
    char store;
    if (!isEmpty(*A)) {
        do {
            store = front(*A);
            printf("Data: %c\n", store);
            dequeue(A);
            enqueue(store, A);
        } while(front(*A) != temp);
    } else {
        printf("The queue is already empty.\n");
    }
}