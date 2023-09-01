#include <stdio.h>

int main()
{
    int n = 42;

    n++;
    printf("Valeur de n: %d\n", n);

    n = n + 1;
    printf("Valeur de n: %d\n", n);

    n += 1; // ajoute 1 à la valeur stockée dans n
    printf("Valeur de n: %d\n", n);

    n--;
    printf("Valeur de n: %d\n", n);

    n = n - 1;
    printf("Valeur de n: %d\n", n);

    n -= 1; // retranche 1 à la valeur stockée dans n
    printf("Valeur de n: %d\n", n);


    int i;
    int j = 0, k = 0;

    printf("j = %d ; k = %d\n", j, k); // j = 0 ; k = 0
    j++;
    k++;
    printf("j = %d ; k = %d\n", j, k); // j = 1 ; k = 1
    j = k++; // incrémentation APRES affectation
    printf("j = %d ; k = %d\n", j, k); // j = 1 ; k = 2
    j = ++k; // incrémentation AVANT affectation
    printf("j = %d ; k = %d\n", j, k); // j = 3 ; k = 3
    j = k--;
    printf("j = %d ; k = %d\n", j, k); // j = 3 ; k = 2
    j = --k;
    printf("j = %d ; k = %d\n", j, k); // j = 1 ; k = 1


    return 0;
}