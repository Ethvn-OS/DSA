/*

This program will perform operations for the computer word variation
of bit-vector implementation.

Programmer: Ethan Andre O. Dalocanog
Date Created: September 29, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "computerword.h"

int main() {
    int place,
        count,
        ctr;
    bool checkMem;
    SET S,
        B;
    initSet(&S);        //initialization
    initSet(&B);        //initialization

    insert(&S, 2);
    insert(&S, 1);
    insert(&S, 4);
    insert(&S, 3);

    checkMem = member(S, 2);      //checks if element is a member of the set

    if (checkMem) {
        printf("%d is a member of the set.\n\n", 2);
    } else {
        printf("%d is not a member of the set.\n\n", 2);
    }

    deleteElem(&S, 3); //deletes an element in the set

    displaySet(S, "Set S after deletion");

    insert(&B, 2);
    insert(&B, 7);
    insert(&B, 3);
    insert(&B, 5);

    displaySet(S, "Set S");
    displaySet(B, "Set B");

    SET C = Union(S,B);           //getting the union between the two sets
    SET D = Intersection(S,B);    //getting the intersection between the two sets
    SET E = Difference(S,B);      //getting the difference between the two sets

    displaySet(C, "Union of Set S and B");
    displaySet(D, "Intersection of Set S and B");
    displaySet(E, "Difference of Set S and B");

    return 0;
}