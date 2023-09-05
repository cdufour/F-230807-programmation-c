#include <stdio.h>

int main() {
    char greetings[] = "Salut les amis";
    printf("%s\n", greetings);
    printf("%c\n", greetings[1]); // 'a'
    
    greetings[3] = 'o'; // accès en écriture
    printf("%s\n", greetings); // Salot les amis

    // 2 façons de créer une chaîne
    char greetings2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    char greetings3[] = "Hello World!";
  
    printf("%lu\n", sizeof(greetings2)); // 13
    printf("%lu\n", sizeof(greetings3)); // 13 (le null charactere est décompté également)
  
    return 0;
}