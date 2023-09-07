#include <stdio.h>
#include <stdlib.h>
void nbBinaires(int nb){
    printf("Decimal : %d\n", nb);
    int bin[32];
    int i=0;
    while(nb>0){
        bin[i] = nb%2;
        nb/=2;
        i++;        
    }
    printf("Binaire : ");
    for (int j=i-1;j>=0;j--){
        printf("%d",bin[j]);
    }
    puts("");
}

void nbrDe1(int nbr){
    nbBinaires(nbr);
    int cmp=0;
    while(nbr>0){
        if(nbr%2==1){
            cmp++;
        }
        nbr= nbr >> 1;
    }
    printf("Il contient %d 1 en binaire",cmp);
}

int main(int argc, char* argv[]){
    //nbrDe1(strtol(argv[1],NULL,10));
    nbrDe1(15);
    return 0;
}