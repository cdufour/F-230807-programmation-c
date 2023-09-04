#include <stdio.h>

int main()
{
    const int n = 42;
    //n = 66; // error

    // convention: nom de constantes en majuscule
    const float PI = 3.14;

    printf("Constante PI (read-only): %.2f\n", PI);

    /*
    Une constante doit recevoir une initialisation
    Le code ci-dessous ne compile pas:
   
    const float TVA;
    TVA = 5.5;
    */


    return 0;

}