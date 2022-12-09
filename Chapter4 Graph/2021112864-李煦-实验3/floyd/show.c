//
// Created by Slater on 2022/10/31.
//
#include "floyd.h"
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
void ShowPath(int**P,int**D,MTgraph G,Vertex head,Vertex tail,int flag)
{
    int temp;
    int path[size]={0};
    int length=0;
    int i;
    int *p=(int*)malloc(sizeof(int)*(G.n+1));
    for(i=1;i<=G.n;i++)
    {
        p[i]=P[head][i];
    }
    temp=p[tail];
    if (temp==-1)
    {
        //printf("There is no path between %d->%d\n",head,tail);
        return ;
    }
    while(temp!=head)
    {
        path[length]=temp;
        temp=p[temp];
        length++;
    }
    if(flag==1)
    printf("%d->",head);
    for(i=length-1;i>=0;i--)
    {
        printf("%d->",path[i]);
    }
    if(G.edge[path[0]][tail]!=NONE)
    {
        printf("%d\t",tail);
    }
    else
    {
        ShowPath(P,D,G,path[0],tail,0);
    }
}
void ShowNodes(int**P,int**D,MTgraph G,int nod1,int nod2)
{
    ShowPath(P,D,G,nod1,nod2,1);
    if(D[nod1][nod2]!=NONE)
        printf("\nThe length is %d\n",D[nod1][nod2]);
    ShowPath(P,D,G,nod2,nod1,1);
    if(D[nod2][nod1]!=NONE)
        printf("\nThe length is %d\n",D[nod2][nod1]);
}
