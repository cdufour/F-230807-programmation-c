// ProjetC.c
// AJC Formation
/*
*
secu_wc
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define LEN_CLEF 16
#define MAX_LEN 255
#define FALSE 0
#define TRUE 1

typedef int Bool;

// Déclaration des fonctions

int secu_wc(int argc, char *argv[]);

int main(int argc, char *argv[])
{ // debut main

    int CodeErr = secu_wc(argc, argv);

    if (CodeErr)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
} // fin main

// Definition des Fonctions

int secu_wc(int argc, char *argv[])
{
    int rtn_open;
    char erreurOpen[MAX_LEN];

    Bool CaracteresSeuls = FALSE;

    int caractere = '#';

    int NombreLignes = 1;
    int NombreMots = 1;
    int NombreCaracteres = 0;

    char NomFichier[MAX_LEN];

    FILE *Fileptr;

    if (argc < 2)
    {
        fprintf(stderr, "Erreur : Pas assez d'arguments en entree\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) // On traite les arguments données en entrée du programme (Les arguments peuvent être donner dans le désordre et ça marche quand même)
    {                              // debut for

        if (strcmp(argv[i], "-c") == 0)
        {
            CaracteresSeuls = TRUE;
            i++;
            strcpy(NomFichier, argv[i]);
        }
        else
        {
            strcpy(NomFichier, argv[i]);
        }
    } // fin for

    Fileptr = fopen(NomFichier, "r");

    /*
    if (rtn_open != 0) // Si on arrive pas a ouvrir le fichier on renvoie une erreur pour eviter un acces interdit en memoire
    {
        //strerror(erreurOpen, errno);
        fprintf(stderr, "Erreur : %s\n", erreurOpen);
        return EXIT_FAILURE;
    }
    */

    while (caractere != EOF)
    {
        caractere = fgetc(Fileptr);

        switch (caractere) // On considère que le retour à la ligne et l'espace sont des caractères et qu'un mot ne s'étend pas sur 2 lignes
        {
        case '\n':
            NombreLignes++;
            NombreMots++;
            NombreCaracteres++;
            break;
        case ' ':
            NombreMots++;
            NombreCaracteres++;
            break;
        default:
            NombreCaracteres++;
            break;
        } // fin switch
    }     // fin while

    fclose(Fileptr);

    if (CaracteresSeuls)
        printf("%d %s\n", NombreCaracteres, NomFichier); // Choix que les caractères avec -c
    else
        printf("%d %d %d %s\n", NombreLignes, NombreMots, NombreCaracteres, NomFichier); // Choix sans -c avec toutes les infos

    return EXIT_SUCCESS;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
//
// Les arguments sont à passer dans : Débogueur Windows local / Propriétés de débogage de #NomDeProjet / Paramètres de configuration / Débogage / Arguments de la commande
