#include <stdio.h>
#define MAX 10

/*
--> Data Type Definitions <------------------------------------------
*/

typedef int Node;
typedef Node Tree[MAX];

/*
--> Function Prototypes <--------------------------------------------
*/

// NOTE: LEFTMOST_CHILD() and RIGHT_SIBLING() only work if there is artificial ordering of nodes
// For this parent pointer representation of trees, assume that the tree is artificially ordered
// This is still missing the CREATE() and MAKENULL() functions because idk how to do that

Node PARENT(Node N, Tree T);
Node LEFTMOST_CHILD(Node N, Tree T);
Node RIGHT_SIBLING(Node N, Tree T);
Node LABEL(Node N, Tree T);
Node ROOT(Tree T);
void PREORDER(Node N, Tree T);
void INORDER(Node N, Tree T);
void POSTORDER(Node N, Tree T);

/*
--> Function Definitions <-------------------------------------------
*/

Node PARENT(Node N, Tree T)
{
    return T[N];
}

Node LEFTMOST_CHILD(Node N, Tree T)
{
    int ctr;
    for (ctr = 0; ctr < MAX && T[ctr] != N; ctr++) {}
    if (ctr < MAX) {
        return ctr;
    } else {
        return -2;
    }
}

Node RIGHT_SIBLING(Node N, Tree T)
{
    int ctr;
    Node P = PARENT(N, T);
    for (ctr = N+1; ctr < MAX && T[ctr] != P; ctr++) {}
    if (ctr < MAX) {
        return ctr;
    } else {
        return -2;
    }
}

Node LABEL(Node N, Tree T)
{
    return N;
}

Node ROOT(Tree T)
{
    int ctr;
    for (ctr = 0; ctr < MAX && T[ctr] != -1; ctr++) {}
    if (ctr < MAX) {
        return ctr;
    }
}

void PREORDER(Node N, Tree T)
{
    /*

    Code I originally made:

    printf("%d ", N);
    if (LEFTMOST_CHILD(N, T) != -2) {
        PREORDER(LEFTMOST_CHILD(N, T), T);
    } else {
        if (RIGHT_SIBLING(N, T) != -2) {
            PREORDER(RIGHT_SIBLING(N, T), T);
        } else if (RIGHT_SIBLING(PARENT(N, T), T) != -2) {
            PREORDER(RIGHT_SIBLING(PARENT(N, T), T), T);
        }
    }

    Then, I asked Copilot to optimize it and got:
    */

    // Code made with the help of Copilot
    printf("%d ", N);
    Node child = LEFTMOST_CHILD(N, T);
    while (child != -2) {
        PREORDER(child, T);
        child = RIGHT_SIBLING(child, T);
    }
}

void INORDER(Node N, Tree T)
{
    Node child;
    if (LEFTMOST_CHILD(N, T) == -2) {
        printf("%d ", N);
    } else {
        INORDER(LEFTMOST_CHILD(N, T), T);
        printf("%d ", N);
        for (child = RIGHT_SIBLING(LEFTMOST_CHILD(N, T), T); child != -2; child = RIGHT_SIBLING(child, T)) {
            INORDER(child, T);
        }
    }
}

void POSTORDER(Node N, Tree T)
{
    Node child = LEFTMOST_CHILD(N, T);
    while (child != -2) {
        POSTORDER(child, T);
        printf("%d ", child);
        child = RIGHT_SIBLING(child, T);
    }
}