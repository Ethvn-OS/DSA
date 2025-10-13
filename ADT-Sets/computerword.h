#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//datatype definition of SET
typedef unsigned char SET;

/*

-- Function Prototypes --

*/

void initSet(SET* S);
void displaySet(SET S, char* label);
void insert(SET* S, int place);
bool member(SET S, int place);
void deleteElem(SET* S, int place);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);

/*

-- Function Definitions --

*/

void initSet(SET* S) {
    *S = 0;
}

void displaySet(SET S, char* label) {
    printf("\n%s:\n", label);
    int pos = 0;
    unsigned char mask = 1 << (sizeof(SET)*8 - 1);

    printf("Bit pattern: ");
    for (; mask != 0; mask >>= 1) {
        printf("%c ", (S & mask) == 0 ? '0' : '1');
    }

    printf("\nActual elements in the set: ");

    unsigned char limit = sizeof(SET)*8;

    printf("{ ");
    for (mask = 1; pos < limit; mask <<= 1, pos++) {
        if ((S & mask) != 0) {
            printf("%d ", pos);
        }
    }
    printf("}");
    printf("\n");
}

void insert(SET* S, int place) {
    unsigned char mask = 1 << place;
    *S = *S | mask;
}

bool member(SET S, int place) {
    unsigned char mask = 1 << place;
    return (S & mask) == 0 ? false : true;
}

void deleteElem(SET* S, int place) {
    unsigned char mask = 1 << place;
    *S = *S & ~mask;
}

SET Union(SET A, SET B) {
    return A | B;
}

SET Intersection(SET A, SET B) {
    return A & B;
}

SET Difference(SET A, SET B) {
    return A & ~B;
}