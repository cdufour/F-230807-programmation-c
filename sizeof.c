// C Program To demonstrate
// sizeof operator
#include <stdio.h>
int main()
{
	printf("char: %lu\n", sizeof(char));
    printf("short int: %lu\n", sizeof(short int));
	printf("int: %lu\n", sizeof(int));
    printf("long int: %lu\n", sizeof(long int)); // égal à: sizeof(long)
	printf("long long int: %lu\n", sizeof(long long));
	printf("float: %lu\n", sizeof(float));
	printf("double: %lu\n", sizeof(double));
    printf("long double: %lu\n", sizeof(long double));
	return 0;
}
