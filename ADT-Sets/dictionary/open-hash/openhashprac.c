#include <stdio.h>
#include "openhashprac.h"

int main() {
    Dictionary D;
    initDict(D);

    insert(D, 56);   // hash = 11
    insert(D, 88);   // hash = 16
    insert(D, 91);   // hash = 10
    insert(D, 123);  // hash = 6
    insert(D, 789);  // hash = 5
    insert(D, 902);  // hash = 11 (collision with 56)
    insert(D, 137);  // hash = 11 (collision with 56, 902)
    insert(D, 345);  // hash = 12

    displayDict(D, "After insertion of elements:");

    deleteElem(D, 88);
    deleteElem(D, 1);
    deleteElem(D, 136);
    deleteElem(D, 137);
    deleteElem(D, 902);

    displayDict(D, "After deletion of elements:");

    return 0;
}