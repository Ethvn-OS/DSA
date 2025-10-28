#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int SET[MAX];

// Function prototypes
SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
SET* Complement(SET A, SET U);
void displaySet(SET S);

int main() {
    SET U = {1, 1, 1, 1, 1};          // Universal set
    SET A = {1, 0, 1, 0, 1};          // Example A = {0, 2, 4}
    SET B = {0, 1, 1, 0, 0};          // Example B = {1, 2}

    printf("Universal Set U: ");
    displaySet(U);
    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    // Step 1: A ∪ B
    SET* unionAB = Union(A, B);

    // Step 2: (A ∪ B)’  -> Complement of unionAB relative to U
    SET* compUnionAB = Complement(*unionAB, B);

    // Step 3: A – B
    SET* diffAB = Difference(A, B);

    // Step 4: (A ∪ B)’ ∩ (A – B)
    SET* result = Intersection(*compUnionAB, *diffAB);

    printf("\n(A ∪ B)’ ∩ (A – B): ");
    displaySet(*result);

    // Free allocated memory
    free(unionAB);
    free(compUnionAB);
    free(diffAB);
    free(result);

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

SET* Complement(SET A, SET U) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++) {
            (*C)[i] = U[i] && !A[i];
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
