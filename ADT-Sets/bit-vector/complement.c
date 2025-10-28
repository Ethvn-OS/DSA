#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int SET[MAX];

// Function prototypes
SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
SET* Complement(SET A, SET U); // <-- You need to implement this!

void displaySet(SET S);

int main() {
    SET U = {1, 1, 1, 1, 1}; // Universal set: all elements are included
    SET A = {1, 0, 1, 0, 0};

    printf("Universal Set U: ");
    displaySet(U);
    printf("Set A: ");
    displaySet(A);

    SET* C = Complement(A, U); // TODO: Implement this function!

    printf("Complement of A (A′): ");
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
SET* Complement(SET A, SET U) {
    // Your code here
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int ctr;
        for (ctr = 0; ctr < MAX; ctr++) {
            (*C)[ctr] = U[ctr] && !A[ctr];
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
