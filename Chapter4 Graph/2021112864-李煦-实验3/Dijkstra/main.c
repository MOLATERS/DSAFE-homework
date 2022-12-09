#include "Dijk.h"
int main() {
    MTgraph G;
    int point=3;
    int nod1=9;
    int nod2=2;
    CreatMGraph(&G);
    show(G);
    int **D=(int**)malloc(sizeof(int*)*(G.n+1));
    int **S=(int**)malloc(sizeof(int*)*(G.n+1));
    int **P=(int**)malloc(sizeof(int*)*(G.n+1));
    if(D==NULL||S==NULL||P==NULL)
    {
        printf("fail!");
        return -1;
    }
    for(int i=1;i<=G.n;i++)
    {
        D[i]=(int*) malloc(sizeof(int)*(G.n+1));
        S[i]=(int*) malloc(sizeof(int)*(G.n+1));
        P[i]=(int*) malloc(sizeof(int)*(G.n+1));
        if(D[i]==NULL||S[i]==NULL||P[i]==NULL)
        {
            printf("fail!");
            return -1;
        }
    }
        Dijkstra_X(G,D,P,S);
        showP(D,G.n);
        showP(S,G.n);
        showP(P,G.n);
    printf("���е㵽%d�ŵ�����·���Լ�����Ϊ��\n",point);
    for(int k=1;k<=G.n;k++)
    {
        ShowPath_X(P[k],G,D[k],k,point);
    }
        printf("\n");
    printf("%d�ŵ��%d�ŵ�֮���·�����䳤��Ϊ��\n",nod1,nod2);
        ShowPath_X(P[nod1],G,D[nod1],nod1,nod2);
        ShowPath_X(P[nod2],G,D[nod2],nod2,nod1);
    return 0;
}
