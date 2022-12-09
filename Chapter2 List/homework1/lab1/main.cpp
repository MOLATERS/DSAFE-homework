//#include "Lab1.h"
#include <stdio.h>

int main()
{
    float f;
    for (;;)
    {
        printf("请输入一个浮点数：\n");
        scanf("%f", &f);
        printf("这个浮点数是：%f\n", f);
        if (f == 0)break;
    }
}
