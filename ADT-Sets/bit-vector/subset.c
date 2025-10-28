#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int SET[MAX];

// Function prototypes
SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
int isSubset(SET A, SET B); // <-- You need to implement this!

void displaySet(SET S);

int main() {
    SET A = {1, 0, 1, 0, 0};
    SET B = {1, 1, 1, 1, 0};

    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    int result = isSubset(A, B); // TODO: Implement this function!

    if (result)
        printf("✅ A is a subset of B\n");
    else
        printf("❌ A is NOT a subset of B\n");

    return 0;
}

SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] || B[i];
        }
    }
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && B[i];
        }
    }
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && !B[i];
        }
    }
    return C;
}

// TODO: Implement this function
int isSubset(SET A, SET B) {
    // Your code here
    int ctr;
    for (ctr = 0; ctr < MAX && A[ctr] == 0 || B[ctr] == 1; ctr++) {}
    return (ctr < MAX) ? 0 : 1;
}

void displaySet(SET S) {
    printf("{ ");
    for (int i = 0; i < MAX; i++) {
        if (S[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}
