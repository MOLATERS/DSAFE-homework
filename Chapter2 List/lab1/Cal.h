#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#define maxlength 100
#define NOT 9999.0
#define not '\0'
typedef struct Stack1{//��������ջ
    int top;
    float s[maxlength];
}S1;
typedef struct Stack2{//����������ջ
    int top;
    char s[maxlength];
}S2;
void initial_1(S1* S);//��ʼ������ջ
void initial_2(S2* S);//��ʼ������ջ
float pop_1(S1*S,int flag,FILE* out);//����ջ��������
void push_1(float x,S1*S);//����ջѹ�����
char pop_2(S2*S,int flag,FILE* out);//����ջ��������
void push_2(char x,S2*S);//����ջ��������
int priority(char c);//���÷��ŵ����ȼ�
int ReadFile(char* Operation);//���ļ��ж�ȡ��׺���ʽ
void ShowStack1(S1*Operand,int c);//չʾ����ջ������
void ShowStack2(S2*Operator,int c);//չʾ������ջ������
void Transfer(char* Operation, S1 Operand, S2 Operator,FILE * out);//����׺���ʽת���ɺ�׺���ʽ��������ļ�
float Answer(S1* Operand , S2* Operator,FILE* out);//������
int Instack(S1* Operand,S2* Operator);//��ջ���м���