#include "floyd.h"

int main() {
    MTgraph G;
    int nod1=9;
    int nod2=2;
    int point=5;
    int**D=NULL;
    int**P=NULL;
    CreatMGraph(&G);
    D=(int**) malloc(sizeof (int*)*(G.n+1));
    P=(int**) malloc(sizeof (int*)*(G.n+1));
    for(int i=1;i<=G.n;i++)
    {
        D[i]=(int*) malloc(sizeof(int)*(G.n+1));
        P[i]=(int*) malloc(sizeof(int)*(G.n+1));
    }
    Floyd(D,G,P);
    show(G);
    showP(D,G.n);
    showP(P,G.n);
    printf("所有点到%d号点的最短路径以及长度为：\n",point);
    for(int k=G.n;k>=1;k--)
    {
        if(k==point)continue;
        ShowPath(P,D,G,k,point,1);
        if(D[k][point]!=NONE)
            printf("\nThe length is %d\n",D[k][point]);
    }
    printf("\n\n");
    printf("%d号点和%d号点之间的路径及其长度为：\n",nod1,nod2);
    ShowNodes(P,D,G,nod1,nod2);
    return 0;
}
