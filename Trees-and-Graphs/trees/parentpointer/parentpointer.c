#include <stdio.h>
#include "parentpointer.h"

int main() {
    Tree T = {5,6,5,6,1,-1,5,1,2,-2};

    printf("\n-- PREORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 5 0 2 8 6 1 4 7 3\n");
    printf("Actual Output: ");
    PREORDER(ROOT(T), T);

    printf("\n\n-- INORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 0 5 8 2 4 1 7 6 3\n");
    printf("Actual Output: ");
    INORDER(ROOT(T), T);

    printf("\n\n-- POSTORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 0 8 2 4 7 1 3 6 5\n");
    printf("Actual Output: ");
    POSTORDER(ROOT(T), T);
    printf("5");

    printf("\n\n");

    return 0;
}