#include<iostream>
using namespace std;
#define maxlength 5
#define NOT -2
///////////////////////////////////////////
/*                调试日志                */
/*当前出现死循环问题等待修改 2022.9.28 10：09*/
//////////////////////////////////////////
typedef int type;

struct list{
    type data=-1;
    int order=1;
    struct list* next=NULL;
}L;

struct Stack{
    list*head = new list;
};

class LinkStack{
public:
    LinkStack(list* input);
    list* Length(Stack &S);
    void MakeNull(Stack &S);
    type Top(Stack &S);
    void Pop(Stack &S);
    void Push(type x, Stack &S);
    bool Empty(Stack &S);
    Stack S;
};

LinkStack::LinkStack(list* input)
{
    memcpy(S.head,input->next,sizeof(list*));
}
void LinkStack::MakeNull(Stack &S)
{
    S.head->next=NULL;
    S.head->data=NOT;
}
bool LinkStack:: Empty(Stack&S)
{
    if(S.head->data==NOT)
    return true;
    else
    return false;
}
type LinkStack:: Top(Stack &S)
{
    if(Empty(S))
    {
        return NOT;
    }
    else
    {
        return S.head->data;
    }
}
void LinkStack:: Push(type x,Stack &S)
{
    list* end;
    list*p=S.head;
    end = Length(S);
    if(end->order==maxlength)
    {
        cout<<"the stack is full!"<<endl;
    }
    else 
    {
        end->next=new list;
        end->next->data=end->data+1;
        while(p->next)
            {
                p->next->data=p->data;
                p=p->next;
            }
        S.head->data=x;
    }
}
list* LinkStack::Length(Stack &S)
{
    list*p=S.head;
    while(p->next)
    {
        p=p->next;
    }
    return p;
}
void LinkStack:: Pop(Stack &S)
{
    list*p=S.head;
    if(Empty(S))
    {
        cout<<"the stack is empty"<<endl;
    }
    else{
        if(S.head->next!=NULL)
        {
            cout<<S.head->data<<" ";
            while(p->next)
            {
                p->data=p->next->data;
                p=p->next;
            }
            delete p;
        }
        else
        {
            cout<<S.head->data<<" ";
            S.head->data=NOT;
        }
    }
}
int main()
{
    list* input=new list;
    list*p=input;
    type temp;
    for(int i=0;i<=maxlength-1;i++)
    {
        p->next=new list;
        p->next->order=p->order+1;
        cin>>p->next->data;
        p=p->next;
    }
    LinkStack stack(input);
    for (int i=0 ; i<=maxlength-1;i++)
    {
        cin>>temp;
        stack.Push(temp,stack.S);
    }
    for (int i=0 ; i<=maxlength-1;i++)
    {
        stack.Pop(stack.S);
    }
}

