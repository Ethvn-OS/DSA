#include <stdio.h>
#include <stdlib.h>

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
        if (A->rear != NULL) {
            A->rear->link = temp;
        } else {
            A->front = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Queue* A) {
    if (A->front != NULL) {
        Node temp = A->front;
        A->front = temp->link;
        free(temp);
        if (A->front == NULL) {
            A->rear = NULL;
        }
    }
}

void printQueue(Queue* A) {
    //insert code here
}