#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define size 50
typedef int Vertex;                     //定义节点标记类型
typedef int Edge;                       //定义权重类型
typedef struct {                        //邻接矩阵
    Vertex v[size];                     //用于记录顶点
    Edge edge[size][size];              //用于记录权值
    int n,e;                            //表示点的个数以及边的个数
}MTgraph;

typedef struct node{                    //边表节点
    int adj;                            //记录邻接点域的下标
    Edge cost;                          //记录边上的权值
    struct node*next;                   //下一边链表指针
}EdgeNode;

typedef struct {                        //顶点表结点
    Vertex v;                           //顶点数据域
    EdgeNode*firstedge;                 //边链表头指针
}VertexNode;

typedef struct{                         //图的邻接表
    VertexNode vlist[size];             //记录所有的结点
    int n,e;                            //顶点数与边数
}Adjgraph;

typedef struct{                         //建立队列
    int head;                           //队列头
    int tail;                           //队列尾
    int Q[size];                        //队列数组
}queue;

typedef struct{                         //度数表
    int dev[size];                      //度数
    int v[size];                        //结点标号
}DEV;

typedef struct tree{                    //生成树
       struct tree* rchild;
       struct tree* lchild;             //左右子树
       Vertex v;                        //结点
}Tree;

Tree* createNew();//创建新的树节点
void CreatMGraph(MTgraph* G);//邻接矩阵表示，数组表示法
void CreateGraph(Adjgraph*G);//邻接表存储结构建立的算法
void AMTransfer(MTgraph* G1,const Adjgraph G2);//从邻接表转换为邻接矩阵
void MATransfer(Adjgraph* G2,const MTgraph G1);//从邻接矩阵转换为邻接表
void initialG1(MTgraph*G);//将邻接矩阵置为空
void initialG2(Adjgraph*G);//将邻接表置为空
void show(const MTgraph g1);
void DFSTA(Adjgraph G,int i,Tree *T);//邻接表深度优先算法递归单元
void DFSTA_X(Adjgraph G,int i,Tree *T);//循环实现邻接表深度优先算法
void DFSTB(MTgraph G,int i,Tree*T);//邻接矩阵深度优先算法递归单元
void DFSTB_X(MTgraph G,int i,Tree*T);//循环实现邻接矩阵深度优先算法
void BFSTA(const Adjgraph G,int i);//邻接表广度优先算法
void BFSTB(const MTgraph G,int i);//邻接矩阵深度优先算法
void BFSTAmain(const Adjgraph G);//邻接表广度优先算法
void DFSTAmain_X(Adjgraph G,Tree *T);//邻接表深度优先算法(循环)
void BFSTBmain(const MTgraph G);//邻接矩阵广度优先算法
void DFSTBmain_X(MTgraph G,Tree *T);//邻接矩阵深度优先算法(递归)
void DFSTAmain(Adjgraph G,Tree* T);//邻接表深度优先算法
void DFSTBmain(const MTgraph G,Tree*T);//邻接矩阵深度优先算法
void initial(queue* Q);//初始化队列
void inque(int k,queue* Q);//入队列
int ouque(queue*Q);//出队列
void makenull(DEV* dev);//设置度表为空表
void showDev(DEV* dev);//展示度表内的数值
void Dev1(MTgraph G,DEV* dev1);//邻接矩阵的度计算
void Dev2(Adjgraph G,DEV* dev2);//邻接表的度计算
void preorder(Tree* T);
void clean(Adjgraph* G);