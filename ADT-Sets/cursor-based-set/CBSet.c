/*

This program will perform UID operations on Sorted Sets implemented using Cursor-Based Implementation.

Programmer: Ethan Andre O. Dalocanog
Date Created: October 29, 2025

*/

#include <stdio.h>
#include "CBSet.h"

int main() {
    VirtualHeap VH;
    LIST A;
    initVirtualHeap(&VH);
    initList(&A);

    insertSortedUnique(&VH, &A, 3);
    insertSortedUnique(&VH, &A, 1);
    insertSortedUnique(&VH, &A, 5);
    insertSortedUnique(&VH, &A, 10);
    insertSortedUnique(&VH, &A, 6);

    displaySet(VH, A, "Set A");

    LIST B;
    initList(&B);

    insertSortedUnique(&VH, &B, 6);
    insertSortedUnique(&VH, &B, 1);
    insertSortedUnique(&VH, &B, 10);
    insertSortedUnique(&VH, &B, 4);
    insertSortedUnique(&VH, &B, 7);

    displaySet(VH, B, "Set B");

    LIST C = UnionSorted(&VH, A, B);
    displaySet(VH, C, "Union of Set A and Set B");

    LIST D = IntersectionSorted(&VH, A, B);
    displaySet(VH, D, "Intersection of Set A and Set B");

    LIST E = DifferenceSorted(&VH, A, B);
    displaySet(VH, E, "Difference of Set A and Set B");

    return 0;
}