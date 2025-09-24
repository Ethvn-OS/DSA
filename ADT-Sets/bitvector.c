#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int SET[MAX];

SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);

int main() {
    int ctr;

    SET A = {1, 1, 1, 1, 1};
    SET B = {1, 1, 0, 1, 0};
    SET* C = Difference(A, B);

    for (ctr = 0; ctr < MAX; ctr++) {
        printf("Data: %d\n", (*C)[ctr]);
    }

    return 0;
}

SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int ctr;
        for (ctr = 0; ctr < MAX; ctr++) {
            (*C)[ctr] = A[ctr] || B[ctr];
        }
    }
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int ctr;
        for (ctr = 0; ctr < MAX; ctr++) {
            (*C)[ctr] = A[ctr] && B[ctr];
        }
    }
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        int ctr;
        for (ctr = 0; ctr < MAX; ctr++) {
            (*C)[ctr] = A[ctr] && !B[ctr];
        }
    }
}