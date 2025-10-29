#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50

/*
--> Data Type Definitions <-----------------------------------------
*/

typedef struct node {
    char* name;
    struct node* link;
} Nodetype, *LIST;

typedef LIST Dictionary[MAX];

/*
--> Function Prototypes <--------------------------------------------
*/

// Dictionary Functions
void insert(Dictionary D, char* name);
void deleteName(Dictionary D, char* name);
bool member(Dictionary D, char* name);

// Hash Function
int hash(char* name);

// Basic Essential Functions
void displayDict(Dictionary D, char* label);
void initDict(Dictionary D);

/*
--> Function Definitions <--------------------------------------------
*/

int hash(char* name) {
    int sum = 0,
        ctr;
    for (ctr = 0; name[ctr] != '\0'; ctr++) {
        sum += name[ctr];
    }
    return sum % 49;
}

void initDict(Dictionary D) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        D[ctr] = NULL;
    }
}

void displayDict(Dictionary D, char* label) {
    printf("\n%s\n\n", label);
    int ctr;
    LIST* ptr;
    for (ctr = 0; ctr < MAX; ctr++) {
        printf("Index %d: ", ctr);
        for (ptr = D+ctr; *ptr != NULL; ptr = &(*ptr)->link) {
            printf("%s ", (*ptr)->name);
        }
        printf("\n");
    }
    printf("\n");
}

void insert(Dictionary D, char* name) {
    int hashVal = hash(name);
    LIST* ptr = D+hashVal;
    LIST temp = (LIST)malloc(sizeof(Nodetype));
    if (temp != NULL) {
        temp->name = name;
        temp->link = *ptr;
        *ptr = temp;
    }
}

void deleteName(Dictionary D, char* name) {
    int hashVal = hash(name);
    LIST* ptr;
    for (ptr = D+hashVal; *ptr != NULL && strcmp((*ptr)->name, name) != 0; ptr = &(*ptr)->link) {}
    if (*ptr != NULL) {
        LIST temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

bool member(Dictionary D, char* name) {
    // insert code here
}