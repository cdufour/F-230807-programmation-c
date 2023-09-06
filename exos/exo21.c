#include <stdio.h>

/**
Ecrire un programme qui vérifie sur un chiffre donné est pair ou impair
en utilisant une fonction

-- Sortie attendue --
Saisir un chiffre: 9
9 est impair
*/

int is_pair(int v)
{
    return !(v%2);
}

int main() {
    int chiffre=0;

    printf("Entrez un nombre :\n");
    scanf("%d",&chiffre);

    if (is_pair(chiffre))
        printf("Chiffre pair \n");
    else
        printf("Chiffre impair \n");
}
