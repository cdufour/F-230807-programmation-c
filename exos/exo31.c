#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int static_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int qty = atoi(argv[1]);

    int* dynamic_tab = calloc(sizeof(int), qty);

    for(int i = 0; i < qty; i++)
    {
        dynamic_tab[i] = static_tab[i];
        printf("%d ", dynamic_tab[i]);
    }

    free(dynamic_tab);

    return 0;    
}