#include <stdio.h>

int main() {

    int i = 0;
    int val;
    int myTab[4];

    for (i = 0; i < 4; i++) {
        printf("Entrez un nombre : ");
        scanf("%d", &val);
        myTab[i] = val;
    }
    
    // parcours dans l'ordre inverse
    for (i = 3; i >= 0; i--) {
        printf("%d\n", myTab[i]);
    }

}