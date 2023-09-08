#include <stdio.h>

int exo29(char file_name1[], char file_name2[])
{
    FILE *fptr1;
    FILE *fptr2;

    fptr1 = fopen(file_name1, "r");
    char data1[100];
    fgets(data1, 20, fptr1);
    fclose(fptr1);

    fptr2 = fopen(file_name2, "r");
    char data2[100];
    fgets(data2, 20, fptr2);
    fclose(fptr2);

    puts(data1);
    puts(data2);

    
    FILE *fptr3;
    fptr3 = fopen("res.txt", "a");
    fprintf(fptr3, "%s", data1);
    fprintf(fptr3, "%s", data2);
    fclose(fptr3);
    
    return 0;
}

int main(int argc, char *argv[])
{
    exo29(argv[1], argv[2]);
    return 0;
}