#include <stdio.h>

#define MAX 3

typedef enum Color { 
    RED, 
    GREEN, 
    BLUE 
} Color;


int main(int argc, char **argv) {

    Color c1 = RED, c2 = BLUE;
    Color colors[MAX] = {RED, RED, GREEN};

    if (c1 != c2) puts("c1 et c2 sont des couleurs différentes");

    for (int i = 0; i < MAX; i++)
        printf("%d\n", *(colors + i));

    return 0;
}