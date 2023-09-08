#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // getfc lecture / fputc écriture

    char data[100], file1[50], file2[50], resultat[50];
    /*printf("f1 %s\n",argv[1]);
    printf("f2 %s\n",argv[2]);
    printf("f3 %s\n",argv[3]);
    */
    
    strcpy(file1, argv[1]);
    puts(file1);


    // file2[50],resultat[50]
    FILE *fptr;

    // open

    // fptr = fopen("partie1.txt", "r");
    fptr = fopen(file1, "r");
    if (fptr != NULL)

    {
        fgets(data, 200, fptr);
        fclose(fptr);
        printf("%s \n", data);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s", file1);
    }

    // close

    // open
    // fptr = fopen("data.txt", "r");
    fptr = fopen(argv[3], "a");
    fprintf(fptr, "%s", data);
    fclose(fptr);
    // close

    // open
    // fptr = fopen("partie2.txt", "r");
    fptr = fopen(argv[2], "r");
    char lecture[100];
    int i = 0;
    while (!feof(fptr))
    {
        lecture[i] = fgetc(fptr);
        i++;
    }
    fclose(fptr);
    printf("%s \n", lecture);
    // close

    // open
    int counter;
    // fptr = fopen("data.txt", "r");
    fptr = fopen(argv[3], "a");
    for (i = 0; i < strlen(lecture) - 1; i++)
    {
        fputc(lecture[i], fptr);
    }
    fclose(fptr);
    // close

    
    return 0;
}