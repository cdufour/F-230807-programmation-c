#include <stdio.h>
int main()
{
    char text[10];
    gets(text);
    puts(text);

    printf("Taille de text: %lu\n", sizeof(text));

    int count = 0;
    while (text[count] != '\0') {
        printf("Caractère: %c\n", text[count]);
        count++;
    }
    printf("Longueur de la chaîne saisie: %d\n", count);
}