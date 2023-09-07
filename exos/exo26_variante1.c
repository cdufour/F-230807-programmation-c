#include <stdio.h>

int exo26(int nbr)
{
    int quotient = nbr;
    int binResult = 0;
    int bitCompteur; // nb fois apparaît 1
    int compteur = 0;
    int dizaine = 1;
    while(quotient != 0)
    {
        dizaine = 1;
        for(int i = 0; i < compteur ; i++)
        {
            dizaine *= 10;
        }
        binResult += (quotient % 2)*dizaine;
        bitCompteur += (quotient % 2);
        compteur++;
        quotient /= 2;
    }

    printf("le nombre %d s'ecrit %d en binaire et contient %d 1\n", nbr, binResult, bitCompteur);

    return 0;
}

int main(int argc, char *argv[])
{
    exo26(15);
    return 0;
}