#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char chaine[20];
    short int voy = 0;
    short int cons = 0;
    short int i;

    puts("Entrez une chaîne de caractère : \n");
    gets(chaine);

    for (i=0; i < strlen(chaine); i++) {
        switch(chaine[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                voy++;
                break;
            default:
                cons++;
        }
    }
    
    printf("Il y a %hd voyelles.\n",voy);
    printf("Il y a %hd consonnes.\n",cons);

}