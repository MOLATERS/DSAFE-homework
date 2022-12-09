#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#define maxlength 100
#define NOT 9999.0
#define not '\0'
typedef struct Stack1{//用作数据栈
    int top;
    float s[maxlength];
}S1;
typedef struct Stack2{//用作操作数栈
    int top;
    char s[maxlength];
}S2;
void initial_1(S1* S);//初始化数据栈
void initial_2(S2* S);//初始化操作栈
float pop_1(S1*S,int flag,FILE* out);//数据栈弹出操作
void push_1(float x,S1*S);//数据栈压入操作
char pop_2(S2*S,int flag,FILE* out);//操作栈弹出操作
void push_2(char x,S2*S);//操作栈弹出操作
int priority(char c);//设置符号的优先级
int ReadFile(char* Operation);//从文件中读取中缀表达式
void ShowStack1(S1*Operand,int c);//展示数据栈的内容
void ShowStack2(S2*Operator,int c);//展示操作数栈的内容
void Transfer(char* Operation, S1 Operand, S2 Operator,FILE * out);//把中缀表达式转换成后缀表达式并输出到文件
float Answer(S1* Operand , S2* Operator,FILE* out);//计算结果
int Instack(S1* Operand,S2* Operator);//用栈进行计算