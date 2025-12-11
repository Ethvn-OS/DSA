#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
===========================================
            STRUCT DEFINITIONS
===========================================
*/

typedef struct node {
    char label[20];      // node label (e.g., "R", "A", "L2")
    char data[10];       // operator ("+", "-", "*", "/") or number ("12")
    struct node* left;
    struct node* right;
} Node, *Tree;

/*
===========================================
        FUNCTION PROTOTYPES
===========================================
*/

// YOU implement this:
int evaluateTree(Tree root);

// Helpers already done:
Tree makeNode(const char* label, const char* data);

// Test case builders:
Tree buildTest1();   // (2 * 3) + 5
Tree buildTest2();   // 10 - (4 / 2)
Tree buildTest3();   // 7 + (6 * 2)
Tree buildTest4();   // (5 * (8 - 3)) + 1
Tree buildTest5();   // ((20 / 2) * (3 + 1)) - 7

/*
===========================================
                 MAIN
===========================================
*/

int main() {
    printf("===== EXPRESSION TREE TESTS =====\n\n");

    Tree T;
    int result;

    // TEST 1
    T = buildTest1();
    result = evaluateTree(T);
    printf("Test 1: (2 * 3) + 5 = %d   %s\n", result, (result == 11 ? "PASS" : "FAIL"));

    // TEST 2
    T = buildTest2();
    result = evaluateTree(T);
    printf("Test 2: 10 - (4 / 2) = %d   %s\n", result, (result == 8 ? "PASS" : "FAIL"));

    // TEST 3
    T = buildTest3();
    result = evaluateTree(T);
    printf("Test 3: 7 + (6 * 2) = %d   %s\n", result, (result == 19 ? "PASS" : "FAIL"));

    // TEST 4
    T = buildTest4();
    result = evaluateTree(T);
    printf("Test 4: (5 * (8 - 3)) + 1 = %d   %s\n", result, (result == 26 ? "PASS" : "FAIL"));

    // TEST 5
    T = buildTest5();
    result = evaluateTree(T);
    printf("Test 5: ((20 / 2) * (3 + 1)) - 7 = %d   %s\n",
           result, (result == 33 ? "PASS" : "FAIL"));

    return 0;
}

/*
===========================================
          FUNCTION YOU MUST DO
===========================================
*/

int evaluateTree(Tree root) {
    /*
       TODO: Implement this function.

       Rules:
       - If root->data is a number → return atoi(root->data)
       - Otherwise, it's an operator ("+", "-", "*", "/")
       - Recursively evaluate left & right children
       - Apply the operator

       Example guideline:
            if (strcmp(root->data, "+") == 0)
                return evaluateTree(root->left) + evaluateTree(root->right);
    */
    if (root->data[0] == '+') {
        return evaluateTree(root->left) + evaluateTree(root->right);
    } else if (root->data[0] == '-') {
        return evaluateTree(root->left) - evaluateTree(root->right);
    } else if (root->data[0] == '*') {
        return evaluateTree(root->left) * evaluateTree(root->right);
    } else if (root->data[0] == '/') {
        return evaluateTree(root->left) / evaluateTree(root->right);
    } else {
        return atoi(root->data);
    }
}

/*
===========================================
        TREE CREATION HELPER
===========================================
*/

Tree makeNode(const char* label, const char* data) {
    Tree t = malloc(sizeof(Node));
    strcpy(t->label, label);
    strcpy(t->data, data);
    t->left = t->right = NULL;
    return t;
}

/*
===========================================
                TEST CASE 1
          (2 * 3) + 5
===========================================
*/

Tree buildTest1() {
    Tree R = makeNode("R", "+");
    Tree A = makeNode("A", "*");
    Tree L1 = makeNode("L1", "2");
    Tree L2 = makeNode("L2", "3");
    Tree B = makeNode("B", "5");

    R->left = A;
    R->right = B;
    A->left = L1;
    A->right = L2;

    return R;
}

/*
===========================================
                TEST CASE 2
           10 - (4 / 2)
===========================================
*/

Tree buildTest2() {
    Tree R = makeNode("R", "-");
    Tree L = makeNode("L", "10");
    Tree A = makeNode("A", "/");
    Tree L1 = makeNode("L1", "4");
    Tree L2 = makeNode("L2", "2");

    R->left = L;
    R->right = A;
    A->left = L1;
    A->right = L2;

    return R;
}

/*
===========================================
                TEST CASE 3
             7 + (6 * 2)
===========================================
*/

Tree buildTest3() {
    Tree R = makeNode("R", "+");
    Tree L = makeNode("L", "7");
    Tree A = makeNode("A", "*");
    Tree L1 = makeNode("L1", "6");
    Tree L2 = makeNode("L2", "2");

    R->left = L;
    R->right = A;
    A->left = L1;
    A->right = L2;

    return R;
}

/*
===========================================
                TEST CASE 4
         (5 * (8 - 3)) + 1
===========================================
*/

Tree buildTest4() {
    Tree R = makeNode("R", "+");
    Tree A = makeNode("A", "*");
    Tree L1 = makeNode("L1", "5");
    Tree B = makeNode("B", "-");
    Tree C1 = makeNode("C1", "8");
    Tree C2 = makeNode("C2", "3");
    Tree D = makeNode("D", "1");

    R->left = A;
    R->right = D;

    A->left = L1;
    A->right = B;

    B->left = C1;
    B->right = C2;

    return R;
}

/*
===========================================
                TEST CASE 5
       ((20 / 2) * (3 + 1)) - 7
===========================================
*/

Tree buildTest5() {
    Tree R = makeNode("R", "-");

    Tree A = makeNode("A", "*");
    Tree B = makeNode("B", "/");
    Tree C = makeNode("C", "+");

    Tree L1 = makeNode("L1", "20");
    Tree L2 = makeNode("L2", "2");
    Tree L3 = makeNode("L3", "3");
    Tree L4 = makeNode("L4", "1");
    Tree L5 = makeNode("L5", "7");

    // Left subtree: (20 / 2) * (3 + 1)
    B->left = L1; B->right = L2;
    C->left = L3; C->right = L4;

    A->left = B;
    A->right = C;

    R->left = A;
    R->right = L5;

    return R;
}
