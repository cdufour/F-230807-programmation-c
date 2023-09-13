#define EX33 1
#ifdef EX33
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
Ecrire un programme prenant le fichier players.csv entrée.
Créer une structure Player correspondant aux entêtes du fichier.
Le programme placera les données du fichier dans une zone de mémoire
dynamiquement allouée.
Par le biais d'une fonction, calculer la moyenne de buts inscrits
(nombre total de buts / nombre de joueurs).
*/

typedef enum TEAM
{
    TEAM_Juventus,
    TEAM_PSG,
} TEAM;

typedef struct Player
{
    char nom[64];
    int nombre;
    int but;
    TEAM equipe;
} Player;

Player *parseLine(char *line)
{
    Player *pplayer = calloc(1, sizeof(Player));

    char delims[] = ",";
    int id_token = 0;

    char *token = strtok(line, delims);

    while (token != NULL)
    {
        switch (id_token)
        {
        case 0: // nom du joueur :
            break;
        case 1: // nombre
            strncpy(pplayer->nom, line, token - line);
            pplayer->nombre = atoi(token);
            break;
        case 2: // but
            pplayer->but = atoi(token);
            break;
        case 3: // team
            if (!strcmp(token, "Juventus"))
            {
                pplayer->equipe = TEAM_Juventus;
            }
            else if (!strcmp(token, "PSG"))
            {
                pplayer->equipe = TEAM_PSG;
            }
            break;
        }

        id_token++;
        token = strtok(NULL, delims);
    }

    return pplayer;
}

float moyenne_but(Player **players, int nbJoueur);

int main(int argc, char *argv[])
{
    FILE *fin = NULL;

    fin = fopen("players.csv", "r");

    char currentline[128];
    char cur = 0;
    int i_line = 0, line_count = 0;
    int player_max = 10, player_count = 0;
    memset(currentline, 0, 128);

    Player *players[player_max];

    if (!fin)
    {
        fprintf(stderr, "Probleme avec le fichier d'entree");
    }

    while ((cur = fgetc(fin)) != EOF)
    {
        if (line_count > 0)
        {
            currentline[i_line] = cur;
            i_line++;
        }

        if (cur == '\n' && line_count > 0)
        {
            i_line = 0; // retour au debut

            // printf("line : %s\n",currentline);
            players[player_count] = parseLine(currentline);
            memset(currentline, 0, 128);
            player_count++;
        }
        if (cur == '\n')
            line_count++;
    }

    //printf("last line : %s\n", currentline);
    players[player_count] = parseLine(currentline);
    player_count++;

    for (int i = 0; i < player_count; i++)
    {
        printf("nom : %s, il est le numero %d, il a marque : %d buts, et il est dans l'equipe d'id %d\n", players[i]->nom, players[i]->nombre, players[i]->but, players[i]->equipe);
    }

    printf("Moyenne des buts : %.02f\n", moyenne_but(players, player_count));

    return 0;
}

float moyenne_but(Player **players, int nbJoueur)
{
    float total = 0;
    for (int i = 0; i < nbJoueur; i++)
        total += players[i]->but;

    return total / (float)nbJoueur;
}
#endif
