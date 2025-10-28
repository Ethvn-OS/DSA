#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SET_LENGTH 2

typedef unsigned int SET[SET_LENGTH]; //0 - 31 in index 0 && 32 - 63 in index 1

/*
--> Function Prototypes
*/

void initSet(SET S);
void displaySet(SET S, char* label);
void insert(SET S, int pos);
bool member(SET S, int pos);
void deleteElem(SET S, int pos);
SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);

/*
--> Function Definitions
*/

void initSet(SET S) {
    S[0] = 0;
    S[1] = 0;
}

void displaySet(SET S, char* label) {
    printf("------------------------------------------------------------------------\n");
    printf("%s\n\n", label);
    int pos = 0;
    unsigned int mask = 1 << sizeof(int)*8-1;

    printf("Bit pattern of Bucket 1: ");
    for (; mask != 0; mask >>= 1) {
        printf("%d", (S[0] & mask) == 0 ? 0 : 1);
    }
    printf("\n");

    mask = 1 << sizeof(int)*8-1;

    printf("Bit pattern of Bucket 2: ");
    for (; mask != 0; mask >>= 1) {
        printf("%d", (S[1] & mask) == 0 ? 0 : 1);
    }
    printf("\n");

    printf("\nElements of the set:\n");
    printf("{ ");
    int ctr,
        check;

    for (ctr = 0; ctr < 2; ctr++) {
        check = (ctr == 0) ? 32 : 64;
        for (mask = 1; pos != check; mask <<= 1, pos++) {
            if ((S[ctr] & mask) != 0) {
                printf("%d ", pos);
            }
        }
    }

    printf("}");
    printf("\n------------------------------------------------------------------------\n\n");
}

void insert(SET S, int pos) {
    if (pos < 0 || pos > 63) {
        printf("Cannot insert element %d\n\n", pos);
    } else {
        unsigned int bucket = pos / (sizeof(int)*8);
        unsigned int bit = pos % (sizeof(int)*8);
        unsigned int mask = 1 << bit;

        S[bucket] |= mask;
        printf("Successfully inserted element %d\n\n", pos);
    }
}

bool member(SET S, int pos) {
    unsigned int bucket = pos / (sizeof(int)*8);
    unsigned int bit = pos % 32;
    unsigned int mask = 1 << bit;

    return ((S[bucket] & mask) == 0) ? false : true;
}

void deleteElem(SET S, int pos) {
    unsigned int bucket = pos / (sizeof(int)*8);
    unsigned int bit = pos % 32;
    unsigned int mask = 1 << bit;

    if (member(S, pos)) {
        S[bucket] = S[bucket] & ~mask;
        printf("Successfully deleted %d\n\n", pos);
    } else {
        printf("Element not found.\n\n");
    }
}

SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        (*C)[0] = A[0] | B[0];
        (*C)[1] = A[1] | B[1];
    }
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        (*C)[0] = A[0] & B[0];
        (*C)[1] = A[1] & B[1];
    }
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        (*C)[0] = A[0] & ~B[0];
        (*C)[1] = A[1] & ~B[1];
    }
    return C;
}