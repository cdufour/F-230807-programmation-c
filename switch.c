#include <stdio.h>

int main() {

    char letter = 'r';

    switch (letter) {
        case 'R':
            puts("Red (rouge)");
            break;
        case 'G':
            puts("Green (vert)");
            break;
        case 'B':
            puts("Blue (bleu)");
            break;
        default:
            puts("???");
    }

}