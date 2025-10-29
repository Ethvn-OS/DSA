#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define EMPTY -999999
#define DELETED -88888888

/*
--> Data Type Definitions <------------------------------------------
*/

typedef int Dictionary[MAX];

/*
--> Function Prototypes <--------------------------------------------
*/

// Dictionary Functions
void insert(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
bool member(Dictionary D, int elem);

// Hash Function
int hash(int elem);

// Basic Essential Functions
void initDict(Dictionary D);
void printDict(Dictionary D, char* label);

/*
--> Function Definitions <--------------------------------------------
*/

int hash(int elem) {
    return elem % 10;
}

void initDict(Dictionary D) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        D[ctr] = EMPTY;
    }
}

void printDict(Dictionary D, char* label) {
    printf("%s\n", label);
    int ctr;
    printf("Elements: ");
    for (ctr = 0; ctr < MAX; ctr++) {
        if (D[ctr] != EMPTY || D[ctr] != DELETED) {
            printf("%d ", D[ctr]);
        }
    }
    printf("\n\n");
}

void insert(Dictionary D, int elem) {
    int hashVal = hash(elem);
    if (D[hashVal] == EMPTY) {
        D[hashVal] = elem;
    } else {
        int ctr;
        for (ctr = (hashVal+1) % MAX; ctr != hashVal && D[ctr] != EMPTY; ctr = (ctr+1) % MAX) {}
        if (ctr != hashVal) {
            D[ctr] = elem;
        } else {
            int ndx = 0;
            for (; ndx < MAX && D[ctr] != DELETED; ctr = (ctr+1) % MAX, ndx++) {}
            if (ndx < MAX) {
                D[ctr] = elem;
            } else {
                printf("Dictionary is full. Cannot insert element %d.\n", elem);
            }
        }
    }
}

void deleteElem(Dictionary D, int elem) {
    int hashVal = hash(elem),
        ctr;
    if (D[hashVal] != elem) {
        for (ctr = (hashVal+1) % MAX; ctr != hashVal && D[ctr] != elem && D[ctr] != EMPTY; ctr = (ctr+1) % MAX) {}
        if (ctr != hashVal && D[ctr] == elem) {
            D[ctr] = DELETED;
        }
    } else {
        D[hashVal] = DELETED;
    }
}

bool member(Dictionary D, int elem) {
    int hashVal = hash(elem),
        ctr;
    bool retval = false;
    if (D[hashVal] != elem) {
        for (ctr = (hashVal+1) % MAX; ctr != hashVal && D[ctr] != elem && D[ctr] != EMPTY; ctr = (ctr+1) % MAX) {}
        if (ctr != hashVal && D[ctr] == elem) {
            retval = true;
        }
    } else {
        retval = true;
    }
    return retval;
}