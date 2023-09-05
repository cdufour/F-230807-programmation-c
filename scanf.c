#include <stdio.h>
int main()
{
    short int age;

    printf("Quel est ton âge ? ");
    scanf("%hd", &age);
    printf("Tu as donc %d ans\n", age);
	
    // complément (multiple inputs) --------------
    int myNum;
    char myChar;

    printf("Type a number AND a character and press enter: \n");
    scanf("%d %c", &myNum, &myChar);
    printf("Your number is: %d\n", myNum);
    printf("Your character is: %c\n", myChar);
    // -------------------------------------------
    
    return 0;
}
