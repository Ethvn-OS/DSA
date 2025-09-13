/* ******************************************************************************
*                                                                                *
*    This program demonstrates ADT Queues                                        *
*    (Version 1: Elements are unique | Version 2: Elements are not unique)       *
*                                                                                *
*    Programmer: Ethan Andre O. Dalocanog                                        *
*    Date Created: September 13, 2025                                            *
*                                                                                *
**********************************************************************************/

#include <stdio.h>
//#include "ADTQueueArray.h"
#include "ADTQueueLinkedList.h"

int main() {
    //initializing the queue
    Queue Q;
    initializeQueue(&Q);

    //inserting elements into the queue
    enqueue('U', &Q);
    enqueue('S', &Q);
    enqueue('C', &Q);
    enqueue('T', &Q);
    enqueue('R', &Q);

    //printing the queue
    printf("\nInitial list in the queue:\n");
    printQueue(&Q);

    //deleting one element from the queue
    dequeue(&Q);

    //printing the queue again
    printf("\nQueue after deletion:\n");
    printQueue(&Q);

    printf("\nQueue after insertion again, demonstrating when the queue is already full:\n");
    enqueue('A', &Q);
    enqueue('B', &Q);
    enqueue('G', &Q);
    enqueue('Z', &Q);
    printQueue(&Q);

    printf("\nQueue after deleting all elements, demonstrating when the queue is already empty:\n");
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    printQueue(&Q);

    return 0;
}