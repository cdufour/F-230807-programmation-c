#include <stdio.h>

typedef char BYTE;

int main() {
    FILE * fptr;
    fptr = fopen("poke.png", "rb"); // read binary mode
    BYTE sequence[2];

    sequence[0] = fgetc(fptr); // lecture de l'octet 1
    sequence[1] = fgetc(fptr); // lecture de l'octet 2
    
    for (int i = 0; i < 2; i++) {
        printf("%d\n", sequence[i]);
    }
    
    
    fclose(fptr);
    return 0;
}