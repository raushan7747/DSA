#include<stdio.h>
#include<stdlib.h>
// inserting element at first
int insertionAtFirst(int array[], int element, int aSize, int index)
{

    for(int i = 0; i<aSize; i++)
    {
        printf("%d", array[i]);
    }

}
int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9};
    int aSize = (sizeof(array))/sizeof(int);
    // printf("%d", aSize);
    int insertElement, index;
    printf("Enter the element you want to be shown here's: ");
    scanf("%d", &insertElement);
    printf("You entered: %d", insertElement);
    printf("Enter the index you want to be shown there's: ");
    scanf("%d", &index);
    printf("You entered: %d", index);
   
}