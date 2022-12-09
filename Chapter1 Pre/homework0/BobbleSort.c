#include <stdio.h>
void print(int*a,int n);
void BobbleSort(int a[],int n);
void Bobblesort_x(int a[],int i,int j,int n);
void swap(int *a,int *b);
int main ()
{
    int a[10]={3,4,5,6,10,99,54,23,12,32};
    //BobbleSort(a,10);
    Bobblesort_x(a  ,0,0,10);
    print(a,10);
}
void print(int*a,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void BobbleSort(int a[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(a[j]>=a[j+1])
            swap(&a[j],&a[j+1]);
        }
    }
    return;
}
void Bobblesort_x(int a[],int i,int j,int n)
{
    if(i>=9) return;
    if(j>=n-i-1){i++;j=0;}
    if(a[j]>=a[j+1]){swap(&a[j],&a[j+1]);}
    return Bobblesort_x(a,i,j+1,n);
}
void swap(int *a,int *b)
{
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}