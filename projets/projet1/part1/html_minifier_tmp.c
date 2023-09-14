#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN_MDP 32
#define MAX_CHAINE 255

#define TRUE 1
#define FALSE 0

void html_minifier(FILE *file) // on peut créer un html autre : html_src != html_dst
{
    // Déclaration de Variables
    char caractere = ' ';
    char chaine1[MAX_CHAINE];
    char chaine2[MAX_CHAINE];
    char *NomFichier = "sortie.html";
    FILE *File2ptr;

    // Instructions
    File2ptr = fopen(NomFichier, "w");

    while (caractere != EOF)
    {
        caractere = fgetc(file);
        if ((caractere == ' ') || (caractere == '\t') || (caractere == '\n') || (caractere == '\r'))
            ;
        else
            fputc(caractere, File2ptr);
    }

    fputc(EOF, file);
    fclose(File2ptr);

    return;
}

int main(int argc, char *argv[])
{
    // Déclaration de Variables

    char *NomFichier2 = "files/projet.html";
    FILE *File2ptr;

    // Instructions
    File2ptr = fopen(NomFichier2, "r");
    html_minifier(File2ptr);
    fclose(File2ptr);

    return EXIT_SUCCESS;
}