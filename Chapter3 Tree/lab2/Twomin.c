#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void AdjustHeap(int*a,int i,int size);
void buildHeap(int*a,int size);
void TwoMin(int *a,int size,int*min1,int*min2);
int main(){
    int a[12];
    int min1;
    int min2;
    srand(time(0));
    for(int i=1;i<=12;i++)
    {
        a[i]=rand()%20;
    }
    TwoMin(a,12,&min1,&min2);
    printf("%d %d\n",min1,min2);
}
void AdjustHeap(int*a,int k,int size)
{
    int i;
    a[0]=a[k];
    for(i=2*k;i<=size;i*=2)
    {
        if(i<=size&&a[i]>a[i+1])
        i++;
        if(a[0]<a[i])break;
        else
        {
            a[k]=a[i];
            k=i;
        }
    }
    a[k]=a[0];
}
void buildHeap(int*a,int size)
{
    for(int i=size/2;i>0;i--)
    {
        AdjustHeap(a,i,size);
    }
    for(int i=1;i<=size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void TwoMin(int *a,int size,int*min1,int*min2){
    buildHeap(a,size);
    *min1=a[1];
    a[1]=a[size];
    size--;
    buildHeap(a,size);
    *min2=a[1];
}