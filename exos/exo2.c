#include <stdio.h>

int main()
{
    int celsius = 0;

    printf("Entrez une temperature en celsius ?");
    scanf("%d", &celsius);

    if (celsius < -50 || celsius > 50)
    {
        printf("Veuillez entrez une temp entre -50 et +50 C\n");
        return 1;
    }

    printf("farenheit: %.2f\n", (float) (celsius*(9.0/5.0))+32.0);
    
    return 0;
}