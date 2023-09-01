#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x = 5, y = 3;

    printf("%d\n", y < x); // 1
    printf("%d\n", !(y < x)); // 0
    printf("%d\n", !(!(y > x))); // 0 -> 1 -> 0

    // évaluation booléenne par Et logique (&&) entre
    // deux expressions comparatives
    printf("%d\n", !(x > 3 && x < 10));


    bool isGoodTeacher = false;
    printf("%d\n", isGoodTeacher);

    if (1) {
        printf("Vrai !\n");
    }

    if (isGoodTeacher) {
        puts("Bon prof");
    }

    // version compacte (si une seule instruction)
    if (isGoodTeacher) puts("Bon prof");

    if (isGoodTeacher) {
        puts("Bon prof");
    } else {
        puts("Mauvais prof");
    }

    if (x == 5) {
        puts("x vaut 5");
    }

    return 0;
}