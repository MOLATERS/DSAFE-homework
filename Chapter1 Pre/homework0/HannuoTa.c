#include <stdio.h>
void move(int i,char a,char b)
{
    printf("Move floor %d from %c to %c\n",i,a,b);
}
void HannuoTa(int n,char a,char b,char c)
{
    if(n==1)
    move(1,a,c);
    else{
        HannuoTa(n-1,a,c,b);
        move(n,a,c);
        HannuoTa(n-1,b,a,c);
    }
}
int main ()
{
    int n;
    scanf("%d",&n);
    HannuoTa(n,'A','B','C');
    return 0;
}