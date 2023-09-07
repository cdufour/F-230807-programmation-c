#include <stdio.h>
#include <stdlib.h>

#define PENTAGONE 5

typedef struct Point {
    float x;
    float y;
} Point;

void DoublePoints(Point ** point, int length);

// Les arguments sont à passer dans : Débogueur Windows local / Propriétés de débogage de #NomDeProjet / Paramètres de configuration / Débogage / Arguments de la commande

int main(int argc, char* argv[])
{
    // Déclaration de Variables

    Point point1 = { 0.0, 0.0 };
    Point point2 = { 1.0, 0.0 };
    Point point3 = { 0.0, 1.0 };
    Point point4 = { 1.0, 1.0 };
    Point point5 = { 1.5, 1.5 };

    Point * Figure[PENTAGONE] = { &point1, &point2, &point3, &point4, &point5 }; // Je passe en référence les points sinon ça marche pas

    // Instructions

    printf("Figure : \n");

    DoublePoints(Figure, PENTAGONE);

    return EXIT_SUCCESS; // ==> return 0;
}

void DoublePoints(Point ** Figure, int length) // Double tous les points de la figure
{
    for (int i = 0; i < length; i++)
    {
        Figure[i]->x *= 2.0;
        Figure[i]->y *= 2.0;
        printf("X = %.2f et Y = %.2f pour le point %d\n", Figure[i]->x, Figure[i]->y, i+1);
    }
    return;
}
