#include "BT.h"
int level[maxlength] = {0};    //记录二叉树的宽度
int Wid = 0;                   //表明二叉树的宽度
BT *Node(type x, BT *L, BT *R) //创建节点
{
    BT *p = (BT *)malloc(sizeof(BT));
    if (p == NULL)
    {
        printf("fail!");
    }
    p->data = x;
    p->Lchild = L;
    p->Rchild = R;
    return p;
}
void push(BT *T, ST *S) //压入栈中的元素
{
    if (S->top >= maxlength)
    {
        return;
    }
    else
    {
        S->top++;
        S->s[S->top] = T;
    }
}
BT *pop(ST *S) //弹出栈内部的元素
{
    if (S->top == -1)
    {
        return NULL;
    }
    else
    {
        S->top--;
        return S->s[S->top + 1];
    }
}
type visit(BT *T) //访问树结点的数值
{
    printf("%d ", T->data);
    return T->data;
}
int IsEmpty(BT *T) //判断树结点是否为空
{
    if (T == NULL)
        return 1;
    else
        return 0;
}
BT *createBT(FILE *fp) //根据文件tree.txt创建二叉树
{
    BT *p;
    int x;
    // printf("Please enter the data( 0 for no data ): ");
    fscanf(fp, " %d", &x);
    if (x == 0)
    {
        return NULL;
    }
    else
    {
        p = (BT *)malloc(sizeof(BT));
        p->data = x;
        // printf("The left tree's data:\n");
        p->Lchild = createBT(fp);
        // printf("The right tree's data:\n");
        p->Rchild = createBT(fp);
    }
    return p;
}
void PreOrder(BT *T) //递归的方式完成先序遍历二叉树
{
    if (!IsEmpty(T))
    {
        visit(T);
        PreOrder(T->Lchild);
        PreOrder(T->Rchild);
    }
    else
        return;
}
void MidOrder(BT *T) //递归的方式完成中序遍历二叉树
{
    if (!IsEmpty(T))
    {
        MidOrder(T->Lchild);
        visit(T);
        MidOrder(T->Rchild);
    }
    else
        return;
}
void AftOrder(BT *T) //递归的方式完成后序遍历二叉树
{
    if (!IsEmpty(T))
    {
        AftOrder(T->Lchild);
        AftOrder(T->Rchild);
        visit(T);
    }
    else
        return;
}
void PreOrder_X(BT *T) //循环的方式完成先序遍历二叉树
{
    ST S;
    S.top = -1;
    BT *p = T;
    while (1)
    {
        if (p->Lchild != NULL)
        {
            printf("%d ", p->data);
            push(p, &S);
            p = p->Lchild;
        }
        else
        {
            if (p->Rchild != NULL)
            {
                printf("%d ", p->data);
                p = p->Rchild;
            }
            else if (p->Rchild == NULL)
            {
                printf("%d ", p->data);
                if (S.top != -1)
                {
                    p = pop(&S);
                    while (p->Rchild == NULL)
                        p = pop(&S);
                    p = p->Rchild;
                }
                else
                    break;
            }
        }
    }
}
void MidOrder_X(BT *T) //循环的方式完成中序遍历二叉树
{
    ST S;
    S.top = -1;
    BT *p = T;
    while (1)
    {
        if (p->Lchild != NULL)
        {
            push(p, &S);
            p = p->Lchild;
        }
        else
        {
            if (p->Rchild != NULL)
            {
                printf("%d ", p->data);
                p = p->Rchild;
            }
            else if (p->Rchild == NULL)
            {
                printf("%d ", p->data);
                if (S.top != -1)
                {
                    p = pop(&S);
                    printf("%d ", p->data);
                    while (p->Rchild == NULL)
                    {
                        p = pop(&S);
                        printf("%d ", p->data);
                    }
                    p = p->Rchild;
                }
                else
                    break;
            }
        }
    }
}
void AftOrder_X(BT *T) //循环的方式完成后序遍历二叉树
{
    ST S;
    int s[maxlength];
    S.top = -1;
    BT *p = T;
    while (p != NULL || S.top != -1)
    {
        while (p != NULL)
        {
            push(p, &S);
            s[S.top] = 1;
            p = p->Lchild;
        }
        while (S.top != -1 && s[S.top] == 2)
        {
            p = pop(&S);
            printf("%d ", p->data);
        }
        if (S.top != -1)
        {
            s[S.top] = 2;
            p = pop(&S);
            push(p, &S);
            p = p->Rchild;
        }
        if (p == T && S.top == -1)
            break;
    }
}
void LeverOder(BT *T) //层序遍历二叉树
{
    int head = 0, tail = 0;
    BT *Q[maxlength];
    if (T == NULL)
        return;
    Q[tail++] = T;
    BT *temp;
    while (head != tail)
    {
        temp = Q[head++];
        printf("%d ", temp->data);
        if (temp->Lchild != NULL)
            Q[tail++] = temp->Lchild;
        if (temp->Rchild != NULL)
            Q[tail++] = temp->Rchild;
    }
}
int Hight(BT *T) //计算二叉树的高度
{
    int l;
    int r;
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        l = Hight(T->Lchild);
        r = Hight(T->Rchild);
        return l > r ? l + 1 : r + 1;
    }
}
int Dev(BT *T) //计算每个点的度
{
    if (T->Lchild != NULL && T->Rchild != NULL)
        return 2;
    else if ((T->Lchild == NULL && T->Rchild != NULL) || (T->Rchild == NULL && T->Lchild != NULL))
        return 1;
    if (T->Lchild == NULL && T->Rchild == NULL)
        return 0;
}
int Judge(BT *T) //判断是否为二叉树
{
    int head = 0, tail = 0;
    BT *Q[maxlength];
    if (T == NULL)
        return 0;
    Q[tail++] = T;
    T->leve = 1;
    BT *temp;
    int hight = Hight(T);
    int dev[maxlength];
    while (head != tail)
    {
        temp = Q[head++];
        if (temp->Lchild != NULL)
            Q[tail++] = temp->Lchild;
        if (temp->Rchild != NULL)
            Q[tail++] = temp->Rchild;
    }
    for (int i = 0; i <= head - 1; i++)
    {
        dev[i] = Dev(Q[i]);
        if (i <= pow(2, hight - 2) - 2)
        {
            if (dev[i] != 2)
                return 0;
        }
        if (dev[i] == 1)
        {
            if (Q[i]->Lchild == NULL)
                return 0;
        }
    }
    return 1;
}
void Width(BT *T, int leve) //递归计算二叉树的宽度
{
    if (T == NULL)
    {
        return;
    }
    level[leve]++;
    Wid = level[leve] > Wid ? level[leve] : Wid;
    Width(T->Lchild, leve + 1);
    Width(T->Rchild, leve + 1);
}
int Width_X(BT *T) //循环计算二叉树的宽度
{
    int head = 0, tail = 0;
    BT *Q[maxlength];
    if (T == NULL)
        return 0;
    Q[tail++] = T;
    T->leve = 0;
    BT *temp;
    int *leve = (int *)malloc(sizeof(int) * Hight(T));
    while (head != tail)
    {
        temp = Q[head++];
        if (temp->Lchild != NULL)
        {
            Q[tail++] = temp->Lchild;
            temp->Lchild->leve = temp->leve + 1;
        }
        if (temp->Rchild != NULL)
        {
            Q[tail++] = temp->Rchild;
            temp->Rchild->leve = temp->leve + 1;
        }
    }
    for (int i = 0; i <= head - 1; i++)
    {
        leve[i] = 0;
    }
    for (int i = 0; i <= head - 1; i++)
    {
        int j = Q[i]->leve;
        leve[j]++;
    }
    return FindMax(leve, Hight(T));
}
int FindMax(int *leve, int hight) //寻找数组中数据的最大值
{
    int max = leve[0];
    for (int i = 1; i <= hight - 1; i++)
    {
        if (leve[i] > max)
        {
            max = leve[i];
        }
    }
    return max;
}
int main()
{
    FILE *fp = fopen("tree.txt", "r");
    BT *T = Node(NOT, NULL, NULL);
    T = createBT(fp);
    if (T->data != NOT)
        printf("Binary Tree has been prepared!\n");
    int choice = 1;
    while (choice != 0)
    {
        printf("Please Enter your choice( 0 for exit ):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("先序递归遍历二叉树结果：");
            PreOrder(T);
            printf("\n");
            printf("先序循环遍历二叉树结果：");
            PreOrder_X(T);
            printf("\n");
            break;
        case 2:
            printf("中序递归遍历二叉树结果：");
            MidOrder(T);
            printf("\n");
            printf("中序循环遍历二叉树结果：");
            MidOrder_X(T);
            printf("\n");
            break;
        case 3:
            printf("后序递归遍历二叉树结果：");
            AftOrder(T);
            printf("\n");
            printf("后序循环遍历二叉树结果：");
            AftOrder_X(T);
            printf("\n");
            break;
        case 4:
            printf("层序遍历二叉树结果：");
            LeverOder(T);
            printf("\n");
            break;
        case 5:
            printf("判断二叉树是否为完全二叉树：\n");
            if (Judge(T))
                printf("是\n");
            else
                printf("否\n");
            break;
        case 6:
            printf("递归计算二叉树宽度：");
            Width(T, 0);
            printf("%d\n", Wid);
            break;
        case 7:
            printf("循环计算二叉树宽度：");
            printf("%d\n", Width_X(T));
            break;
        default:
            break;
        }
    }
    return 0;
}
