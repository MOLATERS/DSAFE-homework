//
// Created by Slater on 2022/10/30.
//
#include "floyd.h"
void Floyd(int**D,MTgraph G,int **P)//Floyd算法
{
    int i,j,k,m;
    for(i=1;i<=G.n;i++)
        for(j=1;j<=G.n;j++)
        {
            D[i][j]=G.edge[i][j];
            if(D[i][j]!=NONE)
                P[i][j]=i;
            else
                P[i][j]=-1;
        }//初始化所有需要用到的结构
        for(k=4,m=1;m<=G.n;m++,k++)
        {
            if(k>G.n)k=k-G.n;
            if(k<=0)k=k+G.n;
            for (i = 1; i <= G.n; i++) {
                if(k==i)continue;
                for (j = 1; j <= G.n; j++)
                {
                    if(k==j||i==j) continue;
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                        P[i][j] = k;/*当找到更优化的路径时更新距离并更新前驱节点*/
                    }
                }
            }
        }
}
