#include <stdio.h>
int main()
{

    // Déclaration de Variables
    int Nombre1 = 5;
    int Nombre2 = 6;
    int Somme;

    int *ptr1 = &Nombre1, *ptr2 = &Nombre2, *ptrS = &Somme;

    // Instructions
    *ptrS = *ptr1 + *ptr2;
    printf("La somme de %d + %d = %d\n", *ptr1, *ptr2, *ptrS);

    return 0;
}