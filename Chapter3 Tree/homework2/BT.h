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

BT* Node(type x, BT* L,BT* R);//�����ڵ�
void push(BT* T,ST* S);//ѹ��ջ�е�Ԫ��
BT* pop(ST* S);//����ջ�ڲ���Ԫ��
type visit(BT* T);//������������ֵ
int IsEmpty(BT* T);//�ж�������Ƿ�Ϊ��
BT* createBT(FILE* fp);//�����ļ�tree.txt����������
void PreOrder(BT* T);//�ݹ�ķ�ʽ����������������
void MidOrder(BT* T);//�ݹ�ķ�ʽ����������������
void AftOrder(BT* T);//�ݹ�ķ�ʽ��ɺ������������
void PreOrder_X(BT*T);//ѭ���ķ�ʽ����������������
void MidOrder_X(BT*T);//ѭ���ķ�ʽ����������������
void AftOrder_X(BT*T);//ѭ���ķ�ʽ��ɺ������������
void LeverOder(BT*T);//�������������
int Hight(BT*T);//����������ĸ߶�
int Dev(BT*T);//����ÿ����Ķ�
int Judge(BT*T);//�ж��Ƿ�Ϊ������
void Width(BT*T,int leve);//�ݹ����������Ŀ��
int Width_X(BT*T);//ѭ������������Ŀ��
int FindMax(int*leve,int hight);//Ѱ�����������ݵ����ֵ