/*
33. Ecrire un programme prenant le fichier PLAYER.csv entrée.
Créer une structure Player correspondant aux entêtes du fichier.
Le programme placera les données du fichier dans une zone de mémoire
dynamiquement allouée.
Par le biais d'une fonction, calculer la moyenne de buts inscrits
(nombre total de buts / nombre de joueurs).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PLAYER {
    char name[40];
    unsigned short number;
    unsigned short goals;
    char team[40];
} PLAYER; 

float goals_mean_number(PLAYER* tab, int len); // Return all players goal mean count


int main(int argc, char *argv[]) {
    // Pass CSV file to parse as first argument
    char csv_file[40];
    strcpy(csv_file, argv[1]);

    // Open CSV file
    FILE * csv_ptr = fopen(csv_file, "r");
    if (!csv_ptr) {
        fprintf(stderr, "Error opening file %s\n", csv_file);
        return 0;
    }

    // Count number of lines and search end of first line which contains headers
    char c; int first_break = 0; int line_cnt = 0;
    while ((c = fgetc(csv_ptr)) != EOF) {
        if (c == '\n') { 
            line_cnt++;
            if (first_break == 0) {
                first_break = (int) ftell(csv_ptr);
            }
        }
    }
    printf("Joueur a ajouter: %d\n", line_cnt);
    first_break += sizeof(char)*2; // Skip \n at the end of headers line
    
    // Create dynamic size PLAYER array
    PLAYER* p_tab = (PLAYER *) malloc(sizeof(PLAYER) * line_cnt);

    // Fill the array, skipping first line with column headers
    fseek(csv_ptr, first_break, SEEK_SET);
    for (int i = 0; i < line_cnt; i++) {
        // Scan next line with correct format
        fscanf(csv_ptr, "%[^,],%d,%d,%[^\n]\n", &p_tab[i].name, &p_tab[i].number, &p_tab[i].goals, &p_tab[i].team);
        printf("Joueur ajoute: %s ; %d ; %d ; %s\n", p_tab[i].name, p_tab[i].number, p_tab[i].goals, p_tab[i].team);
    }

    printf("Moyenne des buts: %.2f", goals_mean_number(p_tab, line_cnt));

    free(p_tab);
    return 0;
}

// Return all players goal mean count
float goals_mean_number(PLAYER* tab, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += tab[i].goals;
    }
    return (float) sum / len;
}