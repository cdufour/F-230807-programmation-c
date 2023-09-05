#include <stdio.h>
int main()
{
    int ma[3][3]={ {1,1,1},{2,2,2},{3,3,3} };
    int mb[3][3]={ {4,4,4},{3,3,3},{2,2,2} };

    int mc[3][3];

    for (int x=0;x<3;x++)
    for (int y=0;y<3;y++)
    {
        mc[x][y] = ma[x][y]+mb[x][y];
    }

    for (int x=0;x<3;x++)
        printf("%d %d %d\n",mc[x][0],mc[x][1],mc[x][2]);
}