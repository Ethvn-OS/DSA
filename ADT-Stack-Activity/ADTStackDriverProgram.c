#include <stdio.h>
//#include "ADTStackArray.h"
#include "ADTStackLinkedList.h"

int main() {
    Stacktype S;

    initStack(&S);
    pushStack(&S, 'C');
    pushStack(&S, 'S');
    pushStack(&S, 'U');

    printf("The initial data in the stack:\n");
    printStack(S);

    popStack(&S);

    printf("\nData after pop:\n");
    printStack(S);

    return 0;
}