// Traversing the whole elements of an array
#include <stdio.h>
int main()
{
    int array[] = {8, 8, 2, 6, 7, 5, 4, 2, 8, 8};
    int arrSize = (sizeof(array)) / sizeof(int);
    printf("Your array size is: %d\n\n",arrSize);
    int low = 0;            // at zero (0) index
    int high = arrSize - 1; // at (9) index
    printf("The highest index of your array is: %d\n\nElements of the array is: ", high);

    while (low <= high) // from index zero to nine (0-9)
    {
        printf("%d", array[low]); // prints first element from zero (0) index
        low++;
    }

    return 0;
}