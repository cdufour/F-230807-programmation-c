#include <stdio.h>

int main() {

    int n = 5;
    printf("Valeur de n: %d\n", n);

    n = 9;
    printf("Valeur de n: %d\n", n);

    float pi = 3.14159265358979323846;
    //printf("Valeur de pi: %f\n", pi); // Valeur de pi: 3.141593
    printf("Valeur de pi: %.8f\n", pi);

    double pi_bis = 3.14159265358979323846;
    //printf("Valeur de pi_bis: %f\n", pi_bis);
    printf("Valeur de pi_bis: %.10f\n", pi_bis);

    char c = 'A';
    printf("Valeur de c en base 10: %d => en caractère: %c\n", c, c);

    // exemple de nommage en "camel case"
    int numberStudentsInSchool = 15;

    // exemple de nommage en "snake case"
    int number_teachers_in_school = 4;

    int grade1 = 3, grade2 = 13;
    printf("Note1: %d, Note2: %d\n", grade1, grade2);

    // error: invalide syntax
    //int 3grade = 20; 

    unsigned short int demo = 31123;
    printf("Valeur de demo: %hu\n", demo);
    //printf("Valeur de demo: %d\n", demo);

    return 0;
}