/*
This program will demonstrate heapsort using heapify().

Programmer: Ethan Andre O. Dalocanog
Date Created: October 14, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "priorityqueuemax.h"
#define MAX 6

int main() {
    maxHeap A;
    initHeap(&A);
    A.elem[A.count++] = 2;
    A.elem[A.count++] = 8;
    A.elem[A.count++] = 5;
    A.elem[A.count++] = 3;
    A.elem[A.count++] = 9;
    A.elem[A.count++] = 1;
    print(A);

    heapSort(&A);
    print(A);

    return 0;
}