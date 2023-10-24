// Deleting an element between the array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int deleteIndex = 2;
    int array[] = {12, 23, 34, 45, 67, 89, 90};      // This array reserves the sizeof(int) * elements, arrSize = 4*7 = 28.
    int arraySize = (sizeof(array)) / (sizeof(int)); // diveded by sizeof(int), because each block size is equal to integer.
    printf("The size of your array is: %d\n", arraySize);
    // printing array
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d\t", array[i]); // prints array[0] first, again prints array[1] and upto array[6]
    }
    printf("\n");
    for (int index = deleteIndex; index < arraySize - 1; index++)
    {
        array[index] = array[index + 1]; // array[2+1 = 3] ko hum array[2] me daal rhe hain, jisse array[2] ke element delete ho jayenge
    }
    arraySize -= 1;
    // printing array
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}
/*
In Line 17-loop: index = 2 means, loop array[2] se start hoga
index < arraySize-1 means, 2 < 6 = (2,3,4,5), yani ki array[2] se lekar array[5] tak yeh loop chalega
Ab, jab hum array[2] ke element ko delete kar denge toh uske baad bas 4 elements hi bachenge, jise hume left side shift karna hoga
*/