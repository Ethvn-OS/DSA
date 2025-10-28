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
SET* FindFinalMovieList(SET Alex, SET Blake, SET Casey);

int main() {
    SET Alex  = {1, 0, 0, 1, 0};
    SET Blake = {0, 1, 1, 0, 1};
    SET Casey = {0, 0, 1, 0, 1};

    SET* FinalList = FindFinalMovieList(Alex, Blake, Casey);

    printf("🎬 Final Movie Genres for Movie Night:\n");
    printf("(1 = include, 0 = exclude)\n");
    displaySet(*FinalList);

    free(FinalList);
    return 0;
}

// TODO: Implement this function
SET* FindFinalMovieList(SET Alex, SET Blake, SET Casey) {
    /*
       Your task:
       - Use set operations (Union, Intersection, etc.)
       - Return a SET where each element is 1 if that genre
         is liked by at least two friends, otherwise 0.

       Hint:
       Combine intersections and unions logically.
    */
    SET* D = Intersection(Alex, Blake);
    SET* C = Union(*D, Casey);
    return C;
}

// ====== SET OPERATION IMPLEMENTATIONS ======
SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++)
            (*C)[i] = A[i] || B[i];
    }
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++)
            (*C)[i] = A[i] && B[i];
    }
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++)
            (*C)[i] = A[i] && !B[i];
    }
    return C;
}

SET* Complement(SET A, SET U) {
    SET* C = (SET*)malloc(sizeof(SET));
    if (C != NULL) {
        for (int i = 0; i < MAX; i++)
            (*C)[i] = !A[i] && U[i];
    }
    return C;
}

void displaySet(SET S) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
}
