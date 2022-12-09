//
// Created by Slater on 2022/10/30.
//
#include "floyd.h"
void CreatMGraph(MTgraph*G)//邻接矩阵表示，数组表示法
{
    //printf("Adjacency matrix representation, array representation, array representation\n");
    int w;//记录权值
    int i,j;
    FILE* fp=fopen("C:\\Users\\Slater\\Documents\\vscode\\.vscode\\DSAFE\\Chapter4 Graph\\lab3\\Floyd\\graph.txt","r");//将图中结点信息保存在文件中
    FILE* fq=fopen("C:\\Users\\Slater\\Documents\\vscode\\.vscode\\DSAFE\\Chapter4 Graph\\lab3\\Floyd\\data.txt","r");
    //printf("Please enter the number of nodes:");
    fscanf(fq,"%d ",&G->n);//节点数目
    //printf("Please enter the number of edges:");
    fscanf(fq,"%d ",&G->e);//边的数目
    for(i=0;i<G->n;i++)
    {
        fscanf(fp,"%d ",&(G->v[i]));//读入节点名称
    }
    fclose(fp);
    for(i=1;i<=G->n;i++)
        for(j=1;j<=G->n;j++)
            G->edge[i][j]=NONE;
    for(int k=1;k<=G->e;k++)
    {
        //printf("Please enter a node of the edge:");
        fscanf(fq,"%d ",&i);//左顶点的位置信息
        //printf("Please enter another node for the edge:");
        fscanf(fq,"%d ",&j);//右顶点的位置信息
        //printf("Please enter the weights:");
        fscanf(fq,"%d ",&w);//记录权值
        G->edge[i][j]=w;
//        G->edge[j][i]=w;
    }
    fclose(fq);
//    printf("Build successfully!\n");
}
void show(MTgraph g1)//展示邻接矩阵
{
    for(int i=1;i<=g1.n;i++)
    {
        for(int j=1;j<=g1.n;j++)
            if(g1.edge[i][j]==NONE)
                printf("%3c",'#');
        else
            printf("%3d",g1.edge[i][j]);
        printf("\n");
    }
    printf("\n");
}