#include <stdio.h>

int main()
{
    int source = 560;
    int guess = -1;
    int compteur = 0;

    while (guess != source) {
        printf("Saisir un nombre : ");
        scanf("%d", &guess);
        compteur++;
        
        if (guess > source) {
        printf("C'est moins\n");
        } else if (guess < source) {
        printf("C'est plus\n");
        } else {
        printf("C'est gagné\n");
        }
    }
    printf("Vous avez trouvez le nombre en %d coups\n", compteur);

    return 0;
}