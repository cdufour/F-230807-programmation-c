/*C program to count number of 1's in a number */
 
#include <stdio.h>
 
int count1s(unsigned int num)
{
    unsigned char i;
    int count=0;
    unsigned char totalBits = sizeof(num) * 8;
    
    for(i=0;i< totalBits;i++)
    {
        if( num & (1<< i) )
            count++;
    }
 
    return count;
}

int main()
{
    unsigned int data=0xF;
    printf("\nTotal number of 1 in %x (%d) data variable : %d\n", data, data, count1s(data));
 
    return 0;
}