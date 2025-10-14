/*

This program will perform UID operations on Unsorted and Sorted Sets implemented using Linked List.

Programmer: Ethan Andre O. Dalocanog
Date Created: September 28, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include "LLSet.h"

int main() {
    int countA,
        countB,
        ctr,
        elem;
    SET A,
        B;

    initSET(&A);
    initSET(&B);

    //Populating the SETS
    printf("How many elements will Set A have? ");
    scanf("%d", &countA);
    printf("How many elements will Set B have? ");
    scanf("%d", &countB);

    printf("\nPopulating Set A:\n");
    for (ctr = 0; ctr < countA; ctr++) {
        printf("Input data %d: ", ctr+1);
        scanf("%d", &elem);
        insertUnique(&A, elem);
    }

    printf("\nPopulating Set B:\n");
    for (ctr = 0; ctr < countB; ctr++) {
        printf("Input data %d: ", ctr+1);
        scanf("%d", &elem);
        insertUnique(&B, elem);
    }

    printf("\nSet A:\n");
    printSET(A);

    printf("\nSet B:\n");
    printSET(B);

    SET C = UnionUnsorted(A, B);

    printf("\n\nUnion of Set A and Set B\n");
    printSET(C);
/*
    SET D = IntersectionUnsorted(A,B);

    printf("\n\nIntersection of Set A and Set B\n");
    printSET(D);

    SET E = DifferenceUnsorted(A,B);

    printf("\n\nDifference of Set A and Set B\n");
    printSET(E);
*/
    return 0;
}