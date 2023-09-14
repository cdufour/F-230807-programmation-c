#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN_MDP 32
#define MAX_CHAINE 255
#define SEED time(NULL)
#define ASCII_OFFSET 33
#define ASCII_CHIFFRE_OFFSET 47
#define ASCII_CHIFFRE_MAX 58
#define ASCII_MAJUSCULE_OFFSET 64
#define ASCII_MAJUSCULE_MAX 91
#define ASCII_MINUSCULE_OFFSET 96
#define ASCII_MINUSCULE_MAX 123
#define SUCESS_STRONG 1
#define FAILURE_STRONG 0
#define NB_BYTE_CHECK 3
#define NB_EXTENSION 5
#define TRUE 1
#define FALSE 0

void generate_password(char Password[], int length, int NbSpeChar)
{
    // Déclaration de Variables
    int RandInt, i;
    int caractere, SpeCharOk = 0, MajCharOk = 0, ChiffreOk = 0, MinCharOk = 0;

    // Initialisation
    srand(SEED); // Seed pour la fonction srand()

    // Instruction
    for (i = 0; i < length; i++)
    { // debut for

        RandInt = (rand() % 93) + ASCII_OFFSET;

        if ((RandInt > ASCII_CHIFFRE_OFFSET) && (RandInt < ASCII_CHIFFRE_MAX))
            ChiffreOk = 1;
        if ((RandInt > ASCII_MAJUSCULE_OFFSET) && (RandInt < ASCII_MAJUSCULE_MAX))
            MajCharOk = 1;
        if ((RandInt > ASCII_MINUSCULE_OFFSET) && (RandInt < ASCII_MINUSCULE_MAX))
            MinCharOk = 1;

        switch (RandInt)
        { // debut switch
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 123:
        case 124:
        case 125:
        case 126:
            if (NbSpeChar == 1)
            {
                Password[i] = (char)RandInt;
                SpeCharOk = 1;
            }
            else
            {
                i--;
            }
            break;
        default:
            // pas face à un caractère spécial
            Password[i] = (char)RandInt;
            break;
        } // fin switch
    }     // fin for

    if ((SpeCharOk == 0) && (NbSpeChar == 1))
    {
        RandInt = (rand() % 14) + ASCII_OFFSET;
        int index = rand() % length;
        Password[index] = (char)RandInt;
    }

    if (ChiffreOk == 0)
    {
        RandInt = (rand() % 10) + ASCII_CHIFFRE_OFFSET + 1;
        int index = rand() % length;
        Password[index] = (char)RandInt;
    }

    if (MajCharOk == 0)
    {
        RandInt = (rand() % 26) + ASCII_MAJUSCULE_OFFSET + 1;
        int index = rand() % length;
        Password[index] = (char)RandInt;
    }

    if (MinCharOk == 0)
    {
        RandInt = (rand() % 26) + ASCII_MINUSCULE_OFFSET + 1;
        int index = rand() % length;
        Password[index] = (char)RandInt;
    }

    Password[i] = '\0';

    return;
}

int main(int argc, char *argv[])
{
    // Déclaration de Variables
    char Caractere;
    int LongueurMDP, NombreCaractereSpeciaux;
    char MotDePasse[LEN_MDP];

    // Instructions
    printf("Saisir la longueur du mot de passe choisi ( au moins 10 ) : ");
    scanf("%d", &LongueurMDP);

    if (LongueurMDP < 10)
    {
        printf("Il faut au moins 10\n");
        return EXIT_FAILURE;
    }

    printf("Saisir s'il doit y avoir un caracteres speciaux choisis (Oui = 1 / Non = 0) : ");
    scanf("%d", &NombreCaractereSpeciaux);

    if ((NombreCaractereSpeciaux != 0) && (NombreCaractereSpeciaux != 1))
    {
        printf("Il faut Oui = 1 / Non = 0\n");
        return EXIT_FAILURE;
    }

    generate_password(MotDePasse, LongueurMDP, NombreCaractereSpeciaux);
    printf("\nLe mot de passe genere est : %s\n", MotDePasse);
    return EXIT_SUCCESS;
}