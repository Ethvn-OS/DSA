#include <stdio.h>
#include <stdlib.h>

/*
-- Datatype definition of SET --
*/

typedef struct node {
    int elem;
    struct node* next;
} Nodetype, *SET;

/*
-- Function Prototypes --
*/

//basic essential functions
void initSET(SET* S);
void printSET(SET S);

//use for unsorted sets
void insertUnique(SET* S, int elem);
SET UnionUnsorted(SET A, SET B);
SET IntersectionUnsorted(SET A, SET B);
SET DifferenceUnsorted(SET A, SET B);

//use for sorted sets
void insertSortedUnique(SET* S, int elem);
SET UnionSorted(SET A, SET B);
SET IntersectionSorted (SET A, SET B);
SET DifferenceSorted(SET A, SET B);

/*
-- Function Definitions --
*/

/*
-- Definitions of Basic Essential Functions --
*/
void initSET(SET* S) {
    *S = NULL;
}

void printSET(SET S) {
    SET ptr;
    for (ptr = S; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->elem);
    }
}

/*
-- These functions are for unsorted sets
*/
void insertUnique(SET* S, int elem) {
    SET* ptr;
    for (ptr = S; *ptr != NULL && (*ptr)->elem != elem; ptr = &(*ptr)->next) {}
    if (*ptr == NULL) {
        SET temp = (SET)malloc(sizeof(Nodetype));
        if (temp != NULL) {
            temp->elem = elem;
            temp->next = NULL;
            *ptr = temp;
        }
    }
}

SET UnionUnsorted(SET A, SET B) {
    SET C,
        aptr = A,
        bptr = B;
    initSET(&C);
    SET* cptr = &C;
    for (; aptr != NULL; aptr = aptr->next) {
        *cptr = (SET)malloc(sizeof(Nodetype));
        if (*cptr != NULL) {
            (*cptr)->elem = aptr->elem;
            cptr = &(*cptr)->next;
        }
    }

    for (; bptr != NULL; bptr = bptr->next) {
        for (aptr = A; aptr != NULL && aptr->elem != bptr->elem; aptr = aptr->next) {}
        if (aptr == NULL) {
            *cptr = (SET)malloc(sizeof(Nodetype));
            if (*cptr != NULL) {
                (*cptr)->elem = bptr->elem;
                cptr = &(*cptr)->next;
            }
        }
    }
    *cptr = NULL;
    return C;
}

SET IntersectionUnsorted(SET A, SET B) {
    //insert code here
}

SET DifferenceUnsorted(SET A, SET B) {
    //insert code here
}

/*
-- These functions are for sorted sets --
*/
void insertSortedUnique(SET* S, int elem) {
    SET* ptr;
    for (ptr = S; *ptr != NULL && (*ptr)->elem < elem; ptr = &(*ptr)->next) {}
    if (*ptr == NULL || (*ptr)->elem != elem) {
        SET temp = (SET)malloc(sizeof(Nodetype));
        if (temp != NULL) {
            temp->elem = elem;
            temp->next = *ptr;
            *ptr = temp;
        }
    }
}

// function for sorted union
SET UnionSorted(SET A, SET B) {
    SET C,
        aptr = A,
        bptr = B;
    initSET(&C);
    SET* cptr = &C;

    while (aptr != NULL && bptr != NULL) {
        *cptr = (SET)malloc(sizeof(Nodetype));
        if (*cptr != NULL) {
            if (aptr->elem < bptr->elem) {
                (*cptr)->elem = aptr->elem;
                aptr = aptr->next;
            } else {
                if (aptr->elem == bptr->elem) {
                    aptr = aptr->next;
                }
                (*cptr)->elem = bptr->elem;
                bptr = bptr->next;
            }
            cptr = &(*cptr)->next;
        }
    }

    if (bptr != NULL) {
        aptr = bptr;
    }

    while (aptr != NULL) {
        *cptr = (SET)malloc(sizeof(Nodetype));
        if (*cptr != NULL) {
            (*cptr)->elem = aptr->elem;
            aptr = aptr->next;
        }
        cptr = &(*cptr)->next;
    }

    *cptr = NULL;

    return C;
}

// function for sorted intersection
SET IntersectionSorted (SET A, SET B) {
    SET C,
        aptr = A,
        bptr = B;
    initSET(&C);
    SET* cptr;

    for (cptr = &C; aptr != NULL && bptr != NULL;) {

        if (aptr->elem == bptr->elem) {
            (*cptr) = (SET)malloc(sizeof(Nodetype));
            if (*cptr != NULL) {
                (*cptr)->elem = aptr->elem;
            }
            aptr = aptr->next;
            cptr = &(*cptr)->next;
        } else if (aptr->elem < bptr->elem) {
            aptr = aptr->next;
        } else if (bptr->elem < aptr->elem) {
            bptr = bptr->next;
        }
    }

    *cptr = NULL;

    return C;
}

// function for sorted difference
SET DifferenceSorted(SET A, SET B) {
    SET C,
        aptr = A,
        bptr = B;
    initSET(&C);
    SET* cptr;

    for (cptr = &C; aptr != NULL && bptr != NULL; ) {
        if (aptr->elem != bptr->elem) {
            if (aptr->elem < bptr->elem) {
                *cptr = (SET)malloc(sizeof(Nodetype));
                if (*cptr != NULL) {
                    (*cptr)->elem = aptr->elem;
                    aptr = aptr->next;
                    cptr = &(*cptr)->next;
                }
            } else {
                bptr = bptr->next;
            }
        } else {
            aptr = aptr->next;
            bptr = bptr->next;
        }
    }

    for (; aptr != NULL; aptr = aptr->next, cptr = &(*cptr)->next) {
        *cptr = (SET)malloc(sizeof(Nodetype));
        if (*cptr != NULL) {
            (*cptr)->elem = aptr->elem;
        }
    }

    *cptr = NULL;

    return C;
}