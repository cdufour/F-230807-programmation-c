#include <stdio.h>
#include <stdlib.h>

void demo(int mem_size);
char * demo2(int mem_size);
void demo3(char * ptr, int mem_size, char c);

int main() {

    // 4 entiers sur le stack (pile)
    int a[4] = {23, 6, 89, 102};

    // 4 entiers sur le heap (tas)
    int * b = malloc(sizeof(int) * 4);
    printf("%p\n", b);

    b[0] = 23;
    b[1] = 6;
    *(b+2) = 89;
    *(b+3) = 102;
    

    for (int i = 0; i < 4; i++)
        printf("%d\n", b[i]);

    free(b);

    puts("-------------------------");

    for (int i = 0; i < 4; i++)
        printf("%d\n", b[i]);

    demo(100);

    puts("-------------------------");
    char * c = demo2(100);

    for (int i = 0; i < 10; i++)
        printf("%c\n", c[i]);
    
    free(c);

    puts("-------------------------");
    char * d = (char *) malloc(100 * sizeof(char));
    demo3(d, 100, 'p');
    
    for (int i = 0; i < 10; i++)
        printf("%c\n", d[i]);

    free(d);


    return 0;
}

void demo(int mem_size) {
    char *ptr;

    ptr = (char *) malloc(mem_size * sizeof(char));

    for (int i = 0; i < mem_size; i++)
        *(ptr + i) = 'x';

    free(ptr);
}

char * demo2(int mem_size) {
    char *ptr;

    ptr = (char *) malloc(mem_size * sizeof(char));

    for (int i = 0; i < mem_size; i++)
        *(ptr + i) = 'x';

    return ptr;
}

void demo3(char * ptr, int mem_size, char c) {
    
    for (int i = 0; i < mem_size; i++)
        *(ptr + i) = c;
}
