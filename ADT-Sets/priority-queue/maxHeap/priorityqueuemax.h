#include <stdio.h>
#include <stdlib.h>
#define SIZE 0xFF

typedef struct {
    int elem[SIZE];
    int count;
} maxHeap, minHeap;

/*
-- Function Prototypes --
*/

// General Functions
void print(maxHeap A);
void initHeap(maxHeap* A);

// Heapsort Functions
void maxSubheapify(maxHeap* A, int ndx);
void maxHeapifyTree(maxHeap* A);
void swap(maxHeap* A, int firstNdx, int secondNdx);
void heapSort(maxHeap* A);

/*
-- Function Definitions --
*/
void print(maxHeap A) {
    int ctr;
    for (ctr = 0; ctr < A.count; ctr++) {
        printf("%d ", A.elem[ctr]);
    }
    printf("\n");
}

void initHeap(maxHeap* A) {
    A->count = 0;
}

void maxSubheapify(maxHeap* A, int ndx) {
    int largest;
    int leftChild = 2*ndx+1;
    int rightChild = leftChild+1;

    if (leftChild < A->count && A->elem[leftChild] > A->elem[ndx]) {
        largest = leftChild;
    } else {
        largest = ndx;
    }

    if (rightChild < A->count && A->elem[rightChild] > A->elem[largest]) {
        largest = rightChild;
    }

    if (largest != ndx) {
        swap(A, largest, ndx);
        maxSubheapify(A, largest);
    }
}

void maxHeapifyTree(maxHeap* A) {
    int lastParent = (A->count - 2) / 2;

    for (; lastParent >= 0; lastParent--) {
        maxSubheapify(A, lastParent);
    }

}

void swap(maxHeap* A, int firstNdx, int secondNdx) {
    int temp = A->elem[firstNdx];
    A->elem[firstNdx] = A->elem[secondNdx];
    A->elem[secondNdx] = temp;
}

void heapSort(maxHeap* A) {
    maxHeapifyTree(A);
    int ndx = A->count;
    while (A->count > 1) {
        swap(A, 0, A->count - 1);
        A->count--;
        maxSubheapify(A, 0);
    }
    A->count = ndx;
}