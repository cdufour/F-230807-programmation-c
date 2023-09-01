#include <stdio.h>

int main()
{
    int x = 5, y = 2;
    int result      = 5 / 2;
    float result2   = 5.0 / 2.0;
    float result3   = (float) x / y;

    printf("%d\n", result);
    printf("%.2f\n", result2);
    printf("%.2f\n", result3);

    float pi = 3.14;
    //int pi_int = (int) pi;
    printf("Valeur de pi_int: %d\n", (int) pi);


    return 0;
}