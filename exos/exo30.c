#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
    int a=strtol(argv[1],NULL,10);
    int b=strtol(argv[2],NULL,10);
    
    if(b==0){
        fprintf(stderr, "Error: Division par 0");
        return 1;
    }
    
    int res = a/b;
    //printf("%d\n", errno); inutile dans notre exemple
    printf("Le resultat est %d\n", res);
    return 0;
}