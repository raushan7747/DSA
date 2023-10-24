// Traversing the whole elements of an array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[] = {6, 2, 9, 9, 0, 5, 2, 4, 3, 9};
    int arrSize = (sizeof(array)) / sizeof(int);
    printf("Your array size is: %d\n\n", arrSize);
    int low = 0;                    // at zero (0) index
    int high = arrSize - 1;         // at (9) index
    int mid = ((low) + (high)) / 2; // at (4) index
    printf("Your mid index is: %d\n\n", mid);
    printf("The highest index of your array is: %d\n\nElements of the array is: ", high);

    while (low <= high) // from index zero to nine (0-9)
    {
        printf("%d", array[low]); // prints first element from zero (0) index
        low++;
    }
    // Now we are making decisions to search an element via binary search
    int lowIndex = 0;                    // at zero (0) index
    int highIndex = arrSize - 1;         // at (9) index
    int midIndex = ((low) + (high)) / 2; // at (4) index
    int element;
    printf("\n\nEnter the element you wanna search: ");
    scanf("%d", &element);
    if (element == array[lowIndex])
    {
        printf("It's true, at the first index the value is: ");
        printf("%d", array[lowIndex]); // prints first element from zero (0) index
    }
    else if (element == array[highIndex])
    {
        printf("It's true, at the highest inedex the value is: ");
        printf("%d", array[highIndex]); // prints first element from zero (0) index
    }
    else if (element == array[midIndex])
    {
        printf("It's true, at the middle index the value is: ");
        printf("%d", array[highIndex]); // prints first element from zero (0) index
    }
    else
    {
        printf("Please enter the correct value, exiting...");
    }

    return 0;
}