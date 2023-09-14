/* Exemples d’utilisation de la commande:
secu_wc file1.txt => output: 5 10 100 file1.txt
secu_wc -c file1.txt => output: 100 file1.txt*/

#include <stdio.h>
#include <string.h>

typedef enum EXEC_MODE
{
    STD,
    CHAR_CNT
} EXEC_MODE;

//  ------------------------------
//              MAIN
//  ------------------------------
int main(int argc, char *argv[])
{
    // Exec vars
    EXEC_MODE mode;
    FILE *fptr = NULL;
    // Exec options vars
    char file_name[40];

    // Options parsing
    if (strcmp(argv[1], "-c") == 0)
    {
        mode = CHAR_CNT;
        strcpy(file_name, argv[2]);
    }
    else
    {
        mode = STD;
        strcpy(file_name, argv[1]);
    }

    // Open file
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", file_name);
        return 1;
    }

    int line_cnt = 0, word_cnt = 0, char_cnt = 0;
    // Crawl file in standard mode
    if (mode == STD)
    {
        char c, cp1;
        while ((c = fgetc(fptr)) != EOF)
        {
            if ((cp1 = fgetc(fptr)) != EOF)
                fseek(fptr, -1, SEEK_CUR);
            if (c == ' ' && cp1 != ' ' && cp1 != '\n' && cp1 != '\0')
                word_cnt++;
            if (c == '\n' || c == '\0')
            {
                word_cnt++;
                line_cnt++;
            }
        }
        line_cnt++;
        char_cnt = ftell(fptr);
        printf("%d %d %d %s\n", line_cnt, word_cnt, char_cnt, file_name);
    }
    // Crawl file in count char mode
    else
    {
        fseek(fptr, 0, SEEK_END);
        char_cnt = ftell(fptr);
        printf("%d %s\n", char_cnt, file_name);
    }
    // Close file
    fclose(fptr);

    return 0;
}