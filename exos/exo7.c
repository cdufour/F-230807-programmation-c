#include <stdio.h>

int main() {

    float s = 0;
    int i;
    int c = 0;
    float myFloats[] = {25.5, 50.20, 75.35};

    // Sommes des éléments
    for (int i = 0; i<3; i++) {
        s = s + myFloats[i];

        if (myFloats[i] < 60.0 && myFloats[i] > 30.0) {
            c = c + 1;
        }
    }
    printf("La somme des nombres est %.1f\n", s);
    printf("Il y a  %d nb compris entre 30 et 60\n", c);
        
    return 0;
}