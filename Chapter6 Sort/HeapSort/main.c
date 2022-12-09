#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BuildHeap(int *s,int len);
void HeapAdjust(int* s,int k,int len);
void HeapSort(int*s,int len);
void swap(int*a,int*b);
int main() {
    int size=100;
    srand(time(0));
    int temp[200]={0};
    int s[200]={0};
    int a=0;
    for(int i=1;i<=size;)
    {
        a=rand()%size;
        if(temp[a]==0){
            s[i++]=a;
            temp[a]++;
        }
    }
    for(int i=1;i<=100;i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    HeapSort(s,size);
    return 0;
}
void swap(int*a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void HeapSort(int*s,int len){
    BuildHeap(s,len);
    for(int i=len;i>1;i--)
    {
        printf("%d ",s[1]);
        swap(&s[i],&s[1]);
        HeapAdjust(s,1,i-1);
    }
}
void BuildHeap(int *s,int len)
{
    for(int i=len/2;i>0;i--)
    {
        HeapAdjust(s,i,len);
    }
}
void HeapAdjust(int* s,int k,int len)
{
    s[0]=s[k];
    for(int i=2*k;i<=len;i*=2)
    {
        if(i<len&&s[i]<s[i+1])
            i++;
        if(s[0]>s[i]) break;
        else
        {
            s[k]=s[i];
            k=i;
        }
    }
    s[k]=s[0];
}