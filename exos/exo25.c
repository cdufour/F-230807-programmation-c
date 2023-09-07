#include <stdio.h>
#include <stdlib.h>

void decalage(char mystring[32])
{
    int cursor = 0;
    while (mystring[cursor] != '\0')
    {
        mystring[cursor] += 1;
        cursor++;
    }
}

int main()
{
    char mystring[32];
    puts("Entrer un mot :");
    scanf("%s", mystring);

    decalage(mystring);
    printf("%s\n", mystring);

    return 0;
}