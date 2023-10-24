// Inserting elements into an array
#include <stdio.h>
#include <stdio.h>

void arrayInsertion(int[], int, int, int);
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6};
    int size = 6, index = 1, insertElement = 7;
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");
    arrayInsertion(array, size, index, insertElement);
    size += 1;
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

void arrayInsertion(int arr[], int size, int index, int insertElement)
{
    for (int i = size - 1; i >= index; i--) // tab tak chalega jab tak hum apne us index[1] pe na phunch jaaye, i = 5, 5-1 = 4,3,2,1..
    {
        arr[i + 1] = arr[i]; // array[5] ke value ko array[5+1] yani ki array[6] me dalega
    }
    // loop khatam hone ke baad ab humara array[1] khali ho chuka hai, ab hum usme apne element ko daal sakte hain.
    arr[index] = insertElement;
}
/*
for-loop ke andar [i] ki value hum array ke indices ke hisaab se denge, kyunki array ka index 0 se start hota hai,
isliye size-1 array ke element address[indices] ke equal hoga.

array[10] = {1,2,3,4,5,6, , , , }, ab hume index 1 ko pehle khali karna hoga to
hum index[5] ke elements ko index [6] pe bhej denge
hum index[4] ke elements ko index [5] pe bhej denge
hum index[3] ke elements ko index [4] pe bhej denge
hum index[2] ke elements ko index [3] pe bhej denge
hum index[1] ke elements ko index [2] pe bhej denge 
// arrayInsertion ka loop yahin aakar khatam ho jayega, kyunki i = 1 ho chuka hai, aur index = 1 tha, aur humne apne loop me
-> yahi condition lagaya tha ki, loop tab tak chale jab tak ki humare 'i' ki value 1 ya usse bara rhe, yani ghatkar jab 1 hoga
-> toh humara condition false ho jayega, kyunki 1-1 = 0, aur '0' '1' se bara nhi hai, toh yahin tak loop chalega humara
phir index[1] ki jagah khali ho jayegi, aur ab usme insert kar sakte hain apne naye value ko

array[10] = {1, ,2,3,4,5,6, , , } to yeh array kuchh is tarah ka hoga
uske baad hum index[1] = 7 store kar sakte hain

*/

/*
i = 5,4,3,2,1 // isme 5>1, 4>1,3>1,2>1,1=1 loop bas yahin tak chalega
index = 1
*/