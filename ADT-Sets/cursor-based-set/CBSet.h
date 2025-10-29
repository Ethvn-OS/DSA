#include <stdio.h>
#define MAX 100

/*
--> Data Type Definition <-----------------------------------------
*/

typedef struct {
    int elem;
    int link;
} Nodetype;

typedef struct {
    Nodetype Nodes[MAX];
    int Avail;
} VirtualHeap;

typedef int LIST;

/*
--> Function Prototypes <-------------------------------------------
*/

void initVirtualHeap(VirtualHeap* VH);
void initList(LIST* L);
void displaySet(VirtualHeap VH, LIST L, char* label);
void insertSortedUnique(VirtualHeap* VH, LIST* L, int elem);

// UID Functions
LIST UnionSorted(VirtualHeap* VH, LIST A, LIST B);
LIST IntersectionSorted(VirtualHeap* VH, LIST A, LIST B);
LIST DifferenceSorted(VirtualHeap* VH, LIST A, LIST B);

// Memory Management Functions
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap* VH, int ndx);

/*
--> Function Definitions <--------------------------------------------
*/

void initVirtualHeap(VirtualHeap* VH) {
    int ctr;
    VH->Avail = MAX-1;
    for (ctr = 0; ctr < MAX; ctr++) {
        VH->Nodes[ctr].link = ctr-1;
    }
}

void initList(LIST* L) {
    *L = -1;
}

void displaySet(VirtualHeap VH, LIST L, char* label) {
    int ctr;
    printf("%s\n", label);
    printf("{ ");
    for (ctr = L; ctr != -1; ctr = VH.Nodes[ctr].link) {
        printf("%d ", VH.Nodes[ctr].elem);
    }
    printf("}\n\n");
}

int allocSpace(VirtualHeap* VH) {
    int temp = VH->Avail;
    if (temp != -1) {
        VH->Avail = VH->Nodes[temp].link;
    }
    return temp;
}

void deallocSpace(VirtualHeap* VH, int ndx) {
    if (ndx >= 0 && ndx < MAX) {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void insertSortedUnique(VirtualHeap* VH, LIST* L, int elem) {
    int temp = allocSpace(VH);
    if (temp != -1) {
        for (; *L != -1 && elem > VH->Nodes[*L].elem; L = &VH->Nodes[*L].link) {}
        if (*L == -1 || elem != VH->Nodes[*L].elem) {
            VH->Nodes[temp].elem = elem;
            VH->Nodes[temp].link = *L;
            *L = temp;
        }
    }
}

LIST UnionSorted(VirtualHeap* VH, LIST A, LIST B) {
    int temp;
    LIST C,
         aptr = A,
         bptr = B;
    initList(&C);
    LIST* cptr = &C;
    while (aptr != -1 && bptr != -1) {
        temp = allocSpace(VH);
        if (temp != -1) {
            if (VH->Nodes[aptr].elem < VH->Nodes[bptr].elem) {
                VH->Nodes[temp].elem = VH->Nodes[aptr].elem;
                aptr = VH->Nodes[aptr].link;
            } else {
                if (VH->Nodes[aptr].elem == VH->Nodes[bptr].elem) {
                    aptr = VH->Nodes[aptr].link;
                }
                VH->Nodes[temp].elem = VH->Nodes[bptr].elem;
                bptr = VH->Nodes[bptr].link;
            }
            *cptr = temp;
            cptr = &VH->Nodes[*cptr].link;
        }
    }

    if (bptr != -1) {
        aptr = bptr;
    }

    while (aptr != -1) {
        int temp = allocSpace(VH);
        if (temp != -1) {
            VH->Nodes[temp].elem = VH->Nodes[aptr].elem;
            *cptr = temp;
            cptr = &VH->Nodes[*cptr].link;
            aptr = VH->Nodes[aptr].link;
        }
    }

    *cptr = -1;
    return C;
}

LIST IntersectionSorted(VirtualHeap* VH, LIST A, LIST B) {
    int temp;
    LIST C,
         aptr = A,
         bptr = B;
    initList(&C);
    LIST* cptr = &C;

    while (aptr != -1 && bptr != -1) {

        if (VH->Nodes[aptr].elem == VH->Nodes[bptr].elem) {
            temp = allocSpace(VH);
            if (temp != -1) {
                VH->Nodes[temp].elem = VH->Nodes[aptr].elem;
                *cptr = temp;
                aptr = VH->Nodes[aptr].link;
                bptr = VH->Nodes[bptr].link;
                cptr = &VH->Nodes[*cptr].link;
            }
        } else if (VH->Nodes[aptr].elem < VH->Nodes[bptr].elem) {
            aptr = VH->Nodes[aptr].link;
        } else if (VH->Nodes[aptr].elem > VH->Nodes[bptr].elem) {
            bptr = VH->Nodes[bptr].link;
        }
    }

    *cptr = -1;
    return C;
}

LIST DifferenceSorted(VirtualHeap* VH, LIST A, LIST B) {
    int temp;
    LIST C,
         aptr = A,
         bptr = B;
    initList(&C);
    LIST* cptr = &C;

    while (aptr != -1 && bptr != -1) {
        if (VH->Nodes[aptr].elem != VH->Nodes[bptr].elem) {
            if (VH->Nodes[aptr].elem < VH->Nodes[bptr].elem) {
                temp = allocSpace(VH);
                if (temp != -1) {
                    VH->Nodes[temp].elem = VH->Nodes[aptr].elem;
                    *cptr = temp;
                    cptr = &VH->Nodes[*cptr].link;
                    aptr = VH->Nodes[aptr].link;
                }
            } else {
                bptr = VH->Nodes[bptr].link;
            }
        } else {
            aptr = VH->Nodes[aptr].link;
            bptr = VH->Nodes[bptr].link;
        }
    }

    while (aptr != -1) {
        temp = allocSpace(VH);
        if (temp != -1) {
            VH->Nodes[temp].elem = VH->Nodes[aptr].elem;
            aptr = VH->Nodes[aptr].link;
            *cptr = temp;
            cptr = &VH->Nodes[*cptr].link;
        }
    }

    *cptr = -1;
    return C;
}