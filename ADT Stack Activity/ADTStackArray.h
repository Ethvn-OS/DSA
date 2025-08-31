//Macro Definitions and inclusion of header file
#define MAX 5
#include <stdio.h>
#include <stdbool.h>

//Data Structure Definition
typedef struct {
    char elem[MAX];
    int top;
} Stacktype;

//Function Prototypes
void initStack(Stacktype* L);
bool isEmpty(Stacktype* L);
bool isFull(Stacktype* L);
void pushStack(Stacktype* L, char elem);
void popStack(Stacktype* L);
char topStack(Stacktype L);

//Function Definitions

//This function initializes the stack
void initStack(Stacktype* L) {
    L->top = MAX;
}

//This function returns true if the stack is empty; otherwise false
bool isEmpty(Stacktype* L) {
    return (L->top == MAX) ? true : false;
}

//This function returns true if the stack is full; otherwise false
bool isFull(Stacktype* L) {
    return (L->top == 0) ? true : false;
}

//This function will push (insert) an element into the arrayList if the stack is not yet full
void pushStack(Stacktype* L, char elem) {
    bool val = isFull(L);
    if (val == false) {
        L->elem[--L->top] = elem;
    }
}

//This function will pop (delete) an element at the top of the arrayList
void popStack(Stacktype* L) {
    bool val = isEmpty(L);
    if (val == false) {
        L->top++;
    }
}

//This function will return the element at the top of the stack
char topStack(Stacktype L) {
    bool val = isEmpty(&L);
    return (val == false) ? L.elem[L.top] : '\0';
}