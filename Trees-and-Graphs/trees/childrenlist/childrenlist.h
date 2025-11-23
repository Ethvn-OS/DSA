#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
--> Data Type Definitions <------------------------------------------
*/

typedef int Node;

typedef struct node {
    Node data;
    struct node* next;
} Nodetype, *Nodeptr;

typedef struct {
    Nodeptr Tree[MAX];
    Node root;
} TreeType;

/*
--> Function Prototypes <--------------------------------------------
*/

// NOTE: LEFTMOST_CHILD() and RIGHT_SIBLING() only work if there is artificial ordering of nodes
// For this parent pointer representation of trees, assume that the tree is artificially ordered
// This is still missing the CREATE() and MAKENULL() functions because idk how to do that

TreeType CREATE();
void MAKENULL(TreeType* T);
Node PARENT(Node N, TreeType T);
Node LEFTMOST_CHILD(Node N, TreeType T);
Node RIGHT_SIBLING(Node N, TreeType T);
Node LABEL(Node N, TreeType T);
Node ROOT(TreeType T);
void PREORDER(Node N, TreeType T);
void INORDER(Node N, TreeType T);
void POSTORDER(Node N, TreeType T);

// Helper Functions
void insertLast(Node elem, Nodeptr* T);

/*
--> Function Definitions <-------------------------------------------
*/

void insertLast(Node elem, Nodeptr* T)
{
    Nodeptr* A;
    for (A = T; *A != NULL; A = &(*A)->next) {}
    Nodeptr temp = (Nodeptr)malloc(sizeof(Nodetype));
    if (temp != NULL) {
        temp->data = elem;
        temp->next = *A;
        *A = temp;
    }
}

TreeType CREATE()
{
    TreeType T;
    MAKENULL(&T);
    T.root = 5;

    Nodeptr* ptr = T.Tree+1;
    insertLast(4, ptr);
    insertLast(7, ptr);

    ptr = T.Tree+2;
    insertLast(8, ptr);

    ptr = T.Tree+5;
    insertLast(0, ptr);
    insertLast(2, ptr);
    insertLast(6, ptr);

    ptr = T.Tree+6;
    insertLast(1, ptr);
    insertLast(3, ptr);

    return T;
}

void MAKENULL(TreeType* T)
{
    int ctr;
    for (ctr = 0; ctr < MAX; ctr++) {
        T->Tree[ctr] = NULL;
    }
}

Node PARENT(Node N, TreeType T)
{
    int ctr,
        flag = 0;
    Nodeptr* ptr;
    for (ctr = 0; ctr < MAX && flag != 1; ctr++) {
        for (ptr = T.Tree+ctr; *ptr != NULL && (*ptr)->data != N; ptr = &(*ptr)->next) {}
        if (*ptr != NULL) {
            flag = 1;
        }
    }
    if (ctr == MAX) {
        ctr = -2;
    }
    return ctr;
}

Node LEFTMOST_CHILD(Node N, TreeType T)
{
    Node retval = -2;
    Nodeptr ptr = T.Tree[N];
    if (ptr != NULL) {
        retval = ptr->data;
    }
    return retval;
}

Node RIGHT_SIBLING(Node N, TreeType T)
{
    Node retval = -2;
    int ctr;
    Nodeptr ptr;
    for (ctr = 0; ctr < MAX; ctr++) {
        for (ptr = T.Tree[ctr]; ptr != NULL && ptr->data != N; ptr = ptr->next) {}
        if (ptr != NULL) {
            break;
        }
    }
    if (ctr < MAX) {
        if (ptr->next != NULL) {
            retval = ptr->next->data;
        }
    }
    return retval;
}

Node LABEL(Node N, TreeType T)
{
    return N;
}

Node ROOT(TreeType T)
{
    return T.root;
}

void PREORDER(Node N, TreeType T)
{
    printf("%d ", N);
    Node child = LEFTMOST_CHILD(N, T);
    while (child != -2) {
        PREORDER(child, T);
        child = RIGHT_SIBLING(child, T);
    }
}

void INORDER(Node N, TreeType T)
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

void POSTORDER(Node N, TreeType T)
{
    Node child = LEFTMOST_CHILD(N, T);
    while (child != -2) {
        POSTORDER(child, T);
        printf("%d ", child);
        child = RIGHT_SIBLING(child, T);
    }
}