//
// Created by Slater on 2022/10/30.
//
#ifndef UNTITLED_DIJK_H
#define UNTITLED_DIJK_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define size 50
#define NONE 9999
typedef int Vertex;                     //定义节点标记类型
typedef int Edge;                       //定义权重类型
typedef struct {                        //邻接矩阵
    Vertex v[size];                     //用于记录顶点
    Edge edge[size][size];              //用于记录权值
    int n,e;                            //表示点的个数以及边的个数
}MTgraph;
void CreatMGraph(MTgraph *G);//邻接矩阵表示，数组表示法
void show(MTgraph g1);//展示邻接矩阵
int MinCost(int *D,int *S,int n);//找到最小的路径长度对应的顶点
void Dijkstra(MTgraph C,int *D,int *P,int *S);//Dijkstra算法的实现
void Dijkstra_X(MTgraph C,int **D,int **P,int **S);
int MinCost_X(int **D,int **S,int n,Vertex node);//找到最小的路径长度对应的顶点
void ShowPath(int*P,MTgraph G,int*D,int head);
void ShowPath_X(int*P,MTgraph G,int*D,int head,int tail);
void ShowNode(int**P,int**D,MTgraph G,int nod1,int nod2);
void showP(int**P,int n);
#endif //UNTITLED_DIJK_H
