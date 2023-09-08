#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *final;
    FILE *final1;
    FILE *final2;
    char myString1[100];
    char myString2[100];
    char new[200];
    int Longueur1;
    int Longueur2;
    int i;
    int j;

    final = fopen("merge.txt", "w");

    final1 = fopen(argv[1], "r");
    final2 = fopen(argv[2], "r");

    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);

    fgets(myString1, 100, final1);
    fgets(myString2, 100, final2);

    Longueur1 = strlen(myString1);
    Longueur2 = strlen(myString2);

   
    for (i = 0; i < Longueur1; i++)
    {
        new[i] = myString1[i];
    }
    puts(new);

    for (j = 0; j < Longueur2; j++)
    {
        new[j + i] = myString2[j];
    }
    puts(new);
    
    fprintf(final, "%s", new);

    fclose(final1);
    fclose(final2);
    fclose(final);
}