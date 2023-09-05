#include <stdio.h>
int main()
{
    int v1 = 12;
    int* ptr1 = &v1;

    printf("v1: %d\n", v1);
    printf("ptr1: %p\n", ptr1);
    printf("&v1: %p\n", &v1);
    printf("*ptr1: %d\n", *ptr1);

    char str[] = "Toto";
    char* ptr2 = &str[1];

    printf("*ptr2: %c\n", *ptr2);
    printf("*str: %c\n", *str); // en C, un array est un pointer, et à ce titre déréférençable

    *ptr2 = 'i'; // écrasement de la valeur
    puts(str);


}