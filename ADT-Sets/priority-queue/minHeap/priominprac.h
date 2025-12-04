#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 15

/*
-- Datatype Definition --
*/

typedef struct {
    int elem[MAX];
    int lastNdx;
} Heap;

/*
-- Function Prototypes --
*/

void initHeap(Heap* A);

// Priority Queue Operations
void insert(Heap* A, int elem);
int deleteMin(Heap* A);
void heapifyMinHeap(Heap* A);                    // This function calls the heapifySubtree() function
void heapifySubtree(Heap* A, int subRoot);

// Helper functions for basic operations
int findParent(int ndx);
int leftChild(int ndx);
int rightChild(int ndx);

// Basic utility functions
void display(Heap A);
void swap(Heap* A, int parentNdx, int currNdx);

/*
-- Function Definitions --
*/

void initHeap(Heap* A)
{
    A->lastNdx = -1;
}

void insert(Heap* A, int elem)
{
    A->elem[++A->lastNdx] = elem;
    int ctr,
        par;
    for (ctr = A->lastNdx, par = findParent(ctr); ctr != 0 && A->elem[par] > A->elem[ctr]; ctr = findParent(ctr)) {
        swap(A, par, ctr);
    }
}

int deleteMin(Heap* A)
{
    if (A->lastNdx != -1) {                 // This is just to check if the minHeap has elements stored in it
        int ctr,
            smallest,                       // store smallest for min
            store;
        int front = A->elem[0];
        A->elem[0] = A->elem[A->lastNdx--];
        for (ctr = 0; leftChild(ctr) <= A->lastNdx && A->elem[ctr] > A->elem[leftChild(ctr)] || A->elem[ctr] > A->elem[rightChild(ctr)]; ) {
            smallest = ctr;

            store = (A->elem[leftChild(ctr)] < A->elem[rightChild(ctr)]) ? leftChild(ctr) : rightChild(ctr);

            if (A->elem[store] < A->elem[smallest]) {
                swap(A, store, smallest);
                ctr = store;
            }
        }
        return front;
    }
}

void heapifyMinHeap(Heap* A)
{
    int lastParent;
    for (lastParent = (A->lastNdx-1) / 2; lastParent >= 0; lastParent--) {
        heapifySubtree(A, lastParent);
    }
}

// // Recursive Definition
void heapifySubtree(Heap* A, int subRoot)
{
    int smallest,
        curr = subRoot,
        leftChild = subRoot*2 + 1,
        rightChild = leftChild + 1;

    smallest = (curr <= A->lastNdx && A->elem[leftChild] < A->elem[curr]) ? leftChild : curr;

    if (curr <= A->lastNdx && A->elem[rightChild] < A->elem[smallest]) {
        smallest = rightChild;
    }

    if (smallest != curr) {
        swap(A, smallest, curr);
        heapifySubtree(A, smallest);
    }
}

// Non-recursive definition
// void heapifySubtree(Heap* A, int subRoot)
// {
//     int smallest,
//         leftChild,
//         rightChild,
//         curr = subRoot,
//         flag = 0;

//     while (flag != 1) {
//         leftChild = curr*2+1;
//         rightChild = leftChild+1;

//         smallest = (curr <= A->lastNdx && A->elem[leftChild] < A->elem[curr]) ? leftChild : curr;

//         if (curr <= A->lastNdx && A->elem[rightChild] < A->elem[smallest]) {
//             smallest = rightChild;
//         }

//         if (smallest != curr) {
//             swap(A, smallest, curr);
//             curr = smallest;
//         } else {
//             flag = 1;
//         }
//     }
// }

int findParent(int ndx)
{
    return (ndx-1)/2;
}

int leftChild(int ndx)
{
    return ndx*2+1;
}

int rightChild(int ndx)
{
    return ndx*2+2;
}

void display(Heap A)
{
    int ctr;
    for (ctr = 0; ctr <= A.lastNdx; ctr++) {
        printf("%d ", A.elem[ctr]);
    }
}

void swap(Heap* A, int parentNdx, int currNdx)
{
    int temp = A->elem[parentNdx];
    A->elem[parentNdx] = A->elem[currNdx];
    A->elem[currNdx] = temp;
}