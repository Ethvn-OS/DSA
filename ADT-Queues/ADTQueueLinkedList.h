#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Data type definitions
typedef struct node {
    char elem;
    struct node* link;
} Nodetype, *Node;

typedef struct {
    Node rear;
    Node front;
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
    A->rear = NULL;
    A->front = NULL;
}

void enqueue(char elem, Queue* A) {
    Node temp = (Node)malloc(sizeof(Nodetype));
    if (temp != NULL) {
        temp->elem = elem;
        temp->link = NULL;
        if (A->rear == NULL) {
            A->front = temp;
        } else {
            A->rear->link = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Queue* A) {
    if (!isEmpty(*A)) {
        Node temp = A->front;
        A->front = temp->link;
        free(temp);
        if (A->front == NULL) {
            A->rear = NULL;
        }
    }
}

bool isEmpty(Queue A) {
    return (A.front == NULL) ? true : false;
}

bool isFull(Queue A) {
    return false;
}

char front(Queue A) {
    return (!isEmpty(A)) ? A.front->elem : '\0';
}

//print queue for when elements are unique and not unique (flexible)
void printQueue(Queue* A) {
    Queue B;
    initializeQueue(&B);
    if (!isEmpty(*A)) {
        while(!isEmpty(*A)) {
            enqueue(A->front->elem, &B);
            printf("Data: %c\n", B.rear->elem);
            dequeue(A);
        }

        while (!isEmpty(B)) {
            enqueue(B.front->elem, A);
            dequeue(&B);
        }
    } else {
        printf("The queue is already empty.\n");
    }
}