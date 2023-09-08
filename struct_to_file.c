#include <stdio.h>

typedef struct Player {
    char name[40];
    short int position;
    float salary;
} Player;

int main(void) {
    Player player;
    FILE *fptr;

    fptr = fopen("players.dat", "w"); //wb mode pas utile (on travaille avec des chaînes)

    printf("Name, position, salary\n");
    scanf("%s %hd %f", player.name, &player.position, &player.salary);

    // write to file
    fprintf(fptr, "%s %hd %.2f", player.name, player.position, player.salary);
    fclose(fptr);

    return 0;
}