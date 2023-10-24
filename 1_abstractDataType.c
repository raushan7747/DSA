/*
ADT (Abstract Data Type), ADT is the user based data type. We can define a data type with their set of functionalities ->
and some operations such as, array functionalities may included with thier size, used size, and so on.
set of Operations such as, max(), min() values in the array, insertion, deletion values in the array.
*/

#include <stdio.h>
#include <stdlib.h>
// Declaring a Abstract Data Type which holds some data types with different functionalities as user define
// Declaring Abstract Data type, which possible by using struct keyword only
struct myArray // myArray is an Abstract data type, which already holds another 3 data types
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show now\n");
    show(&marks);

    return 0;
}