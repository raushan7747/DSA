// Calloc - Contiguos Allocation
// Difference between malloc & calloc - In malloc, array stored with Garbage Values, so we can ->
// easily use local variables to store an array which is provide by Heap(RAM)
// In calloc, array stored with zero(0), means that, we need to use pointer variable to change values

#include <stdio.h>
#include <stdlib.h>

int takeCharacters(int *);
int main()
{
    char *pointer;
    char inputs;
    int givenInputs;
    takeCharacters(&givenInputs);

    pointer = (char *)calloc(givenInputs, sizeof(char));

    printf("\n");

    for (int i = 0; i < givenInputs; i++)
    {
        printf("Enter the characters:");
        scanf(" %c", &inputs); // Through an error, when we remove white-space from [%c] format spec
        pointer[i] = inputs;
    }

    printf("The characters you Entered: ");
    for (int i = 0; i < givenInputs; i++)
    {
        printf("%c", pointer[i]);
    }
    free(pointer);

    return 0;
}
int takeCharacters(int *givenInputs)
{
    printf("Enter how many character do you want to print\n");
    scanf("%d", givenInputs);
    return *givenInputs;
}
