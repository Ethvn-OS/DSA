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
void printStack(Stacktype S);

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

void printStack(Stacktype S) {
    for (; S.top < MAX;) {
        printf("Data: %c\n", top(&S));
        pop(&S);
    }
}