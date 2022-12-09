#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define NOT -1
#define maxlength 100
typedef int type;

typedef struct BinaryTree{
    type data;
    int leve;
    struct BinaryTree* Lchild;
    struct BinaryTree* Rchild;
}BT;
typedef struct Stack{
    int top;
    BT* s[maxlength];
}ST;

BT* Node(type x, BT* L,BT* R);//创建节点
void push(BT* T,ST* S);//压入栈中的元素
BT* pop(ST* S);//弹出栈内部的元素
type visit(BT* T);//访问树结点的数值
int IsEmpty(BT* T);//判断树结点是否为空
BT* createBT(FILE* fp);//根据文件tree.txt创建二叉树
void PreOrder(BT* T);//递归的方式完成先序遍历二叉树
void MidOrder(BT* T);//递归的方式完成中序遍历二叉树
void AftOrder(BT* T);//递归的方式完成后序遍历二叉树
void PreOrder_X(BT*T);//循环的方式完成先序遍历二叉树
void MidOrder_X(BT*T);//循环的方式完成中序遍历二叉树
void AftOrder_X(BT*T);//循环的方式完成后序遍历二叉树
void LeverOder(BT*T);//层序遍历二叉树
int Hight(BT*T);//计算二叉树的高度
int Dev(BT*T);//计算每个点的度
int Judge(BT*T);//判断是否为二叉树
void Width(BT*T,int leve);//递归计算二叉树的宽度
int Width_X(BT*T);//循环计算二叉树的宽度
int FindMax(int*leve,int hight);//寻找数组中数据的最大值