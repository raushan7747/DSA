#include <stdio.h>
#include <stdlib.h>

// printing array-elements
void printElements(int size, int array[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}
// inserting element at first
void insertionAtFirst(int array[], int element, int aSize, int index)
{
    for(int i = aSize-1; index <= i; i--) //  i = 8, 9-1 = 8
    {
        array[i+1] = array[i];
    }
    array[index] = element;
}
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int aSize = 9, index = 0, element = 0;
    printElements(aSize, array);
    printf("\n");
    insertionAtFirst(array, element, aSize, index);
    aSize = aSize+1; // aSize += 1;
    printElements(aSize, array); 
}