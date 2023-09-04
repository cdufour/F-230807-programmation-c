#include <stdio.h>

int main() {
    int tableauDeDepart[] = {25, 47, 0, 42, 56, 42};
    int taille = sizeof(tableauDeDepart) / sizeof(tableauDeDepart[0]);
    
    int tableauPairs[taille];
    int tableauImpairs[taille];
    
    int nbPairs = 0;
    int nbImpairs = 0;

    for (int i = 0; i < taille; i++) {

        if (tableauDeDepart[i] == 0) continue;

        if (tableauDeDepart[i] % 2 == 0) {
            tableauPairs[nbPairs] = tableauDeDepart[i];
            nbPairs++;
        } else {
            tableauImpairs[nbImpairs] = tableauDeDepart[i];
            nbImpairs++;
        }
    }

    printf("Les éléments pairs: ");
    for (int i = 0; i < nbPairs; i++) {
        printf("%d ", tableauPairs[i]);
    }
    
    printf("\nLes éléments impairs: ");
    for (int i = 0; i < nbImpairs; i++) {
        printf("%d ", tableauImpairs[i]);
    }

    puts("");

    return 0;
}