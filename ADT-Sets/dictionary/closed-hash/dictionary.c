//Program to get the average search length of all the elements in the closed hash dictionary
//Programmer: Ethan Andre O. Dalocanog
//Date Created: September 25, 2025

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY -2
#define DELETED -3

typedef char Dictionary[10];

void initDictionary(Dictionary* D);
void printDic(Dictionary D);
int insert(Dictionary* D, char elem, int hash);
void delete(Dictionary* D, int hash);
int getSearchLen(int actualLoc, int hash);

int main() {
    int sum = 0;
    Dictionary D;
    initDictionary(&D);
    printDic(D);

    int SL1 = insert(&D, 'A', 1);
    sum += SL1;
    printDic(D);

    int SL2 = insert(&D, 'B', 4);
    sum += SL2;
    printDic(D);

    int SL3 = insert(&D, 'C', 9);
    sum += SL3;
    printDic(D);

    int SL4 = insert(&D, 'D', 9);
    sum += SL4;
    printDic(D);

    int SL5 = insert(&D, 'E', 0);
    sum += SL5;
    printDic(D);

    int SL6 = insert(&D, 'F', 3);
    sum += SL6;
    printDic(D);

    int SL7 = insert(&D, 'G', 4);
    sum += SL7;
    printDic(D);

    int SL8 = insert(&D, 'H', 3);
    sum += SL8;
    printDic(D);

    float ave = (float)sum / (float)8;

    printf("\nAverage Search Length of all 8 Elements: %.2f\n\n", ave);

    delete(&D, 3);
    printDic(D);

    int SL9 = insert(&D, 'Z', 3);
    printDic(D);

    int SL10 = insert(&D, 'Y', 3);
    printDic(D);

    int SL11 = insert(&D, 'J', 7);
    printDic(D);

    int SL12 = insert(&D, 'K', 7);
    printDic(D);

    return 0;
}

void initDictionary(Dictionary* D) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        (*D)[ctr] = EMPTY;
    }
}

void printDic(Dictionary D) {
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        printf("%c ", D[ctr]);
    }
    printf("\n");
}

int insert(Dictionary* D, char elem, int hash) {
    int ctr;
    if ((*D)[hash] == EMPTY) {
        ctr = hash;
        (*D)[ctr] = elem;
    } else {
        for (ctr = (hash + 1) % MAX; ctr != hash && (*D)[ctr] != EMPTY; ctr = (ctr + 1) % MAX) {}
        if (ctr != hash) {
            (*D)[ctr] = elem;
        } else {
            int ndx = 0;
            for (ctr = hash; ndx < MAX && (*D)[ctr] != DELETED; ctr = (ctr+1) % MAX, ndx++) {}
            if (ndx < MAX) {
                (*D)[ctr] = elem;
            } else {
                printf("The dictionary is full.\n");
            }
        }
    }
    int searchLen = getSearchLen(ctr, hash);
    return searchLen;
}

void delete(Dictionary* D, int hash) {
    if ((*D)[hash] != EMPTY) {
        (*D)[hash] = DELETED;
    }
}

int getSearchLen(int actualLoc, int hash) {
    return (actualLoc - hash + MAX + 1) % MAX;
}