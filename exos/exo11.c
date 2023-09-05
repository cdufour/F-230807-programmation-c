#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab1[2][2]= {{44,10},{86,64}};
    int tab2[2][2]= {{45,10},{86,64}};
    int different = 0; // par défaut on considérer que les matrices ne sont pas différentes (donc elles sont identiques)

    for(int i=0; i<2; i++)
    {
        // inutile d'itérer la boucle externe si une dif a été trouvée
        if (different) break;
        
        printf("Row %d\n", i);
        for(int j=0; j<2; j++)
        {
            printf("Column %d\n", j);
            if(tab1[i][j] != tab2[i][j]) {
                puts("!!! Difference found !!!");
                // si une dif de valeur est trouvée => inverse le flag
                different = 1;
                break;

                // autre possibilité faire retourner la fonction main
                //return 1;
            }
        }
    }

    if(different)
        printf("Tableaux differents");
    else
        printf("Tableaux identiques");

    puts("");

    return 0;
}