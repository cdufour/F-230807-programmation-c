#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int nb, somme = 0;
    printf("De combien de nombre voulez vous faire la somme ?\n");
    scanf("%d", &nb);
    int *tabRes = calloc(nb, sizeof(int));
    for (int i = 0; i < nb; i++)
    {
        printf("Il reste %d nombre & entrer\n", nb - i);
        scanf("%d", &tabRes[i]);
        somme += tabRes[i];
    }
    printf("La somme des nombres entre est %d\n", somme);
    free(tabRes);

    return 0;
}