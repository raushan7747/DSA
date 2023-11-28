#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
{
    // When we try to allocate memory for new-node(or, pushing elements) and they return NULL means that STACK Filled up.
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0; // if stack isn't full return with 0(means false)
}

struct Node *push(struct Node *top, int valueToPutInNode)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // Generating a new-node to store data to perform push-operation
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = valueToPutInNode;
        newNode->next = top; // here's top = NULL, so newNOde->next = NULL;
        top = newNode;       // here's top stores the address of next newNode, means top = Node1
        return top;          // top returns with updated newNode, top = Node1
    }
}

int peek(int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1;
}

int pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *newNode = top;
        top = (top)->next;
        int poppedElement = newNode->data;
        free(newNode);
        return poppedElement;
    }
}

int main()
{
    printf("Adress before pop: %u\n", top);

    top = push(top, 29);
    printf("Adress for 29 pop: %u\n", top);

    top = push(top, 30);
    printf("Adress for 30 pop: %u\n", top);

    top = push(top, 31);
    printf("Adress for 31 pop: %u\n\n", top);

    linkedListTraversal(top);
    for (int i = 1; i <= 3; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    printf("\nAdress before pop: %u\n", top);
    // Pop operation must be after Peek operation, that's why, when we popped-out our element then (top) will addressed to the next Node.
    // In pop() --> Line1: struct Node *newNode = top;  Line2: top = (top)->next; Line3: free(newNode);
    // Because of these three lines, we lost the address of struct Node -> data., when we pop-out the first element then,
    // we lose our data, but there's address is the same, hence, we don't have the data in that address and when we try to print data
    // - at that address, where we were deleted the data, we don't get that data. So, peek() must be executed first before pop().
    int elementPopped = pop(top);
    printf("Popped element is: %d\n", elementPopped);
    printf("\nAdress after pop: %u", top);
    return 0;
}
/*
 * top = push(top, 28); --> Explaining push-operation
 * top holds the address of Node, push function will invoke now to perform
 * In push function, we are generating a Node and put their some values
 * newNode->next = top; --> newNode ke next-field me current wale top ko point karaya ja rha hai (top = NULL)
 * top = newNode; --> top ab update kiya ja rha hai, jo push function me naya node bana hai, uske address ko hum top ko de rhen hai,
 * yani ki ab top NULL ko point na karke naye wale NODE ko point karega.
 * first step: top = Null
 * second step: Node1->next(newNode->next) = NULL(current top), top = Node1(top = newNode) --> top updated from NULL to Node1
 * third step: Node2->next(newNode->next) = Node1(current (top), top = Node2(top = newNode) --> toop updated from Node1 to Node2
 */