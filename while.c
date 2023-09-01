#include <stdio.h>

int main()
{
    int n = 65;
    while (n < 91) {
        printf("\n%d\t%c", n, n);
        n++;
    }
    puts(""); // affichage d'un saut de ligne
    return 0;
}