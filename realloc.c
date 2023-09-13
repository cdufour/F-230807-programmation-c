#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr, i, n1, n2;
    printf("Size: ");
    scanf("%d", &n1);

    ptr = (int *) malloc(n1 * sizeof(int));

    printf("Addresses allocated:\n");
    for (i = 0; i < n1; i++)
        printf("%p\n", ptr + i);

    printf("New size: ");
    scanf("%d", &n2);

    // memory reallocation
    ptr = realloc(ptr, n2 * sizeof(int));

    printf("Addresses newly allocated:\n");
    for (i = 0; i < n2; i++)
        printf("%p\n", ptr + i);

    free(ptr);
    return 0;
}