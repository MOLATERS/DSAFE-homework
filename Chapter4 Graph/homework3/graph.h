#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define size 50
typedef int Vertex;                     //����ڵ�������
typedef int Edge;                       //����Ȩ������
typedef struct {                        //�ڽӾ���
    Vertex v[size];                     //���ڼ�¼����
    Edge edge[size][size];              //���ڼ�¼Ȩֵ
    int n,e;                            //��ʾ��ĸ����Լ��ߵĸ���
}MTgraph;

typedef struct node{                    //�߱�ڵ�
    int adj;                            //��¼�ڽӵ�����±�
    Edge cost;                          //��¼���ϵ�Ȩֵ
    struct node*next;                   //��һ������ָ��
}EdgeNode;

typedef struct {                        //�������
    Vertex v;                           //����������
    EdgeNode*firstedge;                 //������ͷָ��
}VertexNode;

typedef struct{                         //ͼ���ڽӱ�
    VertexNode vlist[size];             //��¼���еĽ��
    int n,e;                            //�����������
}Adjgraph;

typedef struct{                         //��������
    int head;                           //����ͷ
    int tail;                           //����β
    int Q[size];                        //��������
}queue;

typedef struct{                         //������
    int dev[size];                      //����
    int v[size];                        //�����
}DEV;

typedef struct tree{                    //������
       struct tree* rchild;
       struct tree* lchild;             //��������
       Vertex v;                        //���
}Tree;

Tree* createNew();//�����µ����ڵ�
void CreatMGraph(MTgraph* G);//�ڽӾ����ʾ�������ʾ��
void CreateGraph(Adjgraph*G);//�ڽӱ�洢�ṹ�������㷨
void AMTransfer(MTgraph* G1,const Adjgraph G2);//���ڽӱ�ת��Ϊ�ڽӾ���
void MATransfer(Adjgraph* G2,const MTgraph G1);//���ڽӾ���ת��Ϊ�ڽӱ�
void initialG1(MTgraph*G);//���ڽӾ�����Ϊ��
void initialG2(Adjgraph*G);//���ڽӱ���Ϊ��
void show(const MTgraph g1);
void DFSTA(Adjgraph G,int i,Tree *T);//�ڽӱ���������㷨�ݹ鵥Ԫ
void DFSTA_X(Adjgraph G,int i,Tree *T);//ѭ��ʵ���ڽӱ���������㷨
void DFSTB(MTgraph G,int i,Tree*T);//�ڽӾ�����������㷨�ݹ鵥Ԫ
void DFSTB_X(MTgraph G,int i,Tree*T);//ѭ��ʵ���ڽӾ�����������㷨
void BFSTA(const Adjgraph G,int i);//�ڽӱ��������㷨
void BFSTB(const MTgraph G,int i);//�ڽӾ�����������㷨
void BFSTAmain(const Adjgraph G);//�ڽӱ��������㷨
void DFSTAmain_X(Adjgraph G,Tree *T);//�ڽӱ���������㷨(ѭ��)
void BFSTBmain(const MTgraph G);//�ڽӾ����������㷨
void DFSTBmain_X(MTgraph G,Tree *T);//�ڽӾ�����������㷨(�ݹ�)
void DFSTAmain(Adjgraph G,Tree* T);//�ڽӱ���������㷨
void DFSTBmain(const MTgraph G,Tree*T);//�ڽӾ�����������㷨
void initial(queue* Q);//��ʼ������
void inque(int k,queue* Q);//�����
int ouque(queue*Q);//������
void makenull(DEV* dev);//���öȱ�Ϊ�ձ�
void showDev(DEV* dev);//չʾ�ȱ��ڵ���ֵ
void Dev1(MTgraph G,DEV* dev1);//�ڽӾ���Ķȼ���
void Dev2(Adjgraph G,DEV* dev2);//�ڽӱ�Ķȼ���
void preorder(Tree* T);
void clean(Adjgraph* G);