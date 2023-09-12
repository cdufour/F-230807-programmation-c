/*
#ifdef, #else, #endif
#if, #elif, #else, #endif
*/
#include <stdio.h>

//#define DEBUG 1
#define EN_US 1
#define EN_UK 2
#define FR_FR 3
#define LANG EN_US


int main() {

    #ifdef DEBUG
        printf("Debug is ON\n");
        puts("Hello !");
    #else
        printf("Debug is OFF\n");
    #endif

    #if LANG == EN_US
        puts("Selected language: EN_US");
    #elif LANG == EN_UK
        puts("Selected language: EN_UK");
    #else
        puts("Selected language: FR_FR");
    #endif

    return 0;
}