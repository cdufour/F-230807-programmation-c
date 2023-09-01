#include <stdio.h>
int main()
{
    short int age;

    printf("Quel est ton âge ? ");
    scanf("%hd", &age);
    printf("Tu as donc %d ans\n", age);
	return 0;
}
