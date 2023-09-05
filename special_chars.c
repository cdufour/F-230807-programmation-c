#include <stdio.h>
int main()
{
    char str[] = "\"Guillemets\", 'Apostrophe', \\Antislash\\";
    puts(str);

    char str2[] = {'L', '\'', 'e', 'c', 'r', 'i', 't', '\0'};
    puts(str2);

    return 0;
}