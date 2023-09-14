#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *toBinString(unsigned char value)
{
    char *bin = malloc(8);

    for (int i = 0; i < 8; i++)
    {
        bin[7 - i] = ((value >> i) & 1) ? '1' : '0';
    }
    return bin;
}

void genOne(char mode, FILE *out)
{
    unsigned char value;
    switch (mode)
    {
    case 'c':
        value = rand() % 58 + 65;
        fprintf(out, "%c", value);
        break;
    case 'n':
        value = rand() % 10 + 48;
        fprintf(out, "%d", value);
        break;
    case 'b':
        value = rand() % 255;
        fprintf(out, "%s", toBinString(value));
        break;
    case 'h':
        value = rand() % 255;
        fprintf(out, "%x", value);
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    char *mode = argv[1];
    int nb = atoi(argv[2]);
    FILE *fptr;

    if (argc == 5)
    {
        char *file_name = argv[4];
        fptr = fopen(file_name, "a");
    }
    else
    {
        fptr = stdout;
    }
    srand(time(NULL));

    for (int i = 0; i < nb; i++)
    {
        genOne(mode[1], fptr);
    }

    if (argc == 5)
        fclose(fptr);
    return EXIT_SUCCESS;
}