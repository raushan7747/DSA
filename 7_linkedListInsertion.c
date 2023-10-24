// Inserting elements in the Linked-list
// Case 1: Inserting elements at the FIRST Node of Linked-list
// Case 2: Inserting elements BETWEEN the Node of Linked-list
// Case 3: Inserting elements at the END Node of Linked-list

#include <stdio.h>
#include <stdlib.h>
// creating a Node, whch is Abstract-data-type defined by the user
typedef struct parentNode
{
    int data;
    struct parentNode *addressOfNextNodeInSecondBlock;
} spn;
// printing data of the Linked-list
void linkedListTraversal(spn *firstNode)
{
    while (firstNode != NULL)
    {
        printf("%d", firstNode->data);
        firstNode = firstNode->addressOfNextNodeInSecondBlock;
    }
}
// inserting value into the Node at first
spn *insertAtFirst(spn *headCopy, int value)
{
    spn *newHead = NULL;
    newHead = (spn *)malloc(sizeof(spn));
    newHead->data = value;
    newHead->addressOfNextNodeInSecondBlock = headCopy;
    return newHead;
}
// inserting value into the Node at index
spn *insertAtIndex(spn *headCopy, int value, int index) // headCopoy don't have the address of headNode, to change the values directly in headNode
{
    // taking a pointer-to-Node to reach to the index at where we want to place our values
    spn *pointsToTheNode = NULL; // this will points to the headNode, secondNode like wise
    // here's we're just taking copies values of the headNode, not the address of headNode, becoz headNode already a pointer
    pointsToTheNode = headCopy; // this pointer works like head, and helps us to traverse to the wanted-index
    printf("the size and address of pointsToThNode is: %ld\n%u\n\n", sizeof(pointsToTheNode), pointsToTheNode);
    spn *newNode = NULL;
    newNode = (spn *)malloc(sizeof(spn));
    newNode->data = value;
    int i = 0;
    while (i != (index - 1))
    {
        // in-main headNode consists the address of nextNode, like secondNode.so, pointsToTheNode is now eqal to headNode and works-like-wise
        // pointsToTheNode ke second-block me hum headNode ka Address daal rhe hain, taki humara yeh pointer headNode tak pahunch sake.
        pointsToTheNode = pointsToTheNode->addressOfNextNodeInSecondBlock; // we're putting the nextNode addresses into the pointsToTheNode
        // in this loop, we'are just taking the address of headNode, and also headNode will gives us the nextNode addresses.
        i++;
        /*
        pointsToTheNode = headNode, and headNode consists the address of secondNode, and the secondNode consists already the address of
        thirdNode, so on. So, if we take a pointer which is equal to the headNode, then, we can traverse to each node using the first
        headNode.
        */
    }
    newNode->addressOfNextNodeInSecondBlock = pointsToTheNode->addressOfNextNodeInSecondBlock;
    pointsToTheNode->addressOfNextNodeInSecondBlock = newNode;
    return headCopy; // returns head, becoz we don't want to lose our head,at where our Node starts from
}
spn *insertAtEnd(spn *headCopy, int value)
{
    spn *newNode = NULL;
    newNode = (spn *)malloc(sizeof(spn));
    newNode->data = value;
    spn *secondHeadPointer = headCopy;
    while (secondHeadPointer->addressOfNextNodeInSecondBlock != NULL)
    {
        secondHeadPointer = secondHeadPointer->addressOfNextNodeInSecondBlock;
    }
    secondHeadPointer->addressOfNextNodeInSecondBlock = newNode;
    newNode->addressOfNextNodeInSecondBlock = secondHeadPointer->addressOfNextNodeInSecondBlock;
    newNode->addressOfNextNodeInSecondBlock = NULL;
    return headCopy;
}
int main()
{
    // creating our Nodes, which contains ineger-block and address-block of the Node
    spn *headNode = NULL;
    spn *secondNode = NULL;
    spn *thirdNode = NULL;
    spn *fourthNode = NULL;
    // size allocation for the Nodes
    headNode = (spn *)malloc(sizeof(spn));
    secondNode = (spn *)malloc(sizeof(spn));
    thirdNode = (spn *)malloc(sizeof(spn));
    fourthNode = (spn *)malloc(sizeof(spn));
    // assigning values to our nodes
    headNode->data = 88;
    headNode->addressOfNextNodeInSecondBlock = secondNode; // linking first Node to the next-node, taking address of secondNode in the headNode second-Block
    secondNode->data = 77;
    secondNode->addressOfNextNodeInSecondBlock = thirdNode; // linking second Node to the next-node
    thirdNode->data = 66;
    thirdNode->addressOfNextNodeInSecondBlock = fourthNode; // linking third Node to the next-node
    fourthNode->data = 55;
    fourthNode->addressOfNextNodeInSecondBlock = NULL; // linking fouth Node to the NULL, to terminate our Node

    printf("\nthe address of headNode: %u\nlook at that pointsToTheNode and headNode addresses are different, this prooves that,\nwe're using only copy of headNode into our functions, don't take the refrences\n\n", headNode);
    printf("the first likedList we done is: ");
    linkedListTraversal(headNode); // printing the whole-value of Nodes
    printf("\nafter inserting value at the first Node is: ");
    headNode = insertAtFirst(headNode, 99);
    linkedListTraversal(headNode); // printing the whole-value of Nodes
    headNode = insertAtIndex(headNode, 44, 2);
    printf("\nafter the inserting values at the indexes, at where we wants: ");
    linkedListTraversal(headNode); // printing the whole-value of Nodes
    printf("\nafter adding the values at the end: ");
    headNode = insertAtEnd(headNode, 123);
    linkedListTraversal(headNode); // printing the whole-value of Nodes

    free(headNode);
    free(secondNode);
    free(thirdNode);
    free(fourthNode);
    return 0;
}