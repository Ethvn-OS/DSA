#include <stdio.h>
#include "dictionaryprac.h"

int main() {
    Dictionary D;
    initDict(D);

    insert(D, 18);
    insert(D, 21);
    insert(D, 38);
    insert(D, 52);
    insert(D, 99);
    insert(D, 59);

    printDict(D, "Dictionary after insertion:");

    deleteElem(D, 99); // deleting elem not in own hash bucket
    deleteElem(D, 21); // deleting elem in own hash bucket
    deleteElem(D, 59);
    deleteElem(D, 51);

    printDict(D, "Dictionary after deletion:");

    return 0;
}