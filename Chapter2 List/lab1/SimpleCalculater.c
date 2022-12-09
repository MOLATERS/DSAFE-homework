/*简单计算器*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define maxlength 100
#define NOT 9999
#define not '\0'
typedef struct Stack1{//用作数据栈
    int top;
    int s[maxlength];
}S1;
typedef struct Stack2{//用作操作数栈
    int top;
    char s[maxlength];
}S2;
void initial_1(S1* S)//初始化数据栈
{
    for(int i=0;i<=maxlength-1;i++)
    {
        S->s[i]=NOT;
    }
    S->top=-1;
}
void initial_2(S2* S)//初始化操作栈
{
    for(int i=0;i<=maxlength-1;i++)
    {
        S->s[i]=not;
    }
    S->top=-1;
}
int pop_1(S1*S,int flag,FILE* out)//数据栈弹出操作
{
    int pop=NOT;
    if(S->top==-1)
    {
        return NOT;
    }
    else{
        if(flag==1)
        {
            fprintf(out,"%d ",S->s[S->top]);
        }
        if(flag==2)
        {
            pop = S->s[S->top];
        }
        S->s[S->top]=NOT;
        S->top--;
        return pop;
    }
}
void push_1(int x,S1*S)//数据栈压入操作
{
    if(S->top>maxlength-1)
    {
        return;
    }
    else{
        S->top++;
        S->s[S->top]=x;
    }
}
char pop_2(S2*S,int flag,FILE* out)//操作栈弹出操作
{
    char pop=not;
    if(S->top==-1)
    {
        return not;
    }
    else{
        if(S->s[S->top]!='('&&S->s[S->top]!=')'&&flag==1)
        {
            fprintf(out,"%c ",S->s[S->top]);
        }
        if(flag==2)
        {
            pop=S->s[S->top];
        }
        S->s[S->top]=not;
        S->top--;
        return pop;
    }
}
void push_2(char x,S2*S)//操作栈弹出操作
{
    if(S->top>maxlength-1)
    {
        return;
    }
    else{
        S->top++;
        S->s[S->top]=x;
    }
}
int priority(char c)//设置符号的优先级
{
    int priority;
    if(c == '*' || c == '/') priority = 2;
    if(c == '+' || c == '-') priority = 1;
    if(c == '(') priority = 0;
    return priority;
}
int ReadFile(char* Operation)//从文件中读取中缀表达式
{
    FILE* OPER;
    OPER = fopen("operation.txt","r");
    if(Operation==NULL||OPER==NULL)
    {
        printf("fail!");
        return 0;
    }
    char temp;
    int count=2;
    while(1)
    {
        fscanf(OPER,"%c",&temp);
        printf("%c",temp);
        if(temp=='#')
        {
            Operation[0]='#';
            Operation[1]=' ';
            break;
        }
    }
    while(1)
    {
        fscanf(OPER,"%c",&temp);
        printf("%c",temp);
        if(temp=='#')
        {
            Operation[count]=temp;
            break;
        }
        else{
            if(('0'>temp||temp>'9')&&temp!=' ')
            {
                Operation[count]=temp;
                count++;
                Operation[count]=' ';
            }
            else{
                Operation[count]=temp;
            }
            count++;
        }
    }
    printf("\n");
    return 1;
}
void Transfer(char* Operation, S1 Operand, S2 Operator,FILE * out)//把中缀表达式转换成后缀表达式并输出到文件
{
    char*p=Operation;
    int numb=0;
    int count=0;
    int flag=0;
    fprintf(out,"# ");
    while(1)
    {
        if(*p==' ')
        {
            p++;
            char temp[maxlength]={'\0'};
            while(1)
            {
                if(*p=='0'||*p=='1'||*p=='2'||*p=='3'||*p=='4'||*p=='5'||*p=='6'||*p=='7'||*p=='8'||*p=='9'||*p=='.')
                {
                    temp[count]=*p;
                    count++;
                    p++;
                }
                else
                {
                    sscanf(temp,"%d",&numb);
                    if(numb!=0)
                    {
                        push_1(numb,&Operand);
                        pop_1(&Operand,1,out);
                        count=0;
                        numb=0;
                    }
                    flag=1;
                    break;
                }
            }
        }
        else if(*p!=' '&&*p!='#')
        {
            if(*p=='(')
            {push_2(*p,&Operator);p++;continue;}
            else if(*p==')')
            {
                push_2(*p,&Operator);
                for(int i=0;i<=Operator.top+1;i++)
                {
                    pop_2(&Operator,1,out);
                }
                p++;
                continue;
            }
            else if(priority(*p)<priority(Operator.s[Operator.top]))
            {
                for(int i=0;i<=Operator.top+1;i++)
                {
                    pop_2(&Operator,1,out);
                }
                push_2(*p,&Operator);
                p++;
                continue;
            }
            push_2(*p,&Operator);
        }
        if(*p=='#'&&p!=Operation)
        {       
        for(int i=0;i<=Operator.top+1;i++)
            {
                pop_2(&Operator,1,out);
            }
        break;}
        if(flag==0)
        p++;
        flag=0;
    }
    fprintf(out,"# ");
    fclose(out);
}
int Answer(S1* Operand , S2* Operator,FILE* out)
{
    int num1=NOT;
    int num2=NOT;
    int answer=NOT;
    float temp;
    while(Operator->top>-1)
    {
        num1=pop_1(Operand,2,out);
        num2=pop_1(Operand,2,out);
        char oper;
        oper=pop_2(Operator,2,out);
        switch(oper)
        {
        case '+':
            answer=num1+num2;
            break;
        case '-':
            answer=num2-num1;
            break;
        case '*':
            answer=num1*num2;
            break;
        case '/':
            temp=(float)(num2)/num1;
            answer=(int)(temp);
            break;
        default:
            break;
        }
        push_1(answer,Operand);
    }
    return answer;
}
int Instack(S1* Operand,S2* Operator)
{
    int num;//字符串转化成为的数字
    char t;//作为每一次读入
    int count=0;//用于读取数字字符串
    int flag=1;//用于标记第一次读入数据
    int over=0;//用于标记结束符与开始符
    int answer=0;
    FILE *out=fopen("Out.txt","r");
    char temp[maxlength]={'\0'};//保存字符串
    while(over<2)
    {
        while(flag==1)
        {
            fscanf(out,"%c",&t);
            flag=0;
        }
        if(t=='0'||t=='1'||t=='2'||t=='3'||t=='4'||t=='5'||t=='6'||t=='7'||t=='8'||t=='9')
        {
            while(t!=' ')
            {
                temp[count]=t;
                fscanf(out,"%c",&t);
                count++;
            }
            sscanf(temp,"%d",&num);
            push_1(num,Operand);
            for(;count>=0;count--)
            {
                temp[count]='\0';
            }
            count++;
        }
        else if(t=='+'||t=='-'||t=='*'||t=='/')
        {
            push_2(t,Operator);
            answer=Answer(Operand,Operator,out);
            fscanf(out,"%c",&t);
        }
        else if(t==' ')
        {
            fscanf(out,"%c",&t);
        }
        else if(t=='#')
        {
            over++;
            fscanf(out,"%c",&t);
        }
    }
    printf("The Answer of the Operation is %d",answer);
}
int main()
{
    S1 Operand;
    S2 Operator;
    FILE *out=fopen("Out.txt","w");
    char* Operation=(char*)malloc(sizeof(char)*maxlength);
    initial_1(&Operand);
    initial_2(&Operator);
    if(!ReadFile(Operation)){return 0;}
    Transfer(Operation,Operand,Operator,out);
    Instack(&Operand,&Operator);
    return 0;
}