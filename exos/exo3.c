#include <stdio.h>

int main() 
{
  int mdp;
  printf("Ecrire un mot de passe : ");
  scanf("%d", &mdp);

  if (mdp == 1234) {
    printf("Tu passes\n");
  } else {
    printf("Tu ne passes pas\n");
  }

  return 0;
}