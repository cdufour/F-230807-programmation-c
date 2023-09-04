#include <stdio.h>

int main(){

    int tabVal[] = {45, 25, 21};
    int valmax, valmin;

    valmin = tabVal[0];
    valmax = tabVal[0];

    for (int i=1; i<=2; i++){
        if (tabVal[i] < valmin) valmin = tabVal[i];
        if (tabVal[i] > valmax) valmax = tabVal[i];
    }

    printf("L'element max est : %d\nL'element min est : %d\n", valmax, valmin);

    return 0;
}