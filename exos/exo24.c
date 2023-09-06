#include <stdio.h>

void nbPremier(int nb)
{

    int d;
    int tabd[100];
    int i = 0;

    // printf("Entrer un nombre entier : ");
    // scanf("%d", &nb);

    d = nb;

    while (d != 0)
    {
        if ((nb % d) == 0)
        {
            tabd[i] = d;
            i++;
            printf("%d est divisible par %d\n", nb, d);
        }
        else
        {
            printf("%d n'est pas divisible par %d\n", nb, d);
        }
        d--;
    }

    if (tabd[0] == nb && tabd[1] == 1)
    {
        printf("%d est un nombre premier !", nb);
    }
    else
    {
        printf("%d n'est pas un nombre premier !\n", nb);
    }
}

int main(int argc, char *argv[])
{

    nbPremier(*argv[1] - 48);

    return 0;
}