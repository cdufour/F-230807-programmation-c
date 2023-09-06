#include <stdio.h>

void hello() {
    puts("Hello");
}

int increment(int x) {
    return x + 1;
}

int decrement(int x) {
    return x - 1;
}

int multiply(int a, int b) {
    return a * b;
}

void greetings(char name[]) {
    printf("Ave %s !\n", name);
}

int main()
{
    hello();
    
    int n = 5;
    printf("%d\n", increment(n)); // 6
    printf("%d\n", decrement(n)); // 4
    printf("%d\n", multiply(n, 4)); // 20

    greetings("Chris");

}