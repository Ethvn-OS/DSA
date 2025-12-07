#include <stdio.h>
#include <stdlib.h>
#include "maxheapprac.h"

int main() {
    maxHeap H;
    initHeap(&H);

    // Use this if you want to test your heapify
    H.elem[++H.lastNdx] = 6;
    H.elem[++H.lastNdx] = 2;
    H.elem[++H.lastNdx] = 5;
    H.elem[++H.lastNdx] = 4;
    H.elem[++H.lastNdx] = 3;
    H.elem[++H.lastNdx] = 9;
    H.elem[++H.lastNdx] = 7;
    H.elem[++H.lastNdx] = 18;
    H.elem[++H.lastNdx] = 10;
    H.elem[++H.lastNdx] = 9;
    H.elem[++H.lastNdx] = 10;

    printf("\nBefore heapify: ");
    display(H);
    printf("\nAfter Heapify: ");
    heapifyMaxHeap(&H);
    display(H);
    printf("\n\n");

    // // Use this if you want your insert
    // insert(&H, 6);
    // insert(&H, 2);
    // insert(&H, 5);
    // insert(&H, 4);
    // insert(&H, 3);
    // insert(&H, 9);
    // insert(&H, 7);
    // insert(&H, 18);
    // insert(&H, 10);
    // insert(&H, 9);
    // insert(&H, 10);
    // display(H);

    // // Use this if you want to simulate deletion
    // int del = deleteMax(&H);
    // printf("\n\nDeleted Elem: %d\n\n", del);
    // display(H);

    // Use this to check your heapsort function
    heapSort(&H);
    printf("After HeapSort (Ascending Order): ");
    display(H);

    return 0;
}