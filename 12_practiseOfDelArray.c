#include <stdio.h>

void printElements(int size, int array[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

void deletionInArray(int array[], int size, int deleteAtIndex)
{
    for (int index = deleteAtIndex; (size - 1) > index; index++)
    {
        array[index] = array[index + 1];
    }
}

int main()
{
    int array[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = 9, deleteAtIndex = 0;
    printElements(size, array);
    printf("\n");
    deletionInArray(array, size, deleteAtIndex);
    size -= 1;
    printElements(size, array);

    return 0;
}