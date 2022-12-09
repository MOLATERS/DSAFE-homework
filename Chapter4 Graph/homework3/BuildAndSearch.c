#include "graph.h"
int visit[size];
int sub[size];
int count=1;
queue Q;
int main()
{
    MTgraph g1;//邻接矩阵
    Adjgraph g2;//邻接表
    int choice=0;//输入选择
    DEV dev1;//邻接矩阵度表
    DEV dev2;//邻接表度表
    Tree* T1=createNew();//建立六个生成树记录所有遍历的结果
    Tree* T2=createNew();
    Tree* T3=createNew();
    Tree* T4=createNew();
    Tree* T5=createNew();
    Tree* T6=createNew();
    CreatMGraph(&g1);//构建出邻接矩阵
    CreateGraph(&g2);//构建出邻接表  
    while(choice!=-1)
    {
        printf("please enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0://邻接矩阵与邻接表互换
                //show(g1);//展示邻接矩阵
                initialG2(&g2);//清零邻接表
                MATransfer(&g2,g1);//从邻接矩阵转化为邻接表
                initialG1(&g1);//清零邻接矩阵
                AMTransfer(&g1,g2);//将邻接表转化为邻接矩阵
                //show(g1);//展示转换回来的邻接矩阵
                break;
            case 1://邻接表深度优先算法
                DFSTAmain(g2,T1);//递归算法
                clean(&g2);
                DFSTAmain_X(g2,T2);//非递归算法
                clean(&g2);
                preorder(T1->lchild);//生成树遍历
                printf("\n");
                preorder(T2->lchild);
                printf("\n");
                break;
            case 2://邻接矩阵深度优先算法
                //show(g1);
                DFSTBmain(g1,T3);//递归算法
                preorder(T3->lchild);
                printf("\n");
                DFSTBmain_X(g1,T4);//非递归算法
                preorder(T4->lchild);
                printf("\n");
                break;
            case 3://邻接表广度优先算法
                BFSTAmain(g2);//队列算法
                break;
            case 4://邻接矩阵广度优先算法
                BFSTBmain(g1);//队列算法
                break;
            case 5://使用邻接矩阵和邻接表实现计算结点的度
                makenull(&dev2);
                //makenull(&dev1);
                //Dev1(g1,&dev1);
                Dev2(g2,&dev2);
                //showDev(&dev1);
                showDev(&dev2);
                break;
        }
        while(getchar()!='\n');
    }
    return 0;
}
void clean(Adjgraph* G)
{
    for(int i=0;i<G->n;i++)
    sub[i]=0;
        count=0;
}

void preorder(Tree* T)
{
    if(T==NULL)
    {
        return;
    }
    else{
    printf("%d ",T->v);
    preorder(T->lchild);
    preorder(T->rchild);
    }
}
Tree* createNew()//构建新的树节点
{
    Tree* p=NULL;
    if((p=(Tree*)malloc(sizeof(Tree)))!=NULL)
    {
        p->lchild=NULL;
        p->rchild=NULL;
        p->v=-1;
    }
        return p;
    return NULL;
}
void makenull(DEV* dev)//设置度表为空表
{
    for(int i=0;i<size;i++)
    {
        dev->dev[i]=0;
        dev->v[i]=0;
    }
}
void showDev(DEV* dev)//展示度表内的数值
{
    int i=0;
    while(dev->v[i]!=0)
    {
        printf("点的名称为：%d\t度为:%d\n",dev->v[i],dev->dev[i]);
        i++;
    }
    printf("\n");
}
void Dev1(MTgraph G,DEV* dev1)//邻接矩阵的度计算
{
    for(int i=0;i<G.n;i++)
    {
        dev1->v[i]=G.v[i];
        for(int j=0;j<G.n;j++)
        {
            if(G.edge[i][j]!=0)
            (dev1->dev[i])++;
        }

    }
}
void Dev2(Adjgraph G,DEV* dev2)//邻接表的度计算
{
    EdgeNode*p=NULL;
    for(int i=0;i<G.n;i++)
    {
        dev2->v[i]=G.vlist[i].v;
        p=G.vlist[i].firstedge;
        while(p!=NULL)
        {
            dev2->dev[i]++;
            p=p->next;
        }
    }
}
void initial(queue* Q)//初始化队列
{
    Q->head=0;
    Q->tail=0;
    for(int i=0;i<size;i++)
    {
        Q->Q[i]=0;
    }
}
void inque(int k,queue* Q)//入队列
{
    Q->head++;
    if(Q->head==size)return;
    Q->Q[Q->head]=k;
}
int ouque(queue*Q)//出队列
{
    Q->tail++;
    if(Q->tail>Q->head)return -1;
    return Q->Q[Q->tail];
}
void DFSTA_X(Adjgraph G,int i,Tree *T)//循环实现邻接表深度优先算法
{
    int temp=0;int flag=0;int t=i;
    int S[size];//设置一个栈（最大为顶点数）
    for(int i=0;i<size;i++)
    S[i]=-1;
    int top=0;//设置栈顶
    Tree*tp=createNew();
    Tree*ST[size];
    for(int i=0;i<size;i++)
    ST[i]=NULL;
    int Top=0;
    ST[Top]=tp;
    S[top]=i;//将该结点进栈
    visit[i]=1;
    T->v=G.vlist[i].v;
    tp=T;
    EdgeNode*p=NULL;
    int first=0;
    printf("%d ",G.vlist[i].v);
    while(top!=-1)
    {
        temp=-1;
        p=G.vlist[t].firstedge;
        while(p!=NULL)
        {
            if(!visit[p->adj])
            {
                temp=p->adj;
                if(flag==1)
                {
                    top++;
                    S[top]=t;
                    tp->rchild=createNew();
                    tp=tp->rchild;
                    tp->v=G.vlist[temp].v;
                }
                break;
            }
            p=p->next;
        }
        if(temp==-1)
        {
            t=S[top];top--;
            tp=ST[Top];Top--;
            flag=1;
        }
        else{
            printf("%d ",G.vlist[temp].v);
            top++;Top++;
            S[top]=temp;
            visit[temp]=1;
            t=temp;
            ST[Top]=tp;
            if(flag!=1)
            {
                tp->lchild=createNew();
                tp=tp->lchild;
                tp->v=G.vlist[temp].v;
            }
            flag=0;
        }
    }
}
void DFSTA(Adjgraph G,int i,Tree *T)//邻接表深度优先算法递归单元
{
    EdgeNode* p;
    visit[i]=1;//对方访问过的节点进行标记
    sub[i]=count++;//进行编号
    p=G.vlist[i].firstedge;//取一个边表的头指针
    printf("%d ",G.vlist[i].v);//访问该节点
    T->v=G.vlist[i].v;
    Tree* tp=createNew();
    int flag=1;
    while(p!=NULL)
    {
        if(!visit[p->adj])
        {
            if(flag==1)
            {
                T->lchild=tp;
                DFSTA(G,p->adj,tp);
                flag=0;
            }
            else
            {
                tp->rchild=createNew();
                tp=tp->rchild;
                DFSTA(G,p->adj,tp);
            }
        }
        p=p->next;
    }
}
void DFSTB_X(MTgraph G,int i,Tree* T)//循环实现邻接矩阵深度优先算法
{
    int temp=0;int flag=0;
    int S[size];//设置一个栈（最大为顶点数）
    for(int i=0;i<size;i++)
    S[i]=-1;
    int top=0;//设置栈顶
    Tree*tp=createNew();
    Tree*ST[size];
    for(int i=0;i<size;i++)
    ST[i]=NULL;
    int Top=0;
    ST[Top]=tp;
    S[top]=i;//将该结点进栈
    visit[i]=1;
    T->v=G.v[i];
    tp=T;
    int m;
    printf("%d ",G.v[i]);
    while(top!=-1)
    {
        for(m=0;m<G.n;m++)
        {
            if(G.edge[i][m]>0&&visit[m]!=1)
            {
                if(flag==1)
                {
                    top++;
                    S[top]=i;
                    tp->rchild=createNew();
                    tp=tp->rchild;
                    tp->v=G.v[m];
                }
                break;
            }
        }
        if(m==G.n)
        {
            flag=1;
            i=S[top];
            S[top]=-1;
            top--;
            tp=ST[Top];Top--;
        }
        else
        {
                printf("%d ",G.v[m]);
                top++;Top++;
                S[top]=m;
                visit[m]=1;
                i=m;
                ST[Top]=tp;
                if(flag!=1)
                {
                    tp->lchild=createNew();
                    tp=tp->lchild;
                    tp->v=G.v[m];
                }
                flag=0;
        }
    }
}
void DFSTB(MTgraph G,int i,Tree*T)//邻接矩阵深度优先算法递归单元
{
    int j;
    printf("%d ",G.v[i]);
    visit[i]=1;
    sub[i]=count++;
    int flag=1;
    T->v=G.v[i];
    Tree*tp=createNew();
    for(j=0;j<G.n;j++)
    {
        if((G.edge[i][j]>0)&&(!visit[j]))
        {
            if(flag==1)
            {
                T->lchild=tp;
                DFSTB(G,j,tp);
                flag=0;
            }
            else
            {
                tp->rchild=createNew();
                tp=tp->rchild;
                DFSTB(G,j,tp);
            }
        }
    }
}
void DFSTAmain(Adjgraph G,Tree* T)//邻接表深度优先算法
{
    int flag=0;
    Tree* tp=createNew();
    for(int j=0;j<G.n;j++)
    visit[j]=0;
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        {
            if(flag==0)
            {
                T->lchild=tp;
                DFSTA(G,i,tp);
                flag=1;
            }
            else
            {
                tp->rchild=createNew();
                tp=tp->rchild;
                DFSTA(G,i,tp);
            }
        }
    }
    printf("\n");
}
void DFSTAmain_X(Adjgraph G,Tree *T)//邻接表深度优先算法(循环)
{
    int flag=0;
    Tree* tp=createNew();
    for(int j=0;j<G.n;j++)
    visit[j]=0;
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        {
            if(flag==0)
            {
                T->lchild=tp;
                DFSTA_X(G,i,tp);
                flag=1;
            }
            else
            {
                while(tp->rchild!=NULL)tp=tp->rchild;
                tp->rchild=createNew();
                tp=tp->rchild;
                DFSTA_X(G,i,tp);
            }
        }
    }
    printf("\n");
}
void DFSTBmain(MTgraph G,Tree* T)//邻接矩阵深度优先算法
{
    int flag=0;
    Tree*tp=createNew();
    for(int j=0;j<G.n;j++)
    visit[j]=0;
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        {
            if(flag==0)
                {
                    T->lchild=tp;
                    DFSTB(G,i,tp);
                    flag=1;
                }
                else
                {
                    tp->rchild=createNew();
                    tp=tp->rchild;
                    DFSTB(G,i,tp);
                }
        }
    }
    printf("\n");
}
void DFSTBmain_X(MTgraph G,Tree*T)//邻接矩阵深度优先算法(递归)
{
    int flag=0;
    Tree*tp=createNew();
    for(int j=0;j<G.n;j++)
    visit[j]=0;
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        {
            if(flag==0)
                {
                    T->lchild=tp;
                    DFSTB_X(G,i,tp);
                    flag=1;
                }
                else
                {
                    while(tp->rchild!=NULL)tp=tp->rchild;
                    tp->rchild=createNew();
                    tp=tp->rchild;
                    DFSTB_X(G,i,tp);
                }
        }
    }
    printf("\n");
}
void BFSTA(Adjgraph G,int i)//邻接表广度优先算法单元
{
    int j;EdgeNode*p=NULL;
    initial(&Q);
    printf("%d ",G.vlist[i].v);
    visit[i]=1;
    inque(i,&Q);
    while(Q.head!=Q.tail)
    {
        j=ouque(&Q);
        p=G.vlist[j].firstedge;
        while(p!=NULL)
        {
            if(!visit[p->adj])
            {
                printf("%d ",G.vlist[p->adj].v);
                visit[p->adj]=1;
                inque(p->adj,&Q);
            }
            p=p->next;
        }
    }
}
void BFSTB(MTgraph G,int i)//邻接矩阵广度优先算法单元
{
    int j,k;queue Q;initial(&Q);
    printf("%d ",G.v[i]);
    visit[i]=1;
    inque(i,&Q);
    while(Q.head!=Q.tail)
    {
        j=ouque(&Q);
        for(k=0;k<G.n;k++)
        {
            if(G.edge[j][k]>0&&(!visit[k]))
            {
                printf("%d ",G.v[k]);
                visit[k]=1;
                inque(k,&Q);
            }
        }
    }
}
void BFSTAmain(Adjgraph G)//邻接表广度优先算法
{
    for(int i =0; i<G.n;i++)
    {
        visit[i]=0;
    }
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        BFSTA(G,i);//从顶点i出发的第一次搜索
    }
    printf("\n");
}
void BFSTBmain(MTgraph G)//邻接矩阵广度优先算法
{
    for(int i =0; i<G.n;i++)
    {
        visit[i]=0;
    }
    for(int i=0;i<G.n;i++)
    {
        if(!visit[i])
        BFSTB(G,i);//从顶点i出发的第一次搜索
    }
    printf("\n");
}
void show(MTgraph g1)//展示邻接矩阵
{
    for(int i=0;i<g1.n;i++)
    {
    for(int j=0;j<g1.n;j++)
    printf("%2d",g1.edge[i][j]);
    printf("\n");
    }
    printf("\n");
}
void initialG1(MTgraph*G)//将邻接矩阵置为空
{
    int i,j;
    for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edge[i][j]=0;
}
void initialG2(Adjgraph*G)//将邻接表置为空
{
    for(int i=0;i<G->n;i++)
    {
        G->vlist[i].firstedge=NULL;//将边表设置为空表
    }
}
void AMTransfer(MTgraph* G1,const Adjgraph G2)//从邻接表转换为邻接矩阵
{
    int j;
    G1->e=G2.e;//边数传递
    int count=G2.e;//记录边数
    G1->n=G2.n;//结点数传递
    EdgeNode*p=NULL;
    int flag[size][size]={0};
    for(int i=0;i<G2.n;i++)
    {
        p=G2.vlist[i].firstedge;
        while(p!=NULL)
        {
            j=p->adj;
            if(flag[i][j]!=0)  
            {
                p=p->next;
                continue;
            }
            flag[i][j]++;
            flag[j][i]++;
            G1->edge[j][i]=p->cost;
            G1->edge[i][j]=p->cost;
            count--;
            if(count<0) return;
            p=p->next;
        }
    }
}
void MATransfer(Adjgraph* G2,const MTgraph G1)//从邻接矩阵转换为邻接表
{
    G2->e=G1.e;//边数传递
    G2->n=G1.n;//结点数传递
    for(int i=0;i<G1.n;i++)
    for(int j=i;j<G1.n;j++)
    if(G1.edge[i][j]!=0)
    {
        EdgeNode* p=NULL;
        if((p=(EdgeNode *)malloc(sizeof(EdgeNode)))==NULL)
        return;
        p->adj=i;//设置边界点
        p->cost=G1.edge[i][j];
        p->next=G2->vlist[j].firstedge;//链入第tail号链表的前端
        G2->vlist[j].firstedge=p;
        EdgeNode* q=NULL;
        if((q=(EdgeNode *)malloc(sizeof(EdgeNode)))==NULL)
        return;
        q->adj=j;
        q->cost=G1.edge[i][j];
        q->next=G2->vlist[i].firstedge;
        G2->vlist[i].firstedge=q;
    }
}
void CreatMGraph(MTgraph*G)//邻接矩阵表示，数组表示法
{
    //printf("Adjacency matrix representation, array representation, array representation\n");
    int w;//记录权值
    int i,j;
    FILE* fp=fopen("graph.txt","r");//将图中结点信息保存在文件中
    FILE* fq=fopen("data.txt","r");
    //printf("Please enter the number of nodes:");
    fscanf(fq,"%d ",&G->n);//节点数目
    //printf("Please enter the number of edges:");
    fscanf(fq,"%d ",&G->e);//边的数目
    for(i=0;i<G->n;i++)
    {
        fscanf(fp,"%d ",&(G->v[i]));//读入节点名称
    }
    fclose(fp);
    for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edge[i][j]=0;
    for(int k=0;k<G->e;k++)
    {
        //printf("Please enter a node of the edge:");
        fscanf(fq,"%d ",&i);//左顶点的位置信息
        //printf("Please enter another node for the edge:");
        fscanf(fq,"%d ",&j);//右顶点的位置信息
        //printf("Please enter the weights:");
        fscanf(fq,"%d ",&w);
        G->edge[i][j]=w;
        G->edge[j][i]=w;
    }
    fclose(fq);
    printf("Build successfully!\n");
}
void CreateGraph(Adjgraph*G)//邻接表存储结构建立的算法
{
    //printf("Adjacency list storage structure establishment algorithm\n");
    FILE* fp=fopen("graph.txt","r");
    FILE* ft=fopen("data2.txt","r");
    int head,tail,weight;
    //printf("Please enter the number of nodes:");
    fscanf(ft,"%d ",&G->n);//输入顶点个数
    //printf("Please enter the number of edges:");
    fscanf(ft,"%d ",&G->e);//输入边数
    for(int i=0;i<G->n;i++)
    {
        fscanf(fp,"%d ",&(G->vlist[i].v));//输入顶点信息
        G->vlist[i].firstedge=NULL;//将边表设置为空表
    }
    fclose(fp);
    for(int i=0;i<G->e;i++)
    {
        //printf("Please enter a node of the edge:");
        fscanf(ft,"%d ",&head);//输入出边顶点
        //printf("Please enter another node for the edge:");
        fscanf(ft,"%d ",&tail);//输入入边顶点
        //printf("Please enter the weight:");
        fscanf(ft,"%d ",&weight);//输入权重
        EdgeNode* p=NULL;
        if((p=(EdgeNode *)malloc(sizeof(EdgeNode)))==NULL)
        return;
        p->adj=head;//设置边界点
        p->cost=weight;
        p->next=G->vlist[tail].firstedge;//链入第tail号链表的前端
        G->vlist[tail].firstedge=p;
        EdgeNode* q=NULL;
        if((q=(EdgeNode *)malloc(sizeof(EdgeNode)))==NULL)
        return;
        q->adj=tail;
        q->cost=weight;
        q->next=G->vlist[head].firstedge;
        G->vlist[head].firstedge=q;
    }
    fclose(ft);
    printf("Build successfully!\n");
}
