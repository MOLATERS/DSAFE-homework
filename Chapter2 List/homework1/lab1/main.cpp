//#include "Lab1.h"
#include <stdio.h>

int main()
{
    float f;
    for (;;)
    {
        printf("������һ����������\n");
        scanf("%f", &f);
        printf("����������ǣ�%f\n", f);
        if (f == 0)break;
    }
}
