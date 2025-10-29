#include <stdio.h>
#include "openhashstring.h"

int main() {
    Dictionary D;
    initDict(D);

    insert(D, "Ana");
    insert(D, "Bob");
    insert(D, "Zoe");
    insert(D, "Noah");
    insert(D, "Liam");
    insert(D, "Emma");
    insert(D, "Eva");
    insert(D, "Mia");
    insert(D, "Lucas");
    insert(D, "Sofia");
    insert(D, "Ian");
    insert(D, "Lily");
    insert(D, "Owen");
    insert(D, "Ava");

    displayDict(D, "After insertion of names:");

    deleteName(D, "Owen");
    deleteName(D, "Ana");
    deleteName(D, "Calunod");

    displayDict(D, "After deletion of names:");

    return 0;
}