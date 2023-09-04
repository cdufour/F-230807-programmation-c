#include <stdio.h>

int main()
{
    // l'élément d'indice 4 est implicitement converti en int
    int myNumbers[] = {25, 50, 75, 100, 125.5};
    int i = 3;
    printf("%d\n", myNumbers[i]);

    // accès en écriture
    myNumbers[4] = 150;
    printf("%d\n", myNumbers[4]);

    //myNumbers[6] = 200; // crash (runtime)

    // itération sur le tableau (for)
    int j;
    puts("*** Parcours (boucle for) ***");
    for (j = 0; j < 5; j++) {  
        printf("Indice %d : %d\n", j, myNumbers[j]);
    }

    // itération sur le tableau (while)
    int k = 0;
    puts("*** Parcours (boucle while) ***");
    while (k < 5) {
        printf("Indice %d : %d\n", k, myNumbers[k]);
        k++;
    }


    const int TAXES_LEN = 3;
    float taxes[TAXES_LEN] = {5.5, 19.6, 20.0};
    int l;
    puts("*** Parcours (boucle for) ***");
    for (l = 0; l < TAXES_LEN; l++) {  
        printf("Indice %d : %.1f\n", l, taxes[l]);
    }

    char student[4] = {'t', 'o', 't', 'o'};
    printf("Taille de la variable taxes: %lu octets\n", sizeof(taxes));
    printf("Taille de la variable student: %lu octets\n", sizeof(student));

    return 0;
}