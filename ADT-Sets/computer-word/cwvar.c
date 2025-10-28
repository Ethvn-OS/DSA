/*

This program will perform operations for the computer word variation
of bit-vector implementation with an array (buckets).

Programmer: Ethan Andre O. Dalocanog
Date Created: October 28, 2025

*/

#include <stdio.h>
#include "cwvar.h"

int main() {
    SET A;
    initSet(A);

    printf("=== BIT-VECTOR IMPLEMENTATION (COMPUTER WORD VARIATION) ===\n\n");

    displaySet(A, "Initialization of Set:");

    // insertion at first bucket
    insert(A, 5);
    insert(A, 1);
    insert(A, 12);
    insert(A, 20);
    insert(A, 31);

    // insertion at second bucket
    insert(A, 32);
    insert(A, 44);
    insert(A, 46);
    insert(A, 56);
    insert(A, 63);

    // inserting at invalid
    insert(A, -1);
    insert(A, 64);

    displaySet(A, "After insertion:");

    // simulating successful deletion
    deleteElem(A, 12);
    displaySet(A, "After successful deletion of 12:");

    // simulating unsuccessful deletion
    deleteElem(A, 62);
    displaySet(A, "After unsuccessful deletion:");

    // Simulating Union, Intersection, and Difference of Sets
    SET B;
    initSet(B);
    displaySet(B, "Initialization of Set B");

    insert(B, 1);
    insert(B, 44);
    insert(B, 0);
    insert(B, 13);
    insert(B, 25);
    insert(B, 20);
    insert(B, 38);
    insert(B, 41);

    displaySet(A, "Set A:");
    displaySet(B, "Set B:");

    SET* C = Union(A, B);
    displaySet(*C, "Union of Set A and Set B:");

    SET* D = Intersection(A, B);
    displaySet(*D, "Intersection of Set A and Set B");

    SET* E = Difference(A, B);
    displaySet(*E, "Difference of Set A and Set B");

    return 0;
}