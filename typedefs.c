#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define MAX 40
#define TITLE "toto"

typedef short int SI;
typedef unsigned char byte;

typedef struct Book {
    char title[MAX];
    short int publication_year;
    short int pages;
} Book;


void loop() {
    for (int i = 0; i < MAX-30; i++)
        printf("i: %d\n", i);
}

int main()
{
    SI v = 4;
    printf("%hd\n", v);

    byte b1, b2;

    Book book1 = {"Zorro", 2023, 124};
    printf("%s\n", book1.title);
    printf("%s\n", TITLE);

    loop();

    return EXIT_SUCCESS;
}