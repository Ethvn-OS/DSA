#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node {
    int elem;
    struct node* link;
} Nodetype, *LIST;

typedef LIST Dictionary[MAX];

/*
-- Function Prototypes --
*/

void initDictionary(Dictionary A);
void printDictionary(Dictionary A, char* label);
void insertElem(Dictionary A, int elem);
void deleteElem(Dictionary A, int elem);
bool member(Dictionary A, int elem);

int hash(int elem); // hash function that will return a hash value

/*
-- Function Definitions --
*/

// returns a hash value to the calling function
int hash(int elem) {
    return elem % 10;
}

void initDictionary(Dictionary A) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        A[ctr] = NULL;
    }
}

void printDictionary(Dictionary A, char* label) {
    printf("\n%s\n", label);
    LIST* ptr;
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        printf("Index %d: ", ctr);
        for (ptr = A+ctr; *ptr != NULL; ptr = &(*ptr)->link) {
            printf("%d ", (*ptr)->elem);
        }
        printf("\n");
    }
}

void insertElem(Dictionary A, int elem) {
    int hashVal = hash(elem);
    LIST* ptr;
    for (ptr = A+hashVal; *ptr != NULL; ptr = &(*ptr)->link) {}
    LIST temp = (LIST)malloc(sizeof(Nodetype));
    if (temp != NULL) {
        temp->elem = elem;
        temp->link = NULL;
        *ptr = temp;
    }
}

void deleteElem(Dictionary A, int elem) {
    int hashVal = hash(elem);
    LIST* ptr;
    for (ptr = A+hashVal; *ptr != NULL && (*ptr)->elem != elem; ptr = &(*ptr)->link) {}
    if (*ptr != NULL) {
        LIST temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

bool member(Dictionary A, int elem) {
    int hashVal = hash(elem);
    LIST* ptr;
    for (ptr = A+hashVal; *ptr != NULL && (*ptr)->elem != elem; ptr = &(*ptr)->link) {}
    return (*ptr != NULL) ? true : false;
}