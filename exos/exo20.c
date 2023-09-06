#include <stdio.h>
#include <string.h>

int main()
{

    char phrase[50];
    char *ptr1 = &phrase[0];
    int count = 0;

    puts("Ecrire une chaine de caracteres: ");
    gets(phrase);

    for (int i = 0; i < strlen(phrase); i++)
    {
        if (*(ptr1 + i) == 'e')
        {
            count++;
        }
    }

    printf("Chaîne: %s\nNombre de 'e': %d\n", phrase, count);

    return 0;
}