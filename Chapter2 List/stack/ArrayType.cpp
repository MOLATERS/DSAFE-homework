#include<iostream>
using namespace std;
#define maxlength 5
#define NOT -2

typedef int type;

struct Stack{
    int top;
    type s[maxlength]={0};
};
class ArrayStack{
    public:
    ArrayStack(type s[maxlength]);
    void MakeNull(Stack &S);
    type Top(Stack &S);
    void Pop(Stack &S);
    void Push(type x, Stack &S);
    bool Empty(Stack &S);
    Stack S;
    private:
};
ArrayStack::ArrayStack(type s[maxlength])
{
    memcpy(S.s,s,maxlength);
}
void ArrayStack:: MakeNull(Stack &S)
{
    S.top=maxlength;
}
type ArrayStack:: Top(Stack &S)
{
    if(Empty(S))
    {
        return NOT;
    }
    else
    {
        return S.s[S.top];
    }
}
void ArrayStack:: Push(type x,Stack &S)
{
    if(S.top==0)
    {
        cout<<"the stack is full!"<<endl;
    }
    else 
    {
        S.top=S.top-1;
        S.s[S.top]=x;
    }
}
void ArrayStack:: Pop(Stack &S)
{
    if(Empty(S))
    {
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<S.s[S.top]<<" ";
        S.top=S.top+1;
    }
}
bool ArrayStack:: Empty(Stack&S)
{
    if(S.top>maxlength-1)
    return true;
    else
    return false;
}
int main ()
{
    type s[maxlength]={NOT};
    ArrayStack stack(s);
    stack.MakeNull(stack.S);
    type temp;
    for (int i=0 ; i<=maxlength-1;i++)
    {
        cin>>temp;
        stack.Push(temp,stack.S);
    }
    for(int i=0 ; i<=maxlength-1;i++)
    {
        stack.Pop(stack.S);
    }
}