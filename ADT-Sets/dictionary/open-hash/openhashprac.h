#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

/*
--> Data Type Definitions <-------------------------------------
*/

typedef struct node {
    int elem;
    struct node* next;
} Nodetype, *LIST;

typedef LIST Dictionary[MAX];

/*
--> Function Prototypes <---------------------------------------
*/

// Essential Dictionary Functions
void insert(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
bool member(Dictionary D, int elem);

// Hash Function
int hash(int elem); // will return the remainder when the sum of all the digits of x is divided by 19

// Basic Essential Functions
void displayDict(Dictionary D, char* label);
void initDict(Dictionary D);

/*
--> Function Definitions <---------------------------------------
*/

void displayDict(Dictionary D, char* label) {
    printf("\n%s\n\n", label);
    int ctr;
    LIST* ptr;
    for (ctr = 0; ctr < MAX; ctr++) {
        printf("Index %d: ", ctr);
        for (ptr = D+ctr; *ptr != NULL; ptr = &(*ptr)->next) {
            printf("%d ", (*ptr)->elem);
        }
        printf("\n");
    }
    printf("\n");
}

void initDict(Dictionary D) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        D[ctr] = NULL;
    }
}

int hash(int elem) {
    int sum = 0,
        rem;
    while (elem != 0) {
        rem = elem % 10;
        sum += rem;
        elem /= 10;
    }
    return sum % 19;
}

void insert(Dictionary D, int elem) {
    int hashVal = hash(elem);
    LIST* ptr;
    for (ptr = D+hashVal; *ptr != NULL; ptr = &(*ptr)->next) {}
    LIST temp = (LIST)malloc(sizeof(Nodetype));
    if (temp != NULL) {
        temp->elem = elem;
        temp->next = *ptr;
        *ptr = temp;
        printf("Successfully inserted element %d.\n", elem);
    } else {
        printf("Cannot insert element %d.\n", elem);
    }
}

void deleteElem(Dictionary D, int elem) {
    int hashVal = hash(elem);
    LIST* ptr;
    for (ptr = D+hashVal; *ptr != NULL && (*ptr)->elem != elem; ptr = &(*ptr)->next) {}
    if (*ptr != NULL) {
        LIST temp = *ptr;
        *ptr = temp->next;
        free(temp);
        printf("Successfully deleted element %d.\n", elem);
    } else {
        printf("Could not locate element %d.\n", elem);
    }
}

bool member(Dictionary D, int elem) {
    int hashVal = hash(elem);
    LIST ptr;
    for (ptr = D[hashVal]; ptr != NULL && ptr->elem != elem; ptr = ptr->next) {}
    return (ptr != NULL) ? true : false;
}

// void initDict(Dictionary D) {
//     int ctr;
//     for (ctr = 0; ctr < MAX; ctr++) {
//         D[ctr] = NULL;
//     }
// }

// int hash(int elem) {
//     int temp = elem,
//         sum = 0,
//         rem;

//     while (temp != 0) {
//         rem = temp % 10;
//         sum += rem;
//         temp /= 10;
//     }

//     return sum % 19;
// }

// void insert(Dictionary D, int elem) {
//     int hashVal = hash(elem);
//     LIST* ptr = D+hashVal;
//     LIST temp = (LIST)malloc(sizeof(Nodetype));
//     if (temp != NULL) {
//         temp->elem = elem;
//         temp->next = *ptr;
//         *ptr = temp;
//         printf("Successfully inserted element %d.\n", elem);
//     } else {
//         printf("Cannot insert element %d.\n", elem);
//     }
// }

// void deleteElem(Dictionary D, int elem) {
//     int hashVal = hash(elem);
//     LIST* ptr;
//     for (ptr = D+hashVal; *ptr != NULL && (*ptr)->elem != elem; ptr = &(*ptr)->next) {}
//     if (*ptr != NULL) {
//         LIST temp = *ptr;
//         *ptr = temp->next;
//         free(temp);
//         printf("Successfully deleted element %d.\n", elem);
//     } else {
//         printf("Could not locate element %d.\n", elem);
//     }
// }

// bool member(Dictionary D, int elem) {
//     int hashVal = hash(elem);
//     LIST ptr;
//     for (ptr = D[hashVal]; ptr != NULL && ptr->elem != elem; ptr = ptr->next) {}
//     return (ptr != NULL) ? true : false;
// }