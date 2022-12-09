#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;
bool visitedM[100];
bool visitedL[100];
bool visitedBM[100];
bool visitedBL[100];
int dfnM[100];
int dfnL[100];
int bfnM[100];
int bfnL[100];
int countnum1;
int countnum2;
int countBM;
int countBL;
typedef struct Tree
{
    char info;
    struct Tree* lchild;
    struct Tree* rchild;
    Tree():lchild(NULL),rchild(NULL) {}
}Tree;
typedef struct GM
{
    int n;
    int e;
    char vexlist[100];
    int edge[100][100];
}GM;
typedef struct GNode
{
    int adjvex;
    int weigh;
    struct GNode* next;
}GNode;
typedef struct GList
{
    char vertex;
    GNode* firstnode;
}GList;
typedef struct GL
{
    int n;
    int e;
    GList vexlist[100];
}GL;
void createGraph1(GM* G)
{
    int i, j, k, w;
    cout << "请输入顶点数和边数" << endl;
    cin >> G->n >> G->e;
    cout << "请输入顶点信息" << endl;
    getchar();
    for (i = 0;i < G->n;i++)
    {
        G->vexlist[i] = getchar();
        getchar();
    }
    for (i = 0;i < G->n;i++)
    {
        for (j = 0;j < G->n;j++)
        {
            G->edge[i][j] = 0;
        }
    }
    cout << "请输入边" << endl;
    for (k = 0; k < G->e;k++)
    {
        cin >> i >> j >> w;
        G->edge[i][j] = w;
        //G->edge[j][i] = w;
    }
}
void createGraph2(GL* G)
{
    cout << "请输入顶点数和边数" << endl;
    cin >> G->n >> G->e;
    getchar();
    cout << "请输入顶点信息" << endl;
    for (int i = 0;i < G->n;i++)
    {
        G->vexlist[i].vertex = getchar();
        getchar();
        G->vexlist[i].firstnode = NULL;
    }
    int i, j, w;
    cout << "请输入边" << endl;
    for (int k = 0;k < G->e;k++)
    {
        cin >> i >> j >> w;
        GNode* p = new GNode;
        p->adjvex = j;
        p->weigh = w;
        p->next = G->vexlist[i].firstnode;
        G->vexlist[i].firstnode = p;
        /*GNode* q = new GNode;
        q->adjvex = i;
        q->weigh = w;
        q->next = G->vexlist[j].firstnode;
        G->vexlist[i].firstnode = q;*/

    }
}
void GL2GM(GL* G1, GM* G2)
{
    G2->n = G1->n;
    G2->e = G1->e;
    int i, j;
    for (int k = 0;k < G2->n;k++)
    {
        G2->vexlist[k] = G1->vexlist[k].vertex;
    }
    for (i = 0;i < G2->n;i++)
    {
        for (j = 0;j < G2->n;j++)
        {
            G2->edge[i][j] = 0;
        }
    }
    GNode* p;
    for (int k = 0;k < G2->n;k++)
    {
        p = G1->vexlist[k].firstnode;
        while (p)
        {
            G2->edge[k][p->adjvex] = p->weigh;
            p = p->next;
        }
    }
}
void GM2GL(GM* G1, GL* G2)
{
    G2->n = G2->n;
    G2->e = G1->e;
    GNode* p;
    p = new GNode;
    for (int i = 0;i < G1->n;i++)
    {
        G2->vexlist[i].vertex = G1->vexlist[i];
        G2->vexlist[i].firstnode = NULL;
    }
    for (int i = 0;i < G1->n;i++)
    {
        for (int j = 0;j < G1->n;j++)
        {
            if (G1->edge[i][j])
            {
                p->adjvex = j;
                p->weigh = G1->edge[i][j];
                p->next = G2->vexlist[i].firstnode;
                G2->vexlist[i].firstnode = p;
            }
        }
    }
}
void DpsM(int m, GM* G, Tree* T)
{
    cout << G->vexlist[m] << endl;
    visitedM[m] = true;
    dfnM[m] = countnum1;
    T->info = G->vexlist[m];
    countnum1++;
    Tree* tp = new Tree;
    bool fir = true;
    for (int j = 0;j < G->n;j++)
    {
        if (G->edge[m][j]&&visitedM[j]==false)
        {
            if (fir == true)
            {
                T->lchild = tp;
                DpsM(j, G, tp);
                fir = false;
            }
            else
            {
                tp->rchild = new Tree;
                tp = tp->rchild;
                DpsM(j, G, tp);
            }
        }
    }
}
void DpsTraverseM(GM* G, Tree* T)
{
    countnum1 = 1;
    for (int i = 0;i < G->n;i++)
    {
        visitedM[i] = false;
    }
    bool fir = true;
    Tree* tp = new Tree;
    for (int i = 0;i < G->n;i++)
    {
        if (visitedM[i] == false)
        {
            if (fir = true)
            {
                T->lchild = tp;
                DpsM(i, G, tp);
                fir = false;
            }
            else
            {
                tp->rchild = new Tree;
                tp = tp->rchild;
                DpsM(i, G, tp);
            }
        }
    }
}
void DpsL(int i, GL* G, Tree* T)
{
    cout << G->vexlist[i].vertex << endl;
    visitedL[i] = true;
    dfnL[i] = countnum2++;
    T->info = G->vexlist[i].vertex;
    Tree* tp = new Tree;
    GNode* p = new GNode;
    p = G->vexlist[i].firstnode;
    bool fir = true;
    while (p)
    {
        if (visitedL[p->adjvex] == false)
        {
            if (fir == true)
            {
                T->lchild = tp;
                DpsL(p->adjvex, G, tp);
                fir = false;
            }
            else
            {
                tp->rchild = new Tree;
                tp = tp->rchild;
                DpsL(p->adjvex, G, tp);
            }
        }
        p = p->next;
    }
}
void DpsTraverseL(GL* G, Tree* T)
{
    countnum2 = 1;
    for (int i = 0;i < G->n;i++)
    {
        visitedL[i] = false;
    }
    Tree* p = new Tree;
    bool fir = true;
    for (int i = 0;i < G->n;i++)
    {
        if (visitedL[i] == false)
        {
            if (fir == true)
            {
                T->lchild = p;
                DpsL(i, G, p);
                fir = false;
            }
            else
            {
                p->rchild = new Tree;
                p = p->rchild;
                DpsL(i, G, p);
            }
        }
    }
}
void postorder(Tree* T)
{
    if (T)
    {
        printf("%c\t", T->info);
        postorder(T->lchild);
        postorder(T->rchild);
    }
}
void inorder(Tree* T)
{
    if (T)
    {
        inorder(T->lchild);
        printf("%c\t", T->info);
        inorder(T->rchild);
    }
}
void BfsM(int i, GM* G, Tree* T)
{
    unordered_map<int, Tree*> map;
    cout << G->vexlist[i] << endl;
    bfnM[i] = countBM++;
    visitedBM[i] = true;
    queue<int> Q;
    Q.push(i);
    T->info = G->vexlist[i];
    map.insert({ i,T });
    Tree* tp;
    tp = T;
    bool fir = true;
    while (!Q.empty())
    {
        i = Q.front();
        Q.pop();
        tp = map.at(i);
        fir = true;
        for (int j = 0;j < G->n;j++)
        {
            if (G->edge[i][j] && !visitedBM[j])
            {
                cout << G->vexlist[j] << endl;
                bfnM[j] = countBM++;
                visitedBM[j] = true;
                Q.push(j);
                if (fir == true)
                {
                    tp->lchild = new Tree;
                    tp = tp->lchild;
                    tp->info = G->vexlist[j];
                    map.insert({ j,tp });
                    fir = false;
                }
                else
                {
                    tp->rchild = new Tree;
                    tp = tp->rchild;
                    tp->info = G->vexlist[j];
                    map.insert({ j,tp });
                }
            }
        }
    }
}
void BfsTraverseM(GM* G, Tree* T)
{
    countBM = 1;
    Tree* tp = new Tree;
    for (int i = 0;i < G->n;i++)
    {
        visitedBM[i] = false;
    }
    bool fir = true;
    for (int i = 0;i < G->n;i++)
    {
        if (visitedBM[i] == false)
        {
            if (fir == true)
            {
                T->lchild = tp;
                BfsM(i, G, tp);
                fir = false;
            }
            else
            {
                tp->rchild = new Tree;
                tp = tp->rchild;
                BfsM(i, G, tp);
            }
        }
    }
}
void BfsL(int i, GL* G, Tree* T)
{
    cout << G->vexlist[i].vertex << endl;
    visitedBL[i] = true;
    bfnL[i] = countBL++;
    unordered_map<int, Tree*>map;
    T->info = G->vexlist[i].vertex;
    map.insert({ i,T });
    queue<int> Q;
    Q.push(i);
    Tree* tp;
    bool fir = true;
    while (!Q.empty())
    {
        i = Q.front();
        Q.pop();
        tp = map.at(i);
        fir = true;
        GNode* p = G->vexlist[i].firstnode;
        while (p)
        {
            if (visitedBL[p->adjvex] == false)
            {
                cout << G->vexlist[p->adjvex].vertex << endl;
                visitedBL[p->adjvex] = true;
                bfnL[p->adjvex] = countBL++;
                Q.push(p->adjvex);
                if (fir == true)
                {
                    tp->lchild = new Tree;
                    tp = tp->lchild;
                    tp->info = G->vexlist[p->adjvex].vertex;
                    map.insert({ p->adjvex,tp });
                    fir = false;
                }
                else
                {
                    tp->rchild = new Tree;
                    tp = tp->rchild;
                    tp->info = G->vexlist[p->adjvex].vertex;
                    map.insert({ p->adjvex,tp });
                }
            }
            p = p->next;
        }
    }
}
void BfsTraverseL(GL* G, Tree* T)
{
    countBL = 1;
    bool fir = true;
    Tree* tp = new Tree;
    for (int i = 0;i < G->n;i++)
    {
        visitedBL[i] = false;
    }
    for (int i = 0;i < G->n;i++)
    {
        if (visitedBL[i] == false)
        {
            if (fir == true)
            {
                T->lchild = tp;
                BfsL(i, G, tp);
                fir = false;
            }
            else
            {
                tp->rchild = new Tree;
                tp = tp->rchild;
                BfsL(i, G, tp);
            }
        }
    }
}
void countind(GL* G, int ind[])
{
    GNode* p;
    for (int i = 0;i < G->n;i++)
    {
        p = G->vexlist[i].firstnode;
        while (p)
        {
            ind[p->adjvex]++;
            p = p->next;
        }
    }
}
void countoutd(GL* G, int outd[])
{
    GNode* p;
    for (int i = 0;i < G->n;i++)
    {
        p = G->vexlist[i].firstnode;
        while (p)
        {
            outd[i]++;
            p = p->next;
        }
    }
}
void countd(GL* G, int d[])
{
    countind(G, d);
    countoutd(G, d);
}
int main()
{
    Tree* T = new Tree;
    T->info = '#';
    /*GM* G1 = new GM;
    createGraph1(G1);
    //DpsTraverseM(G1,T);
    BfsTraverseM(G1, T);*/
    GL* G2 = new GL;
    createGraph2(G2);
    BfsTraverseL(G2, T);
    postorder(T);
    printf("\n");
    inorder(T);
}


