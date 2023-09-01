#include <stdio.h>

int main() {
    int vitMax = 80;
    int vit;
    
    puts("Entre ta vitesse");
    scanf("%d", &vit);

    int offset = vit - vitMax;

    if (offset > 50) {
        puts("Chaise electrique");
    } else if (offset > 40) {
        puts("Prison");
    } else if (offset > 30) {
        puts("Retrait de permis");
    } else if (offset > 20) {
        puts("Amende de 100 EUR");
    } else if (offset > 10) {
        puts("Amende de 50 EUR");
    } else {
        puts("Pas de sanction");
    }

    return 0;
}