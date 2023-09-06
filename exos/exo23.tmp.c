#include <stdio.h>

void convert_to_bin(int n, int *bin_arr, int arr_size) {
    int i = 1;
    while (n != 0) {
        bin_arr[arr_size - i] = n % 2;
        n = n / 2;
        i++;
    }
}

int main() {
    int nb;
    printf("Entrez un nombre en base 10: ");
    scanf("%d", &nb);

    int bin[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    convert_to_bin(nb, bin, sizeof(bin)/sizeof(int));

    printf("Son binaire est: ");
    for (int i = 0; i < sizeof(bin)/sizeof(int); i++) {
        if (bin[i] != -1) printf("%d", bin[i]);
    }

    return 0;  
}

