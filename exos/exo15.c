#include <stdio.h>
int main()
{
    char chaine[10];
    printf("Entrez chaine de caracteres \n");
    gets(chaine);

    char chaineMaj[sizeof(chaine)/sizeof(char)];

    for(int i = 0; i < sizeof(chaine) / sizeof(char); i++)
    {
        if(chaine[i] >= 97 && chaine[i] <= 122) // 97 ('a') => 122 ('z')
        {
            int asciiCode = chaine[i] - 32;
            //printf("%c", asciiCode);
            chaineMaj[i] = asciiCode;
        }
    }

    puts(chaineMaj);
    return 0;
}