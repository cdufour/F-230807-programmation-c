#include <stdio.h>

int main() {
    int nb1, nb2;
    
    printf("Entrez le premier nombre :\n");
    scanf("%d", &nb1);
    printf("Entrez le second nombre :\n");
    scanf("%d", &nb2);
    printf("Leur produit est: %d\n", nb1 * nb2);
    
    return 0;
}