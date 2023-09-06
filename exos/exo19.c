#include <stdio.h>
int main()
{
    int a, b, max;
    int *ptr = &a, *ptr2 = &b;

    puts("premier nombre");
    scanf("%d", ptr);

    puts("second nombre");
    scanf("%d", ptr2);
    
    if (*ptr2 > *ptr)
    {
        max = *ptr2;
    }
    else
    {
        max = *ptr;
    }
    printf("Le plus grand est : %d\n", max);
}