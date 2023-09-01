#include <stdio.h>

int main() {

    int time = 12;

    // ternary à utiliser que pour des simples instructions
    (time < 18) ? puts("Il est tôt") : puts("Il est tard");

    // identique à
    if (time < 18) {
        puts("Il est tôt");
    } else {
        puts("Il est tard");
    }

}