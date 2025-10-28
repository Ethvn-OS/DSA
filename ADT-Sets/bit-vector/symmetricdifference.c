#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int SET[MAX];

// Function prototypes
SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
SET* SymmetricDifference(SET A, SET B); // <-- You need to implement this!

void displaySet(SET S);

int main() {
    SET A = {1, 0, 1, 0, 1};
    SET B = {1, 1, 0, 0, 1};

    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    SET* C = SymmetricDifference(A, B); // TODO: Implement this function!

    printf("Symmetric Difference (A △ B): ");
    displaySet(*C);

    free(C);
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
SET* SymmetricDifference(SET A, SET B) {
    // Your code here
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int ctr;
        for (ctr = 0; ctr < MAX; ctr++) {
            (*C)[ctr] = A[ctr] && !B[ctr] || !A[ctr] && B[ctr];
        }
    }
    return C;
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