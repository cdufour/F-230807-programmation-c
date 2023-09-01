#include <stdio.h>

int main(){
    int i = -1;
    int c = 0;
    
    printf("\nEntrer un nombre : ");
    scanf("%d", &i);
    c = i;
    while (i != 0){
        printf("\nEntrer de nouveau un nombre : ");
        scanf("%d", &i);
        c += i;
    }
    puts("C'est le bon !");
    printf("La somme des nombres entres est : %d\n", c);
    return 0;
}