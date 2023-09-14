#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void cypher_rotate(char chaine[], int sensRotation, int decalage);

int main(int argc, char *argv[])
{
    /* ToDo:
    fournir à cypher_rotate un argument de ligne de commande
    */
    char mot[] = "ab2aZ";
    cypher_rotate(mot, 0, 4);
    puts(mot);
}
void cypher_rotate(char chaine[], int sensRotation, int decalage)
{

    int longueur = strlen(chaine);
    int mouvement;
    if (sensRotation == 0)
    {
        mouvement = decalage;
    }
    else
    {
        mouvement = -decalage;
    }

    for (int i = 0; i < longueur; i++)
    {
        if ((chaine[i] > 96) && (chaine[i] < 123)) // ascii minuscules
        {

            if ((chaine[i] + (mouvement)) >= 123) 
            {
                int excedent = chaine[i] + mouvement - 122;

                chaine[i] = 96 + excedent;
            }
            else if ((chaine[i] + (mouvement)) <= 96)
            {
                int excedent = 97 - (chaine[i] + mouvement);
                chaine[i] = 123 - excedent;
            }
            else
            {
                chaine[i] = chaine[i] + mouvement;
            }
        }
    }
}
