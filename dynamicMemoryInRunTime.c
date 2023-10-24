// We were using the Static memory Allocation such as
// int arr[20]; In this array, 20* sizeof(int) memory reserved during compilation.

/*
 * Even, when we use Dynamic Memory Allocation, then we're able to change the ->
 * memory size during Run Time. We use only the memory as need as required to our program.
 * Here's we need to create to a (pointer) which points to the HEAP (weSupposeLikeRAM) ->
 * and, one more thing to be noticed that, Heap will return Void pointer -> Such as
 * char *pointer; here's we declare a pointer which stores the address of Char-type omly ->
 * but, if we points to the Heap, then Heap will return a reserved memory blocks to store
 * but Heap will return void pointer, means that we need to declare again that returned pointer
 * or typeCaste the returned pointer.
 * ex ->
 * char *pointer;
 * pointer = (char*) malloc (10 * sizeof(char));
 */

#include <stdio.h>
#include <stdlib.h>

int takeCharacters(int *);
int main()
{
    char *pointer;
    char inputs;
    int givenInputs;
    takeCharacters(&givenInputs);

    pointer = (char *)malloc(givenInputs * sizeof(char));

    printf("\n");

    for (int i = 0; i < givenInputs; i++)
    {
        printf("Enter the characters:");
        scanf(" %c", &inputs); //Through an error, when we remove white-space from [%c] format spec
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
