#include <stdio.h>

int fact(int num){
    int fact = num;
    for(int i = 1; i < num; i++){
        fact *= num - i;
    }
    return fact / num;
}

int main()
{
  printf("Somme de la série : %d\n", fact(1)+fact(2)+fact(3)+fact(4)+fact(5));
  return 0;
}