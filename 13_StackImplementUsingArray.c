// STACKS are completely opposed to the Linked-list
#include <stdio.h>
#include <stdlib.h>

typedef struct stackArray // ADT_Abstract Data Type
{
    int size;
    int topValue;     // topValue stores the [index] value,  which denotes the values if they exist in array.
    int *structArray;

} ssa;
int isStackEmpty(struct stackArray *ptr)
{
    if (ptr->topValue == -1)
        return 1;
    else
    {
        return 0;
    }
}
int isStackFull(struct stackArray *ptr)
{
    if (ptr->topValue == ptr->size - 1)
        return 1;
    else
    {
        return 0;
    }
}
int main()
{
    printf("The size of structure is: %d\n\n", sizeof(ssa));
    struct stackArray *array;
    // Memory allocation in heap to use ADT-like size, topValue, and structArray
    array = (ssa *)malloc(sizeof(ssa));
    array->size = 20;
    array->topValue = -1;
    // Memory allocation in heap to reserve the size for an Array in the (array)-named Variable
    array->structArray = (int *)malloc(array->size * sizeof(int));
    printf("The size of structure array-pointer is: %d\n\n", sizeof(array));
    printf("The size of array->structArray, is: %d\n\n", sizeof(array->structArray));
    // // pushing an element manually
    // array->structArray[0] = 7;
    // array->topValue++;
    if (isStackEmpty(array))
    {
        printf("The Stack is Empty");
    }
    else
    {
        printf("The Stack is not Empty");
    }

    return 0;
}