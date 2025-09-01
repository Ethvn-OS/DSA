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
void initStack(Stacktype* L);
bool isEmpty(Stacktype* L);
bool isFull(Stacktype* L);
void pushStack(Stacktype* L, char elem);
void popStack(Stacktype* L);
char topStack(Stacktype L);
void printStack(Stacktype L);

//Function Definitions

//This function initializes the stack
void initStack(Stacktype* L) {
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
void pushStack(Stacktype* L, char elem) {
    Stacktype temp = (Stacktype)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = elem;
        temp->link = *L;
        *L = temp;
    }
}

//This function will pop (delete) an element at the top of the linkedList
void popStack(Stacktype* L) {
    if (!isEmpty(L)){
        Stacktype temp = *L;
        *L = temp->link;
        free(temp);
    }
}

//This function will return the element at the top of the stack
char topStack(Stacktype L) {
    return (!isEmpty(&L)) ? L->elem : '\0';
}

//This stack will print and display the stack
void printStack(Stacktype L) {
    for (; L != NULL; L = L->link) {
        printf("Data: %c\n", L->elem);
    }
}

/*void printStack(Stacktype L) {
    for (; L != NULL;) {
        printf("Data: %c\n", L->elem);
        popStack(&L);
    }
}*/