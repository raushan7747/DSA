// Not Working properly
#include <stdio.h>
#include <stdlib.h>

struct stackArray
{
    int size;
    int topValue; // topValue stores the [index] value,  which denotes the values if they exist in array.
    int *structArray;

};
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
    struct stackArray *array;
    array->size = 10;
    array->topValue = -1;
    array->structArray = (int *)malloc(array->size * sizeof(int));
    // pushing an element
    array->structArray[0] = 7;
    array->topValue++;
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