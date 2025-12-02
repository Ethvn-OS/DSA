#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8

/*
--> Data Type Definitions <------------------------------------------
*/

typedef struct cell {
    int elem;
    struct cell* LC;
    struct cell* RC;
} ctype, *BST;

/*
--> Function Prototypes <--------------------------------------------
*/

void insertElem(BST* S, int elem);
void deleteElem(BST* S, int elem);
bool isMember(BST S, int elem);
int minElem(BST S);
int maxElem(BST S);
void inOrder(BST S);

/*
--> Function Definitions <-------------------------------------------
*/

void insertElem(BST* S, int elem)
{
    BST* A;
    for (A = S; *A != NULL && (*A)->elem != elem; ) {
        A = (elem < (*A)->elem) ? &(*A)->LC : &(*A)->RC;
    }
    if (*A == NULL) {
        BST temp = (BST)malloc(sizeof(ctype));
        if (temp != NULL) {
            temp->elem = elem;
            temp->LC = NULL;
            temp->RC = NULL;
            *A = temp;
        }
    }
}

// This function will use immediate predecessor
// deleteElem in binary tree has three cases:
// case 1: deleting a leaf
// case 2: deleting an interior node with one child
// case 3: deleting an interior node with two children
void deleteElem(BST* S, int elem)
{
    BST* A;
    BST tempo;
    for (A = S; *A != NULL && (*A)->elem != elem; ) {
        A = (elem < (*A)->elem) ? &(*A)-> LC : &(*A)->RC;
    }
    if (*A != NULL) {
        if ((*A)->LC != NULL && (*A)->RC != NULL) { // handles the third case
            BST temp = *A;
            for (A = &temp->LC; (*A)->RC != NULL; A = &(*A)->RC) {}
            temp->elem = (*A)->elem;
            tempo = *A;
            *A = tempo->LC;
        } else { // handles the first and second case
            tempo = *A;
            *A = ((*A)->LC != NULL) ? (*A)->LC : (*A)->RC;
        }
        free(tempo);
    }
}

bool isMember(BST S, int elem)
{
    BST A;
    for (A = S; A != NULL && A->elem != elem; ) {
        A = (elem < A->elem) ? A->LC : A->RC;
    }
    return (A != NULL) ? true : false;
}

int minElem(BST S)
{
    BST A;
    for (A = S; A != NULL && A->LC != NULL; A = A->LC) {}
    return (A != NULL) ? A->elem : -1;
}

int maxElem(BST S)
{
    BST A;
    for (A = S; A != NULL && A->RC != NULL; A = A->RC) {}
    return (A != NULL) ? A->elem : -1;
}

void inOrder(BST S)
{
    if (S != NULL) {
        inOrder(S->LC);
        printf("%d ", S->elem);
        inOrder(S->RC);
    }
}