#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"

int main() {
    Heap H;
    initHeap(&H);

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

    heapifySubtree(&H, 0);
    display(H);

    return 0;
}