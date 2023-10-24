#include <stdio.h>
#include <stdlib.h>

// ADT struct Node
typedef struct structNode
{
    int data;
    struct structNode *addressOfNext;
} ssn;
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

    linkedListTraversal(headFirst);

    free(headFirst);
    free(secondNode);
    free(thirdNode);
    free(fourthNode);
    return 0;
}
