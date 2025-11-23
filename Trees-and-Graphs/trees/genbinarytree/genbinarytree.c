#include <stdio.h>
#include "genbinarytree.h"

int main() {
    Tree T;
    MAKENULL(T);
    CREATE(T);

    printf("\n-- PREORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 0 1 2 4 3\n");
    printf("Actual Output: ");
    PREORDER(ROOT(T), T);

    printf("\n\n-- INORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 2 4 1 3 0\n");
    printf("Actual Output: ");
    INORDER(ROOT(T), T);

    printf("\n\n-- POSTORDER TRAVERSAL OF NODES --\n\n");
    printf("Expected Output: 4 2 3 1 0\n");
    printf("Actual Output: ");
    POSTORDER(ROOT(T), T);
    printf("%d", ROOT(T));

    printf("\n\n");

    return 0;
}