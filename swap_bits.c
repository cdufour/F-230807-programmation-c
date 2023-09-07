#include <stdio.h>

/*
Hexa: 0XA
Bin: 0000 1010
Dec: 10

Après inversion des bits 1 et 2
Bin: 0000 1100
Hexa: 0xC
Dec: 12
*/

int main() {
    unsigned char data = 0xA; // hexa value

    // obtient le premier bit de data
    unsigned char bit_1 = (data >> 1) & 1;
    printf("%d\n", bit_1);

    // obtient le deuxième bit de data
    unsigned char bit_2 = (data >> 2) & 1;
    printf("%d\n", bit_2);

    // XOR de bit_1 et bit_2
    unsigned char xor_of_bit = bit_1 ^ bit_2;
    printf("%d\n", xor_of_bit);
    
    printf( "Après inversion: %X\n", data ^ (xor_of_bit << 1 | xor_of_bit << 2 ) );



    // 0000 1010
    // 0000 0101
    // & 1
    // 0000 0001
}