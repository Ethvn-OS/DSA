#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    char elem[MAX];
    int top; 
}Stacktype;

void initialize(Stacktype* S);
void push(Stacktype* S, char elem);
void pop(Stacktype* S);
char top(Stacktype* S);
bool isEmpty(Stacktype* S);
bool isFull(Stacktype* S);
void printStack(Stacktype* S);
void insertBottom(Stacktype* S, char elem);

// initialize
void initialize(Stacktype* S){
    S->top = MAX;
}

// push
void push(Stacktype* S, char elem){
    if(!isFull(S)){
        S->elem[--S->top] = elem;
    }
}

// pop
void pop(Stacktype* S){
    if(!isEmpty(S)){
        S->top++;
    }
}

// top
char top(Stacktype* S){
    return (!isEmpty(S)) ? S->elem[S->top] : '\0'; 
}

// isEmpty
bool isEmpty(Stacktype* S){
    return (S->top == MAX) ? true : false; 
}

// isFull
bool isFull(Stacktype* S){
    return (S->top == 0) ? true : false;
}

//This function prints the stack
void printStack(Stacktype* S) {
    for (; S->top < MAX;) {
        printf("Data: %c\n", top(S));
        pop(S);
    }
}

//This function inserts an element at the bottom of the stack
void insertBottom(Stacktype* S, char elem) {
    Stacktype B;
    initialize(&B);

    if (!isFull(S)) {
        char tops;
        while (!isEmpty(S)) {
            tops = top(S);
            pop(S);
            push(&B, tops);
        }

        push(S, elem);

        while (!isEmpty(&B)) {
            tops = top(&B);
            pop(&B);
            push(S, tops);
        }
    } else {
        printf("\nThe stack is full.\n");
    }
}