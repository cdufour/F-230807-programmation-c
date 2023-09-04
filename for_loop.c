#include <stdio.h>

int main()
{
    int n;
    for (n = 65; n < 91;  n++) {
        printf("\n%d\t%c", n, n);
    }
    puts(""); // affichage d'un saut de ligne
    return 0;
}