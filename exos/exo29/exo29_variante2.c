#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2, *fptr3;
    fptr1 = fopen(argv[1], "r");
    fptr2 = fopen(argv[2], "r");
    fptr3 = fopen(argv[3], "w");

    char data1[100];
    char data2[100];

    char c;
    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr3);
    }
    while ((c = fgetc(fptr2)) != EOF)
    {
        fputc(c, fptr3);
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3); // ajoute automatiquement le EOF

    return EXIT_SUCCESS;
}