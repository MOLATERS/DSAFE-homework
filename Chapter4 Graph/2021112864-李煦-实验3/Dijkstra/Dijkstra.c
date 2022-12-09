//
// Created by Slater on 2022/10/30.
//
#include"Dijk.h"
void Dijkstra(MTgraph C,int *D,int *P,int *S)//Dijkstra算法的实现
{
    int i,w;
    int sum=0;
    for(i=1;i<=C.n;i++)
    {
        D[i]=C.edge[1][i];//记录邻接矩阵
        S[i]=0;
        P[i]=1;
    }
    S[1]=1;
    for(i=1;i<C.n;i++)
    {
        w=MinCost(D,S,C.n);
        S[w]=1;
        for(int v=2;v<=C.n;v++)
        {
            if(!S[v])
            {
                sum=D[w]+C.edge[w][v];
                if(sum<D[v]){
                    D[v]=sum;
                    P[v]=w;
                }
            }
        }
    }
}

void Dijkstra_X(MTgraph C,int **D,int **P,int **S)
{
    Vertex node=1;
    while(node<=C.n)
    {
        int i,w;
        int sum=0;
        for(i=1;i<=C.n;i++)
        {
            D[node][i]=C.edge[node][i];
            S[node][i]=0;
            if(D[node][i]!=NONE)
                P[node][i]=node;
            else
                P[node][i]=-1;
        }
        S[node][node]=1;
        for(i=1;i<C.n;i++)
        {
            w=MinCost_X(D,S,C.n,node);
            if(w<=C.n)
            {
                S[node][w]=1;
                for(int v=1;v<=C.n;v++)
                {
                    if(v==node)
                        continue;
                    if(!S[node][v])
                    {
                        sum=D[node][w]+C.edge[w][v];
                        if(sum<D[node][v]){
                            D[node][v]=sum;
                            P[node][v]=w;
                        }
                    }
                }
            }

        }
        node++;
    }
}

int MinCost(int *D,int *S,int n)//找到最小的路径长度对应的顶点
{
    int temp=NONE;
    int i;
    int w=2;
    for(i=2;i<=n;i++)
    {
        if(!S[i]&&D[i]<temp)
        {
            temp=D[i];
            w=i;
        }
    }
    return w;
}

int MinCost_X(int **D,int **S,int n,Vertex node)//找到最小的路径长度对应的顶点
{
    int temp=NONE;
    int i;
    int w=node+1;
    for(i=1;i<=n;i++)
    {
        if(!S[node][i]&&D[node][i]<temp)
        {
            temp=D[node][i];
            w=i;
        }
    }
    return w;
}
