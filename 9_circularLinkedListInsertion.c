#include <stdio.h>
#include <stdlib.h>

// ADT struct Node
typedef struct structNode
{
    int data;
    struct structNode *addressOfNext;
} ssn;
// insertion at first
ssn *insertionAtFirst(ssn *headNode, int value)
{
    ssn *firstNewNode;
    firstNewNode = (ssn *)malloc(sizeof(ssn));
    firstNewNode->data = value;
    firstNewNode->addressOfNext = headNode;
    return firstNewNode;
}
// circular linked list traversal
void linkedListTraversal(ssn *firstNode)
{
    ssn *pointsToTheHead = firstNode;
    do
    {
        printf("%d", firstNode->data);
        firstNode = firstNode->addressOfNext;
    } while (pointsToTheHead != firstNode);
}
void linkedListTraversal1(ssn *firstNode)
{
    ssn *pointsToTheHead = firstNode;
    printf("%d", firstNode->data);
    firstNode = firstNode->addressOfNext;
    do
    {
        printf("%d", firstNode->data);
        firstNode = firstNode->addressOfNext;
    } while (pointsToTheHead != firstNode);
}

int main()
{
    ssn *headFirst = NULL;
    ssn *secondNode = NULL;
    ssn *thirdNode = NULL;
    ssn *fourthNode = NULL;

    headFirst = (ssn *)malloc(sizeof(ssn));
    secondNode = (ssn *)malloc(sizeof(ssn));
    thirdNode = (ssn *)malloc(sizeof(ssn));
    fourthNode = (ssn *)malloc(sizeof(ssn));

    headFirst->data = 88;                  // firstNode data
    headFirst->addressOfNext = secondNode; // storing address of nextNode
    secondNode->data = 26;
    secondNode->addressOfNext = thirdNode;
    thirdNode->data = 75;
    thirdNode->addressOfNext = fourthNode;
    fourthNode->data = 4288;
    fourthNode->addressOfNext = headFirst; // again linking the last node to the first
    printf("before insertion: ");
    linkedListTraversal(headFirst);
    printf("\n");
    printf("after insertion: ");
    headFirst = insertionAtFirst(headFirst, 91);
    linkedListTraversal1(headFirst);

    free(headFirst);
    free(secondNode);
    free(thirdNode);
    free(fourthNode);
    return 0;
}
