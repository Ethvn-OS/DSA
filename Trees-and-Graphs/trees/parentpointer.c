#include <stdio.h>
#include "parentpointer.h"

int main() {
    Tree T = {5,6,5,6,1,-1,5,1,2,-2};

    printf("\n-- PREORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 5 0 2 8 6 1 4 7 3\n");
    printf("Actual Output: ");
    PREORDER(ROOT(T), T);

    return 0;
}