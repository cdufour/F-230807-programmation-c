#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FILE_NOT_FOUND 2

int main() {

    FILE * pfile;
    pfile = fopen("ghost.txt", "r");

    //fprintf(stdout, "Coucou\n");
    //fprintf(stderr, "Au revoir\n");

    if (pfile == NULL) {
        printf("Error\n");
        printf("%d\n", errno);
        if (errno == FILE_NOT_FOUND) {
            // puts("File not found"); // écrit dans par défaut dans stdout
            fprintf(stderr, "Error: %s\n", strerror(errno));
        }
    } else {
        printf("%d\n", errno);
        fclose(pfile);
    }

    return 0;
}
