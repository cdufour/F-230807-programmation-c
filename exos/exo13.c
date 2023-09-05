#include <stdio.h>
int main()
{
    char string[] = "bon jour";

    int index = 0;
    char c = ' ';
    
    while(c != '\0')
    {
        c = string[index];
        index++;
    }

    printf("la chaine comporte %d caracteres dont le finde chaine\n", index);

    // variante
    char input[20];
    int compteur = 0;

    printf("Saisir une chaine de caractere : ");
    scanf("%s", input);

    while(input[compteur] != '\0'){
        compteur++;
    }
    printf("Longueur : %d\n", compteur);
    return 0;
}