#include <stdio.h>
#include <string.h>

struct Book {
    char title[40];
    short int publication_year;
    short int pages;
};

void print_book(struct Book book);
void print_title(struct Book *book);

int main()
{
    struct Book book1;
    struct Book book2 = {"Nord", 1939, 376};
    
    strcpy(book1.title, "Madame Bovary");
    book1.publication_year = 1857;
    book1.pages = 450;

    print_book(book2);
    book2.pages += 20;
    print_book(book2);

    print_title(&book1);

    printf("book1 size: %lu\n", sizeof(book1));
    printf("book2 size: %lu\n", sizeof(book2));

    return 0;
}

void print_book(struct Book book) {
    printf("%s, paru en %hd, %hd pages\n", 
        book.title, book.publication_year, book.pages);
}

void print_title(struct Book *book) {
    printf("Titre: %s\n", book->title);
}