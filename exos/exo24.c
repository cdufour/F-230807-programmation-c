
#include <stdio.h>
#include <stdlib.h> 

int PrimeOrNot(int);

int main(int argc, char *argv[])
{
    int n1, prime;
    printf("\n\n Function : check whether a number is prime number or not :\n");
    printf("---------------------------------------------------------------\n");

    //printf(" Input a positive number : ");
    //scanf("%d", &n1);

    n1 = atoi(argv[1]);
    prime = PrimeOrNot(n1);

    if (prime == 1)
        printf(" The number %d is a prime number.\n", n1);
    else
        printf(" The number %d is not a prime number.\n", n1);
    return 0;
}

int PrimeOrNot(int n1)
{
    int i = 2;
    while (i <= n1 / 2)
    {
        //printf("i: %d, n1: %d, n1/2: %d\n", i, n1, n1/2);
        //printf("n1 mod i: %d\n", n1 % i);
        if (n1 % i == 0)
            return 0;
        else
            i++;
    }
    return 1;
}

