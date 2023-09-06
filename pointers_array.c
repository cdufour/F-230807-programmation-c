#include <stdio.h>

int main() {

    short int a[4] = {2019, 2020, 2021, 2022};
    short int *ptr1 = &a[0], *ptr2 = &a[3];

    printf("Total size %lu\n", sizeof(a));

    for (int i = 0; i < 4; i++) {
        printf("ptr1 => %hd (%p)\n", a[i], ptr1 + i);
        printf("ptr2 => %hd\n", *(ptr2 - i));
    }

    printf("ptr1: %p, ptr2: %p\n", ptr1, ptr2);

    if (ptr1 + 3 == ptr2)
        puts("Pointeurs pointant vers la même addresse");

    ptr1 += 1; // mise à jour du pointeur (changement d'adresse)
    printf("%hd\n", *ptr1);

    *(ptr1 + 2) = 2023; // mise à jour de la valeur
    printf("%hd\n", a[3]);

    return 0;

}