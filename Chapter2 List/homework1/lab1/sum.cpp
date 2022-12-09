#include <stdio.h>


int sum(int a[], int len)
{
    int i, sum = 0;
    for (i = 0; i <= len - 1; i++)
    {
        sum += a[i];
    }
    return sum;
}