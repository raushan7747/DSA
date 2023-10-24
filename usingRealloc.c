#include <stdio.h>
#include <stdlib.h>

int takeCharacters(int *);
int main()
{
    char *pointer;
    char inputs;
    char inputs2;
    int givenInputs;
    takeCharacters(&givenInputs);

    pointer = (char *)malloc((givenInputs + 1) * sizeof(char));

    printf("\n");

    printf("Enter the characters:");
    for (int i = 0; i < givenInputs; i++)
    {
        scanf("%c", &inputs); // Through an error, when we remove white-space from [%c] format spec
        pointer[i] = inputs;
    }

    printf("The characters you Entered: ");
    for (int i = 0; i < givenInputs; i++)
    {
        printf("%c", pointer[i]);
    }
    pointer[givenInputs] = '\0';
    printf("\nThe address of first pointer is %u", &pointer);
    // Using realloc() function to re-allocate again the memory
    int reallocInput;
    printf("\n\n");
    takeCharacters(&reallocInput);

    pointer = (char *)realloc(pointer, (reallocInput + 1) * sizeof(char));
    if (pointer == NULL)
    {
        printf("Memory reallocation failed. Exiting...\n");
        free(pointer); // Free the original memory before exiting
        return 1;
    }

    printf("\n");

    printf("Enter the characters:");
    for (int i = 0; i < reallocInput; i++)
    {
        scanf("%c", &inputs2); // Through an error, when we remove white-space from [%c] format spec
        pointer[i] = inputs2;
    }
    for (int i = 0; i < reallocInput; i++)
    {
        printf("%c", pointer[i]);
    }

    pointer[reallocInput] = '0';
    printf("\nThe address of second pointer is %u", &pointer);
    free(pointer);

    return 0;
}
int takeCharacters(int *givenInputs)
{
    printf("Enter how many character do you want to print\n");
    scanf("%d", givenInputs);
    return *givenInputs;
}
