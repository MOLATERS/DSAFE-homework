//
// Created by Slater on 2022/10/31.
//
#include "Dijk.h"
void ShowPath(int*P,MTgraph G,int*D,int head)
{
    int temp=2;
    int count=1;
    int p[size][size];
    int i,j;
    int length[size]={0};
    while(count<=G.n) {
        temp = count;
        while (temp != -1) {
            p[count][length[count]] = temp;
            temp = P[temp];
            length[count]++;
        }
        p[count][length[count]] = head;
        count++;
        if(count==head)count++;
    }
    for(i=1;i<=G.n;i++)
    {
        if(i==head)continue;
        if(D[i]==NONE)
        {
            //printf("There is no path");
            continue;
        }
        for(j=length[i]-1;j>0;j--)
        {
            printf("%d->",p[i][j]);
        }
        printf("%d\n",p[i][j]);
        printf("The length is %d\n",D[i]);
    }
}
void ShowPath_X(int*P,MTgraph G,int*D,int head,int tail)
{
    int temp=1;
    int count=1;
    int p[size][size];
    int i,j;
    int length[size]={0};
    while(count<=G.n) {
        temp = count;
        while (temp != -1) {
            p[count][length[count]] = temp;
            temp = P[temp];
            length[count]++;
        }
        p[count][length[count]] = head;
        count++;
        if(count==head)count++;
    }
    if(D[tail]==NONE)
    {
        //printf("There is no path");
        return;
    }
    else
    {
        for(j=length[tail]-1;j>0;j--)
        {
            printf("%d->",p[tail][j]);
        }
        printf("%d\t",p[tail][j]);
        printf("\nThe length is %d\n",D[tail]);
    }
}
void ShowNode(int**P,int**D,MTgraph G,int nod1,int nod2)
{
    ShowPath_X(P[nod1],G,D[nod1],nod1,nod2);
    ShowPath_X(P[nod2],G,D[nod2],nod1,nod2);
}
void showP(int**P,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(P[i][j]!=NONE)
                printf("%3d",P[i][j]);
            else
                printf("%3c",'#');
        }
        printf("\n");
    }
    printf("\n");
}