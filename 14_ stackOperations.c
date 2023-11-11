// Not Working properly
#include <stdio.h>
#include <stdlib.h>

typedef struct stackArray // ADT_Abstract Data Type
{
    int size;
    int topValue;     // topValue stores the [index] value,  which denotes the values if they exist in array.
    int *structArray; // points to the struct stackArray

} ssa;

int isStackEmpty(struct stackArray *stackArray)
{
    if (stackArray->topValue == -1)
        return 1;
    else
    {
        return 0;
    }
}
int isStackFull(struct stackArray *stackArray)
{
    if (stackArray->topValue == stackArray->size - 1)
        return 1;
    else
    {
        return 0;
    }
}

void push(struct stackArray *stackArray, int valueToPush)
{
    if (isStackFull(stackArray))
    {
        printf("Stack overflow, you can not push elements into the stack");
    }
    else
    {
        stackArray->topValue++;
        stackArray->structArray[stackArray->topValue] = valueToPush; // [stackArray->topValue] works like array index
        // ablove line looks like: array[10] = 23(or valueToPush)
        printf("The value you push is: %d\n", valueToPush);
    }
}
int pop(struct stackArray *stackArray)
{
    if (isStackEmpty(stackArray))
    {
        printf("Stack underflow, you can not pop elements from the stack");
    }
    else
    {
        int topMostElement = stackArray->structArray[stackArray->topValue];
        stackArray->topValue--;
        printf("The value you popped is: %d\n", topMostElement);
        return topMostElement;
    }
}

int peekValue(struct stackArray *stackArray, int index)
{
    // topValue starts from -1, and at the first position, topValue is 0
    int arrayIndex = stackArray->topValue - index + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position for the Stack\n");
        return -1;
    }
    else
    {
        return stackArray->structArray[arrayIndex];
    }
}
int main()
{
    printf("The size of structure is: %d\n\n", sizeof(ssa));
    struct stackArray *array;
    // Memory allocation in heap to use ADT-like size, topValue, and structArray
    array = (ssa *)malloc(sizeof(ssa));
    array->size = 10;
    array->topValue = -1;
    // Memory allocation in heap to reserve the size for an Array in the (array)-named Variable
    array->structArray = (int *)malloc(array->size * sizeof(int));
    push(array, 67);
    push(array, 47);
    push(array, 447);
    push(array, 367);
    push(array, 677);
    push(array, 867);
    printf("\nThe top value is: %d\n\n", array->topValue);
    pop(array);
    // pop(array);
    // pop(array);
    // pop(array);
    // pop(array);
    printf("\nThe top value is: %d\n\n", array->topValue);
    for (int j = 1; j <= array->topValue + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peekValue(array, j));
    }
        printf("\nThe top value is: %d\n\n", array->topValue);

    return 0;
}