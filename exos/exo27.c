#include <stdio.h>
#include <string.h>

typedef struct Couple {
    short int ageF;
    short int ageH;
} Couple;

int main() {

    short int nbcouple;
    int i;
    short int ageF_input;
    short int ageH_input;
    short int c=0;
    int percent;
    Couple couple={0,0};

    printf("Combien de couples ? \n");
    scanf("%hd", &nbcouple);

    Couple coupleTab[nbcouple];

    for (i=0;i<nbcouple;i++){

        printf("Couple n° %d :\n",i);
        printf("Quel est l'âge de la femme ? ");
        scanf("%hd", &ageF_input);

        printf("Quel est l'âge de l\'homme ? ");
        scanf("%hd", &ageH_input);

        Couple couple = {ageF_input, ageH_input};
        coupleTab[i]= couple;

        if (ageF_input > ageH_input){
            c++;
        }
    }

    percent=(int) ((float)c/nbcouple * 100);

    printf("Il y a %d %% de femmes plus agees que les hommes.\n",percent);

    return(0);
}