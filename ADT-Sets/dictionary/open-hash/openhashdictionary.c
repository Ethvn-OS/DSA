#include <stdio.h>
#include <stdlib.h>
#include "openhashdictionary.h"

int main() {
    Dictionary D;
    initDictionary(D);

    int ctr;
    int arr[9] = {0,13,20,28,30,33,45,48,108};    // This is the set A that needs to be stored inside an open hash table

    for (ctr = 0; ctr < 9; ctr++) {
        insertElem(D, arr[ctr]);
    }

    printDictionary(D, "Dictionary after insertion of elements");

    deleteElem(D, 30);

    printDictionary(D, "Dictionary after deletion of element");

    bool isMember = member(D,20);

    printf("\nChecking if an element is a member of the dictionary\n");

    if (isMember) {
        printf("This element is a member of the dictionary.");
    } else {
        printf("This element is NOT a member of the dictionary.");
    }

    return 0;
}