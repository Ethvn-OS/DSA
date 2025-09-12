#include <stdio.h>
//#include "ADTStackArray.h"
#include "ADTStackLinkedList.h"
//#include "ADTStackCursorBased.h"

int main() {
    Stacktype S;

    initialize(&S);
    push(&S, 'C');
    push(&S, 'S');
    push(&S, 'U');

    printf("The initial data in the stack:\n");
    printStack(S);

    pop(&S);

    printf("\nData after pop:\n");
    printStack(S);

    printf("\nData after inserting at bottom:\n");
    insertBottom(&S, 'x');
    printStack(S);

    return 0;
}