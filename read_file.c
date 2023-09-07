#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("filename.txt", "r");
    char data[100];

    fgets(data, 20, fptr);
    fclose(fptr); // "libère" le fichier

    printf("%s\n", data);

    return 0;
}