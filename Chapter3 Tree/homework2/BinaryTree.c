#include "BT.h"
int level[maxlength] = {0};    //��¼�������Ŀ��
int Wid = 0;                   //�����������Ŀ��
BT *Node(type x, BT *L, BT *R) //�����ڵ�
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
void push(BT *T, ST *S) //ѹ��ջ�е�Ԫ��
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
BT *pop(ST *S) //����ջ�ڲ���Ԫ��
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
type visit(BT *T) //������������ֵ
{
    printf("%d ", T->data);
    return T->data;
}
int IsEmpty(BT *T) //�ж�������Ƿ�Ϊ��
{
    if (T == NULL)
        return 1;
    else
        return 0;
}
BT *createBT(FILE *fp) //�����ļ�tree.txt����������
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
void PreOrder(BT *T) //�ݹ�ķ�ʽ����������������
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
void MidOrder(BT *T) //�ݹ�ķ�ʽ����������������
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
void AftOrder(BT *T) //�ݹ�ķ�ʽ��ɺ������������
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
void PreOrder_X(BT *T) //ѭ���ķ�ʽ����������������
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
void MidOrder_X(BT *T) //ѭ���ķ�ʽ����������������
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
void AftOrder_X(BT *T) //ѭ���ķ�ʽ��ɺ������������
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
void LeverOder(BT *T) //�������������
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
int Hight(BT *T) //����������ĸ߶�
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
int Dev(BT *T) //����ÿ����Ķ�
{
    if (T->Lchild != NULL && T->Rchild != NULL)
        return 2;
    else if ((T->Lchild == NULL && T->Rchild != NULL) || (T->Rchild == NULL && T->Lchild != NULL))
        return 1;
    if (T->Lchild == NULL && T->Rchild == NULL)
        return 0;
}
int Judge(BT *T) //�ж��Ƿ�Ϊ������
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
void Width(BT *T, int leve) //�ݹ����������Ŀ��
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
int Width_X(BT *T) //ѭ������������Ŀ��
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
int FindMax(int *leve, int hight) //Ѱ�����������ݵ����ֵ
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
            printf("����ݹ���������������");
            PreOrder(T);
            printf("\n");
            printf("����ѭ�����������������");
            PreOrder_X(T);
            printf("\n");
            break;
        case 2:
            printf("����ݹ���������������");
            MidOrder(T);
            printf("\n");
            printf("����ѭ�����������������");
            MidOrder_X(T);
            printf("\n");
            break;
        case 3:
            printf("����ݹ���������������");
            AftOrder(T);
            printf("\n");
            printf("����ѭ�����������������");
            AftOrder_X(T);
            printf("\n");
            break;
        case 4:
            printf("������������������");
            LeverOder(T);
            printf("\n");
            break;
        case 5:
            printf("�ж϶������Ƿ�Ϊ��ȫ��������\n");
            if (Judge(T))
                printf("��\n");
            else
                printf("��\n");
            break;
        case 6:
            printf("�ݹ�����������ȣ�");
            Width(T, 0);
            printf("%d\n", Wid);
            break;
        case 7:
            printf("ѭ�������������ȣ�");
            printf("%d\n", Width_X(T));
            break;
        default:
            break;
        }
    }
    return 0;
}
