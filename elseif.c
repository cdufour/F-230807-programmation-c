#include <stdio.h>

int main()
{
    int temperature = 21;


    // ces ifs qui se suivent sont évalués indépendamment
    if (temperature > 30) {
        puts("Canicule !");
    }

    if (temperature > 20) {
        puts("Agréable !");
    }

    if (temperature > 10) {
        puts("Frisquet !");
    }

    // dès qu'une condition est rencontrée, sortie
    //  du bloc if..else if..else
    if (temperature > 30) {
        puts("Canicule !");
    } else if (temperature > 20) {
        puts("Agréable");
    } else if (temperature > 10) {
        puts("Frisquet");
    } else {
        puts("???");
    }
    

    return 0;

}