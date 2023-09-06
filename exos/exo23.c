#include <stdio.h>

void decimalEnBinaire(int decimal)
{
    if (decimal == 0)
    {
        printf("Le nombre binaire est : 0\n");
        return;
    }

    int binaire[32];
    int i = 0;

    while (decimal > 0)
    {
        binaire[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Le nombre binaire est : ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaire[j]);
    }

    printf("\n");
}

int main()
{
    int decimal;

    printf("Entrez un nombre décimal : ");
    scanf("%d", &decimal);

    decimalEnBinaire(decimal);

    return 0;
}