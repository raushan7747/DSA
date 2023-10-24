#include <stdio.h>

int main() // yeh bhi ik function hai, jo ki pehle se defined hai ki, jitne bhi execution honge woh iske andar hi likhe jayenge
           // yani ki jo bhi output hoga humare codes ka, wah main() function hi handle karega, ki jo iske andar codes hain, uska
           // ouput kya hona chahiye. int main() ka matlab hai ki, jab humara main() function apna kaam sahi se kar dega to wah ik
           // output hume dega yeh batane ke liye ki, main() funciton ke andar jo humne codes likhe hain wah sahi hai ki nhi
           // kyunki main() function pehle se defined hai ki wah kis tarah se codes ko lega, aur us inputs ka kya output hona chahiye
           // yeh sab kuchh main() function ke andar pehle se defined hain.
           // yani ki jab koi user, main() function ke definition se alag koi bhi kisi tarah ka different inputs dega, toh humara
           // main function use execute nhi kar payega, aur jo value return karega wah ik error code dega, jahan error aa rha hoga
           // jaise hum simple return type function banate hain, usi tarah se main() function bhi kaam karta hai
           // jis tarah se hum apne function me koi value return karwate hain, us FUNCTION ka execution ke baad, usi tarah se int main()
           // bhi ik inetger value return karega.
           // main() function ko define karne waqt ho sakta, developer ne FIRST line zero 0 se start kiya hoga aur usme yeh likha hoga
           // ki jab aage ke sabhi lines jo hum define kar rhen woh sahi rhe toh, LINE number 0 me jo VALUE hai use return kardo, jo ki 0 ho sakta
           // aur agar kisi lines me error hain to hume batao ki, main() function ke definition me se kis line ko humara yeh code follow nhi kar rha
           // to wahan error code ki tarah, wah us line Number ko rerurn kar dega, jo ki main() ke definition ko follow nhi kar rha hai.
{
    printf("This is only a string literal");
    return 0;
}
/*
Line-1: '#include' ik preprocessor keyword hai jo ki allow karta hai kisi file ko use karne ke liye
<stdio.h> ik file hai, jisme pehle se kuchh functions jaise ki printf,scanf ko define kiya gya hai
Functions ka seedha matlab hota hai, jab hum use kahin define karte hain to, hum use bas uske naam se hi woh kaam karwa sakte hain.
'printf' Fucntion ka example:
maanlo hum C programming ke <stdio.h> library abhi likh rhen hain, Dennis Ritchie ki tarah hi, to hum C me functions kaise banate hain
--> void printf (void); // yeh rha function declaration, yani ki bata rhen sirf ki 'printf' naam ka koi function hai
ab hum 'printf' fucntion ko define karenge, ki yeh fucntion kya karega,
--> void printf (void) {    // FUNCTION DEFINITION
    taking inputs under this brackets only = ()
    under brackets () user-input = ("literals")
    taking values under "literals" = ("%d")
    define value = ("%d", number) [when 'number' is type of integer]
    define format specifiers = ("%d %c %s %u %l") [where '%u' is unsigned int(means value must start from zero 0)], and so on
    define address of value = ("%d", &number)
    to exit from this function accept only = ; (semicolon)
}

printf("first function"); // FUNCTION CALL, isme inputs dene ke liye hume is tarah se hi likhna hoga "first function"

aur isi tarah se hum alag-alag functions banate hain, aur wah input kaise lega, output kis tarah se dega yeh sab <stdio.h> is tarah
ke files me pehle se hi saved hai, hum bas use call karte hain, jis tarah se hum apne banaye functions ko bas uske naam se call karte

To upar jaise humne ik 'printf' function ka definition diya, usi tarah se kuchh functions ke definitions pehle se hi alag alag
files me saved hain.
to hum jis bhi function ka use karna chahenge, uske liye hume un files ko add karna hoga, jisme yeh functions defined hain.

yeh jo #include<stdio.h>, #include<stdlib.h>, #include<string.h> HEADER files hain usme har category ke functions defined hain
to hume print aur scan karne ke liye [printf,scanf] function ko bas call karenge aur woh apna kaam humare liye karke de dega


*/