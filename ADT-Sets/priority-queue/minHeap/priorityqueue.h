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
void insert(Heap* A, int elem);
int findParent(int ndx);
void display(Heap A);
void swap(Heap* A, int parentNdx, int currNdx);
int deleteMin(Heap* A);
void heapifySubtree(Heap* A, int subRoot);
int leftChild(int ndx);
int rightChild(int ndx);

/*
-- Function Definitions --
*/

void initHeap(Heap* A) {
    A->lastNdx = -1;
}

void display(Heap A) {
    int ctr;
    for (ctr = 0; ctr <= A.lastNdx; ctr++) {
        printf("%d ", A.elem[ctr]);
    }
}

void swap(Heap* A, int parentNdx, int currNdx) {
    int temp = A->elem[parentNdx];
    A->elem[parentNdx] = A->elem[currNdx];
    A->elem[currNdx] = temp;
}

void insert(Heap* A, int elem) {
    A->elem[++A->lastNdx] = elem;
    int currNdx = A->lastNdx;
    int parentNdx = findParent(currNdx);

    for (; currNdx != 0 && A->elem[parentNdx] > A->elem[currNdx]; currNdx = parentNdx, parentNdx = findParent(currNdx)) {
        swap(A, parentNdx, currNdx);
    }
}

int deleteMin(Heap* A) {
    int SChild = 0; //smaller child of parent
    int currNdx = 0;
    int min = A->elem[currNdx];
    A->elem[0] = A->elem[A->lastNdx--];

    while (leftChild(currNdx) < A->lastNdx && A->elem[currNdx] > A->elem[leftChild(currNdx)] || A->elem[currNdx] > A->elem[rightChild(currNdx)]) {

        if (A->elem[rightChild(currNdx)] < A->elem[leftChild(currNdx)]) {
            SChild = rightChild(currNdx);
        } else {
            SChild = leftChild(currNdx);
        }
        swap(A, currNdx, SChild);

        currNdx = SChild;
    }

    return min;
}

void heapifySubtree(Heap* A, int subRoot) {
    int curr = subRoot;
    int flag = 0;

    while (flag != 1) {
        int leftChild = 2*curr+1;
        int rightChild = 2*curr+2;
        int smallest = 0;

        if (leftChild <= A->lastNdx && A->elem[leftChild] < A->elem[curr]) {
            smallest = leftChild;
        } else {
            smallest = curr;
        }

        if (rightChild <= A->lastNdx && A->elem[rightChild] < A->elem[smallest]) {
            smallest = rightChild;
        }

        if (smallest != curr) {
            int temp = A->elem[curr];
            A->elem[curr] = A->elem[smallest];
            A->elem[smallest] = temp;
            curr = smallest;
        } else {
            flag = 1;
        }
    }
}

int findParent(int ndx) {
    return (ndx - 1) / 2;
}

int leftChild(int ndx) {
    return 2*ndx+1;
}

int rightChild(int ndx) {
    return 2*ndx+2;
}