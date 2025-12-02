#include <stdio.h>
#include "bst.h"

int main() {
    int arr[MAX] = {10,3,15,1,8,4,9,18}; // These are the values to be stored in the nodes of the BST
    int ctr;
    BST S = NULL;

    // Inserting elements in the binary search tree
    for (ctr = 0; ctr < MAX; ctr++) {
        insertElem(&S, arr[ctr]);
    }

    // Displaying initial nodes of the BST
    printf("\nExpected Output: 1 3 4 8 9 10 15 18\n");
    printf("Actual Output: ");
    inOrder(S);
    printf("\n\n");

    // Deleting a node from the BST
    deleteElem(&S, 3); // just try changing this value to see if your deleteElem() function works
    printf("Expected Output: 1 4 8 9 10 15 18\n");
    printf("Actual Output: ");
    inOrder(S);
    printf("\n\n");

    // Testing member function
    bool catcher = isMember(S, 16);
    (catcher) ? printf("It is a member") : printf("It is not a member");
    printf("\n\n");

    // Testing min function
    int min = minElem(S);
    printf("The minimum element in the BST is %d\n", min);

    // Testing max function
    int max = maxElem(S);
    printf("The maximum element in the BST is %d\n\n", max);

    return 0;
}