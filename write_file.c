#include <stdio.h>

int main()
{
    FILE *fptr;
    //fptr = fopen("filename.txt", "w"); // w: write mode
    fptr = fopen("filename.txt", "a"); // a: append mode
    short int grade = 13;

    fprintf(fptr, "Tout va super bien ! Ma note est de: %hd\n", grade);

    fclose(fptr); // "libère" le fichier

    return 0;
}