//Macro Definitions and inclusion of header file
#define MAX 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Data Structure Definition
typedef struct node {
    char elem;
    struct node* link;
} *Stacktype;

//Function Prototypes
void initialize(Stacktype* L);
bool isEmpty(Stacktype* L);
bool isFull(Stacktype* L);
void push(Stacktype* L, char elem);
void pop(Stacktype* L);
char top(Stacktype* L);
void printStack(Stacktype* L);
void insertBottom(Stacktype* L, char elem);

//Function Definitions

//This function initializes the stack
void initialize(Stacktype* L) {
    *L = NULL;
}

//This function returns true if the stack is empty; otherwise false
bool isEmpty(Stacktype* L) {
    return (*L == NULL) ? true : false;
}

//This function returns true if the stack is full; otherwise false
bool isFull(Stacktype* L) {
    return false;
}

//This function will push (insert) an element into the linkedList if the stack is not yet full
void push(Stacktype* L, char elem) {
    Stacktype temp = (Stacktype)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = elem;
        temp->link = *L;
        *L = temp;
    } else {
        printf("Memory allocation failed.\n");
    }
}

//This function will pop (delete) an element at the top of the linkedList
void pop(Stacktype* L) {
    if (!isEmpty(L)){
        Stacktype temp = *L;
        *L = temp->link;
        free(temp);
    } else {
        printf("The stack is empty.\n");
    }
}

//This function will return the element at the top of the stack
char top(Stacktype* L) {
    return (!isEmpty(L)) ? (*L)->elem : '\0';
}

//This stack will print and display the stack
void printStack(Stacktype* L) {
    Stacktype B = NULL;
    Stacktype temp;
    while (!isEmpty(L)) {
        push(&B, (*L)->elem);
        printf("Data: %c\n", top(&B));
        pop(L);
    }

    while(!isEmpty(&B)) {
        push(L, B->elem);
        pop(&B);
    }
}

//This function inserts an element at the bottom of the stack
void insertBottom(Stacktype* L, char elem) {
    Stacktype B;
    initialize(&B);

    if (!isFull(L)) {
        char tops;
        while(!isEmpty(L)) {
            tops = top(L);
            pop(L);
            push(&B, tops);
        }

        push(L, elem);

        while(!isEmpty(&B)) {
            tops = top(&B);
            pop(&B);
            push(L, tops);
        }
    } else {
        printf("\nThe stack is full.\n");
    }
}