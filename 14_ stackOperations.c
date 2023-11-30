//  STACK implementation is done by opposite side of Linked list
/*
 * When we try to push our first element, woh sabse neeche jayega, such as we're creating 3-elements STACK, then
 * first-element sabse neeche jakar, 3rd element ho jayega, aur humara 2nd element, 3rd ke upar rhega, usitarah se
 * 3rd element sabse aakhri me jayega, lekin woh STACK ke sabse upar rhega. Toh jab hum STACK ke elements ko access karna
 * chahte hain, to hum apne 3rd element ko 2nd element ke saath link karenge, isse jab hum apne 3rd(or, last) element ko
 * acess karenge, to hum 3rd linked-list ke pointer-field (jisme 2nd element ka Address hai) ki help se
 * 2nd element ko bhi acess kar payenge, aur phir 2nd element ke paas usi tarah se humare 1st linked-list ka Address hoga,
 * aur hum jab apne 1st element ke paas pahunch jayenge, to uske baad to koi elements hai nhi humare STACK me to isiliye
 * hum, 1st element ke pointer-field me NULL put kar denge, jisse ki humara STACK khatam ho sake.
 * THEREFORE, 1st-element ke paas NULL ka address hona chahiye, kyunki 1st-element sabse aakhri me access kiya jayega, aur hum
 * chahenge ki aakhri element ke data ke baad humara STACK khatam ho jaaye, isliye 1st-element me hi pehle hum NULL put karenge,
 * aur uske upar jitne bhi elements hum push karenge, use aakhri element ka address bhi pass karenge, taki jab hum STACK ke upar se
 * elements push kar rhen honge, to new element upar honge, aur uske andar jo pehle se hain hum use access karne ke liye, naye
 * element ko pehle waale element ka address pass kar denge.
 * For Example- STACK me 1 element hai, hum naya element push karenge to, 2nd element ko hum 1st element ka address pass kar denge,
 * aur 1st element ke pass NULL ka address rhege, jo ki sabse aakhri me acess kiya jayega, aur 1st element ke paas aakar hi humara
 * STACK-end hoga. According to LIFO- lAST IN FIRST OUT, and FILO- FIRST IN LAST OUT
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct stackArray // ADT_Abstract Data Type
{
    int size;
    int topValue; // topValue stores the [index] value,  which denotes the values if they exist in array.
    int *structArray;

} ssa;

int isStackEmpty(struct stackArray *stackArray)
{
    if (stackArray->topValue == -1)
        return 1;
    else
    {
        return 0;
    }
}
int isStackFull(struct stackArray *stackArray)
{
    if (stackArray->topValue == stackArray->size - 1)
        return 1;
    else
    {
        return 0;
    }
}

void push(struct stackArray *stackArray, int valueToPush)
{
    if (isStackFull(stackArray))
    {
        printf("Stack overflow, you can not push elements into the stack");
    }
    else
    {
        stackArray->topValue++;
        stackArray->structArray[stackArray->topValue] = valueToPush; // [stackArray->topValue] works like array index
        // ablove line looks like: array[10] = 23(or valueToPush)
        printf("The value you push is: %d\n", valueToPush);
    }
}
int pop(struct stackArray *stackArray)
{
    if (isStackEmpty(stackArray))
    {
        printf("Stack underflow, you can not pop elements from the stack");
    }
    else
    {
        int topMostElement = stackArray->structArray[stackArray->topValue];
        stackArray->topValue--;
        printf("The value you popped is: %d\n", topMostElement);
        return topMostElement;
    }
}

int peekValue(struct stackArray *stackArray, int index)
{
    // topValue starts from -1, and at the first position, topValue is 0
    int arrayIndex = stackArray->topValue - index + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position for the Stack\n");
        return -1;
    }
    else
    {
        return stackArray->structArray[arrayIndex];
    }
}
int main()
{
    printf("The size of structure is: %d\n\n", sizeof(ssa));
    struct stackArray *array;
    // Memory allocation in heap to use ADT-like size, topValue, and structArray
    array = (ssa *)malloc(sizeof(ssa));
    array->size = 10;
    array->topValue = -1;
    // Memory allocation in heap to reserve the size for an Array in the (array)-named Variable
    array->structArray = (int *)malloc(array->size * sizeof(int));
    push(array, 67);
    push(array, 47);
    push(array, 447);
    push(array, 367);
    push(array, 677);
    push(array, 867);
    printf("\nThe top value is: %d\n\n", array->topValue);
    pop(array);
    // pop(array);
    // pop(array);
    // pop(array);
    // pop(array);
    printf("\nThe top value is: %d\n\n", array->topValue);
    for (int j = 1; j <= array->topValue + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peekValue(array, j));
    }
    printf("\nThe top value is: %d\n\n", array->topValue);

    return 0;
}