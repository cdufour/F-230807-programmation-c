#include <stdio.h>

int main() {
    int a = 42, b = 42;
    int c = 0xe0ffd8ff; // base 16 (hexa);
    int *ptr1, *ptr2, *ptr3;
    char c1 = 0xff, c2 = 0xd8, c3 = 0xff, c4 = 0xe0;
    unsigned char h[4] = {0xff, 0xd8, 0xff, 0xe0};
    unsigned char *ptc1, *ptc2;

    ptr1 = &a;
    ptr2 = &b;
    ptr3 = &c;
    ptc1 = &c1;
    ptc2 = &h[0];

    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2);
    printf("%x\n", *ptr3);

    for (int i = 0; i < 4; i++)
        printf("%x\n", h[i]);
    
    puts("***************************");
    printf("%x\n", *ptc2);
    printf("%x\n", *(ptc2 + 1));

    if (*ptc1 == *ptc2)
        puts("Pointeurs ptc1 et ptc2 déférencent la même valeur");

    if (ptc1 != ptc2)
        puts("Pointeurs ptc1 et ptc2 poitent des addresses différentes");

    printf("*ptr3 = %x\n", *ptr3); // e0ffd8ff
    printf("*h = %x\n", *h); // ff
    printf("*(int *)h = %x\n", *(int *)h); // pointer casting e0ffd8ff Cf Big/Little Endian problem
    printf("*(int *)ptr3 = %x\n", *(int *)ptr3); // casting inutile, ptr3 est déjà un int *
    
    return 0;
}