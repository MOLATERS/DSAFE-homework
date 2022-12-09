#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int swap(int* A,int* B);
int Partition ( int i , int j , int pivot,int a[MAX]);
int FindPivot( int  i, int  j,int a[MAX]);
int Separate(int a[MAX],int n);
int show(int a[MAX],int n);

int main() {
    srand(time(0));
    int flag[MAX]={0};
    int count=0;
    int a[MAX]={0};
    while(count<60)
        {
            a[count]=rand()%100;
            if(flag[a[count]]!=1)
            {
                flag[a[count]]=1;
                count++;
            }
        }
    printf("进行分组之前：");
    show(a,count);
    Separate(a,count);
    printf("进行分组之后：");
    show(a,count);
    return 0;
}

int show(int a[MAX],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        if(i==n/2-1)
            printf("%d || ",a[i]);
        else
        printf("%d ",a[i]);
    }
    printf("\n");
}

int  FindPivot( int  i, int  j,int a[MAX])        /* 设A是外部数组 */
{
    int firstkey = a[i] ; /* 第1个关键字的值A[i].key */
    int  k;                                       /* 从左到右查找不同的关键字 */
    for ( k=i+1 ;  k<=j; k++ )         /* 扫描不同的关键字 */
        if ( a[k] > firstkey )   /* 选择较大的关键字 */
            return  k ;
        else if ( a[k] < firstkey )
            return  i ;
    return  0 ;
}

int Partition ( int i , int j , int pivot,int a[MAX])
{
    int l = i, r = j ;
    do{
        while ( a[r]>=pivot )  r--;
        while ( a[l]< pivot  )  l++;
        if( l < r ) swap(&a[l],&a[r]);
    } while( l <= r );
    return l ;
}

int swap(int* A,int* B)
{
    int temp=*A;
    *A=*B;
    *B=temp;
}

int Separate(int a[MAX],int n)
{
    int pivot;
    int k;
    int pivotindex;
    pivotindex= FindPivot(0,n-1,a);
    k= Partition(0,n-1,pivot,a);
    while(k!=n/2)
    {
        if(k<n/2)
        {
            pivotindex= FindPivot(k,n-1,a);
            pivot=a[pivotindex];
            k= Partition(k,n-1,pivot,a);
        }
        else if(k>n/2)
        {
            pivotindex= FindPivot(0,k-1,a);
            pivot=a[pivotindex];
            k= Partition(0,k-1,pivot,a);
        }
    }

}

