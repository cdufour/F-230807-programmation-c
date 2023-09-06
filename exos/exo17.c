#include <stdio.h>
#include <string.h>

int main() {
    int nbs[3];

    printf("Entrez 3 nombres: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &nbs[i]);
        if (i == 0) puts("--- Nombres et pointeurs --");
        printf("Nb %d: %d \t| Adr: %p\n", i, nbs[i], &nbs[i]);
    }

    // Méthode 1 : Ré-assignation du pointeur sur l'adresse de la case suivante du tableau
    puts("--- Doublement par re-referencement de pointeur --");
    int* ptr;
    for (int i = 0; i < 3; i++) {
        ptr = &nbs[i];
        *ptr *= 2;
        printf("Nb %d: %d \t| Adr: %p\n", i, nbs[i], &nbs[i]);
    }

    // Méthode 2 : +1 sur le pointeur à la fin de chaque boucle
    /*
    puts("--- Doublement par incrementation de pointeur --");
    ptr = &nbs[0];
    for (int i = 0; i < 3; i++) {
    *ptr *= 2;
    printf("Nb %d: %d \t| Adr: %p\n", i, nbs[i], &nbs[i]);
    ptr++;
    }

    // Comment les additions fonctionnent sur les pointeurs
    // +1 sur un pointeur le fait pointer sur le case mémoire suivante, selon le type
    // donc un +sizeof() ajoute plusieurs +1 et donc peut dépasser la case mémoire suivante
    ptr = &nbs[0];
    printf("\nptr : \t\t%p = adresse de nbs[0]\n", ptr);
    printf("ptr + 1: \t\t%p = adresse de nbs[1]\n", ptr + 1);
    printf("ptr + 2: \t\t%p = adresse de nbs[2]\n", ptr + 2);
    printf("ptr + 3: \t\t%p = adresse d'un potentiel nbs[3]\n", ptr + 3);
    printf("ptr + 4: \t\t%p = adresse d'un potentiel nbs[4]\n", ptr + 4);
    printf("ptr + sizeof(int): \t%p = segmentation fault", ptr + sizeof(int));
    */

    return 0;
}