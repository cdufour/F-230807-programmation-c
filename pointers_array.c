#include <stdio.h>


int main() {

    short int a[4] = {2019, 2020, 2021, 2022};
    short int *ptr1 = &a[0], *ptr2 = &a[3];

    printf("Total size %lu\n", sizeof(a));


    for (int i = 0; i < 4; i++) {
        printf("ptr1 => %hd (%p)\n", a[i], ptr1 + i);
        printf("ptr2 => %hd\n", *(ptr2 - i));
    }


}