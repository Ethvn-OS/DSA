#include <stdio.h>
#define MAX 5

/*
--> Data Type Definitions <------------------------------------------
*/

typedef int Node;

typedef struct {
    Node leftChild;
    Node rightChild;
} NodeChild;

typedef NodeChild Tree[MAX]; // This is a binary tree definition

/*
--> Function Prototypes <--------------------------------------------
*/

void CREATE(Tree T);
void MAKENULL(Tree T);
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

void CREATE(Tree T)
{
    T[0].leftChild = 1;
    T[0].rightChild = -1;
    T[1].leftChild = 2;
    T[1].rightChild = 3;
    T[2].leftChild = -3; // imaginary left child
    T[2].rightChild = 4;
    T[3].leftChild = -1;
    T[3].rightChild = -1;
    T[4].leftChild = -1;
    T[4].rightChild = -1;
}

void MAKENULL(Tree T)
{
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        T[ctr].leftChild = -1;
        T[ctr].rightChild = -1;
    }
}

Node PARENT(Node N, Tree T)
{
    int ctr;
    for (ctr = 0; ctr < MAX && T[ctr].leftChild != N || T[ctr].rightChild != N; ctr++) {}
    return (ctr < MAX) ? ctr : -2;
}

Node LEFTMOST_CHILD(Node N, Tree T)
{
    return (N >= 0 && T[N].leftChild != -1) ? T[N].leftChild : -2;
}

Node RIGHT_SIBLING(Node N, Tree T)
{
    int ctr;
    for (ctr = 0; ctr < MAX && T[ctr].leftChild != N; ctr++) {}
    return (ctr < MAX && T[ctr].rightChild != -1) ? T[ctr].rightChild : -2;
}

Node LABEL(Node N, Tree T)
{
    return N;
}

Node ROOT(Tree T)
{
    return 0;
}

void PREORDER(Node N, Tree T)
{
    if (N != -3) printf("%d ", N);
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
        if (N != -3) printf("%d ", N);
    } else {
        INORDER(LEFTMOST_CHILD(N, T), T);
        if (N != -3) printf("%d ", N);
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
        if (child != -3) printf("%d ", child);
        child = RIGHT_SIBLING(child, T);
    }
}