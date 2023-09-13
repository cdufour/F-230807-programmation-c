#include <stdio.h>

int main() {

    char str[100];

    fscanf(stdin, "%s", str);
    fprintf(stdout, "%c%c\n", str[0], str[1]);


    return 0;
}