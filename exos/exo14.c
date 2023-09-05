#include <stdio.h>

int main() {
    char mot1[10];
    char mot2[10];
    char conca[21];
    
    printf("Ecrire le premier mot : ");
    gets(mot1);

    printf("Ecrire le deuxieme mot : ");
    gets(mot2);

    int longueur1 = 0, longueur2 = 0;

    while (mot1[longueur1] != '\0') {
        longueur1++;
    }

    for (int i = 0; i < longueur1; i++) {
        conca[i] = mot1[i];
    }

    conca[longueur1] = ' '; // ajout moche de l'espace

    while (mot2[longueur2] != '\0') {
        conca[longueur1 + 1 + longueur2] = mot2[longueur2];
        longueur2++;
    }

    conca[longueur1 + 1 + longueur2] = '\0';

    printf("Concatenation : %s\n", conca);


    // variante
    char text1[100], text2[100];
    int i, j;

    printf("\n Chaîne 1: ");
    gets(text1);
    printf("\n Chaîne 2: ");
    gets(text2);

    i = 0;
    while(text1[i] != '\0')
    {
        i++;
    }

    text1[i] = ' ';
    i++;

    j = 0;
    while(text2[j] != '\0')
    {
        text1[i] = text2[j];
        i++;
        j++;
    }

    text1[i] = '\0';

    printf("\n Concaténation %s\n", text1);

    return 0;
}