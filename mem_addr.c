#include <stdio.h>

int main()
{
    //int v1 = 14;
    //int v2 = 15;

    char v1 = 'a';
    char v2 = 'b';

    printf("&v1: %p\n", &v1);
    printf("&v2: %p\n", &v2);

    //char str[] = "toto";
    int str[] = {45, 12, 8, 9};
    printf("&str: %p\n", &str);
    //printf("&str[0]: %p\n", &str[0]);
    //printf("&str[1]: %p\n", &str[1]);

    int i;
    for (i = 0; i < 4; i++)
        printf("&str[%d]: %p\n", i, &str[i]);


    return 0;
}