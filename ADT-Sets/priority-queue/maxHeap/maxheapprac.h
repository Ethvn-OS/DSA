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
} maxHeap;

/*
-- Function Prototypes --------------------------------------------
*/

void initHeap(maxHeap* A);

// Priority Queue Operations
void insert(maxHeap* A, int elem);
int deleteMax(maxHeap* A);
void heapifyMaxHeap(maxHeap* A);                    // This function calls the heapifySubtree() function
void heapifySubtree(maxHeap* A, int subRoot);

// Helper functions for basic operations
int findParent(int ndx);
int leftChild(int ndx);
int rightChild(int ndx);

// Basic utility functions
void display(maxHeap A);
void swap(maxHeap* A, int parentNdx, int currNdx);

/*
-- Function Definitions --------------------------------------------
*/

void initHeap(maxHeap* A)
{
    A->lastNdx = -1;
}

void insert(maxHeap* A, int elem)
{
    int curr = A->lastNdx;
    A->elem[++A->lastNdx] = elem;
    for (curr = A->lastNdx; curr >= 0 && A->elem[curr] > A->elem[findParent(curr)]; curr = findParent(curr)) {
        swap(A, curr, findParent(curr));
    }
}

int deleteMax(maxHeap* A)
{
    if (A->lastNdx != -1) {
        int front = A->elem[0],
            curr,
            largest;
        A->elem[0] = A->elem[A->lastNdx--];
        for (curr = 0; leftChild(curr) <= A->lastNdx && A->elem[leftChild(curr)] > A->elem[curr] || A->elem[rightChild(curr)] > A->elem[curr];) {
            largest = curr;

            if (A->elem[leftChild(curr)] > A->elem[curr]) {
                largest = leftChild(curr);
            } else {
                largest = curr;
            }

            if (rightChild(curr) <= A->lastNdx && A->elem[rightChild(curr)] > A->elem[largest]) {
                largest = rightChild(curr);
            }

            if (largest != curr) {
                swap(A, largest, curr);
                curr = largest;
            }
        }
        return front;
    } else {
        return -1;
    }
}

void heapifyMaxHeap(maxHeap* A)
{
    int lastParent;
    for (lastParent = (A->lastNdx-1) / 2; lastParent >= 0; lastParent--) {
        heapifySubtree(A, lastParent);
    }
}

// // Recursive Definition
void heapifySubtree(maxHeap* A, int subRoot)
{
    int LC = leftChild(subRoot),
        RC = rightChild(subRoot),
        largest;

    largest = (LC <= A->lastNdx && A->elem[LC] > A->elem[subRoot]) ? LC : subRoot;

    if (RC <= A->lastNdx && A->elem[RC] > A->elem[largest]) {
        largest = RC;
    }

    if (largest != subRoot) {
        swap(A, largest, subRoot);
        heapifySubtree(A, largest);
    }
}

// Non-recursive definition
// void heapifySubtree(maxHeap* A, int subRoot)
// {
//     int flag = 0,
//         curr = subRoot,
//         LC,
//         RC,
//         largest;

//     while (flag != 1) {
//         LC = leftChild(curr);
//         RC = rightChild(curr);

//         largest = (LC <= A->lastNdx && A->elem[LC] > A->elem[curr]) ? LC : curr;

//         if (RC <= A->lastNdx && A->elem[RC] > A->elem[largest]) {
//             largest = RC;
//         }

//         if (largest != curr) {
//             swap(A, largest, curr);
//             curr = largest;
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

void display(maxHeap A)
{
    int ctr;
    for (ctr = 0; ctr <= A.lastNdx; ctr++) {
        printf("%d ", A.elem[ctr]);
    }
}

void swap(maxHeap* A, int parentNdx, int currNdx)
{
    int temp = A->elem[parentNdx];
    A->elem[parentNdx] = A->elem[currNdx];
    A->elem[currNdx] = temp;
}