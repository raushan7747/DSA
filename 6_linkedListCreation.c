#include <stdio.h>
#include <stdlib.h>
// Declaring a Abstract Data Type which holds some data types with different functionalities as user define
// Declaring Abstract Data type, which possible by using struct keyword only
typedef struct parentNode
{
    int data;                    // storing ineger type data
    struct parentNode *nextData; // storing an address which points to the next Node
} spn;

void linkedListTraversal(spn *pointerToVisit)
{
    while (pointerToVisit != NULL)
    {
        printf("%d", pointerToVisit->data);
        pointerToVisit = pointerToVisit->nextData;
    }
}

int main()
{
    spn *head = NULL;   // third node, child node of the 'struct parntNode' -> which holds only two data types
    spn *second = NULL; // first node, which is the branch of 'struct parentNode' -> integer data type and pointer to 'struct parentNOde' data type which means the ->
    spn *third = NULL;  /* second node, connected to the 'struct parentNOde' -> second data type holds the address of 'struct parentNOde', and then we are able to use
     that 2 data types, which are defined under the Abstract-data-type(struct parentNOde), and we put our integer data & addresses of next Data through 'spn' */
    // Dynamic memory allocation to the Heap, typcasting the returned null pointer to the 'struct Node*' which points to the 'spn'
    head = (spn *)malloc(sizeof(spn));
    second = (spn *)malloc(sizeof(spn));
    third = (spn *)malloc(sizeof(spn));
    printf("The size allocated for 'struct parentNode' is: %d, in which 4 bytes is reserved to store an address of 'struct parentNode*'\n\n", sizeof(spn));
    // Linking first node to the second Node
    (*head).data = 960;
    head->nextData = second; // (second) holds (snp*)-type mempry in HEAP // printf("%d", (*head).data); // printf("%d", head->data);
    // Linking second node to the third node
    second->data = 800;
    second->nextData = third;
    // Linking third node to the Null, to terminate
    third->data = 7747;
    third->nextData = NULL;
    linkedListTraversal(head);

    // above function workd like this only -->
    // while (head != NULL) // Loop tab tak chalega, jab tak humara POINTER kisi NULL value ko na dhoondhle.
    // {
    //     printf("%d", head->data); // yeh bas har ik POINTER, jo ki (spn) ka address store karta hai, (spn) ke andar stored values ko print karega
    //     head = head->nextData;    // isme hum bata rhen ki, humara jo POINTER hoga, wah (spn) ke andar (nextDAta) POINTER ki help se agle POINTER ke bhi addresses ko store karta jayega.
    // }                             // For Example: (head) POINTER me humne (second) POINTER ka address diya, usi tarah se (second) me (third), to yeh har ik POINTER ko uske addresses se access kar payega.

    free(head);
    free(second);
    free(third);
    return 0;
}
/*
Hume sabse pehle ik aisa Abstract-data-type banana hoga, jisme 2 blocks honge --> 1st Block me hum apna data store karenge, aur 2nd Blcok me hum usi Abstract-data-type
ka address store karlenge. For Example: 'struct parentNOde' humara Abstract-data-type hai jisme 2 data-types ko store karne ke liye memory space hogi, ineger & pointer.
integer data-type, humare diye hue values ko store karega --> wahin jo pointer hoga, wah poore 'struct parentNode' Abstract-data-type ka ADDRESS store karke rakhega.

Ab hume apne 'struct parentNOde' Abstract-data-type ko use karne ke liye, ik POINTER chahiye hoga JO KI 'struct parentNode' ka address store kare --> aur us POINTER ki
help se hum 'struct parentNode' ko access kar payenge, yani ki hum us POINTER ki help se 'struct parentNode' Abstract-data-type ke har ik elements(int & snp*) me hum
apne values ko store kar payenge, ya usse delete kar payenge, kyunki humne 'struct parentNOde' ke values ki copy store NA karke uske address ko store kar rhe hain.

Ab, humne jo POINTER banaya hai, jo ki 'struct parentNode' ko points kar rha hoga(yani ki 'snp' ka address store karta hoga) --> hum us POINTER ki help se (snp) ke DONO
DATA-TYPES ke andar VALUES ko store kar payenge ya DELETE bhi kar payenge. Ab (snp) ke andar hum 2 data-types ke variables banaye hain, jis variable ke andar hum us -->
data-type me hi values ko store kar sakte hain. FOR EXAPMPLE: agar hum apne 'struct parentNode' ko dekhen to usme humne 2 data-type define kiya hai -->
1st 'int data;' me (data) ik variable hai jo ki sirf integer data-type store kar sakta hai, aur usi tarah se -->
2nd 'struct parentNode *nextData;' me (nextData) ik aisa variable hai jo ki sirf aur sirf 'struct parentNode' ke ADDRESS ko hi store kar sakta hai.

Yani ki hum ab POINTER ki help se 'struct parnetNode' ke har ik element ko is tarah se access karenge [ (*head).data or head->data ] aur jo humara variable jis data-type ka hoga -->
hum usi data-type me uske andar VALUES ko bhi store karente. FOR EXAMPLE:  (*head).data = 96; head->nextData = second;
(data) variable ko humne apne 'struct parentNode' me pehle hi define kar diya hai ki yeh sirf (integer) data-type ke hi values ko store karega jisme ki (96) value hai, aur -->
(nextData) ka bhi data-type humne 'spn' me define kiya tha ki, is variable me hum sirf 'struct parenNode' kaaddress hi store kar sakte hain, jisme ki (second) ik aisa pointer hai -->
jo 'struct parentNode' data-type ka hi hai, jo ki 'spn' ko points kar rha hoga(yani ki 'spn' ka Address store karta hoga) --> aur ab hum phir se (second) POINTER ki help se -->
'struct parentNode' ke dono data-types-variables ka use kar payenge, aur isi tarah se hum jitni baar chahenge utni baar 'spn' ke data-types-variables ko (spn*) data-type POINTERS -->
ki help se har ik data-type-variables ko access kar payenge.
Aur, hume jab aage VALUES store nhi karne honge to hum us POINTER me kisi next [ (spne*) POINTER ] ka address na dekar NULL ko store kar denge, aur ik loop chala sakte hain -->
jisse humara LIST wahin END ho jayega jahan use 2nd data-type me NULL milega.

*/