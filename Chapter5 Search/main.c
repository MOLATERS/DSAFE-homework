#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include <stdio.h>
#include <malloc.h>
#include "search.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
long count=0;//�������е��β��ҳ��ȼ���
long double sum=0;//������¼������ҳ���
long number=0;//������¼Ԫ�صĸ���
int a[2000]={0};//�����洢���г���Ԫ��
records Bin[2000]={0};//Ԫ�ض��ڹؼ������ɵ�˳���

BST InsertBST(records R, BST F,int flag)//����������ڵ�
{
    if ( F ==NULL ) {
        F =(BST) malloc(sizeof (BSTnode));
        F->data = R;
        F->lchild = NULL;
        F->rchild = NULL;
    }else  if ( R.key < F->data.key )
        F->lchild=InsertBST( R , F->lchild,0);
    else  if ( R.key > F->data.key )
        F->rchild=InsertBST( R , F->rchild,0);
    return F;
}

BSTnode * SearchBST( keytype  k, BST F )//�ݹ���Ҳ���
{
    BST p = F;
    if (p == NULL) {
        return p;
    } else {
        if (k == p->data.key) { //�ݹ���ֹ����
            count++;
            return p;
        }
    }
    if ( k < p->data.key )
    {
        count++;
        return ( SearchBST ( k,  p->lchild ) ) ; //����������
    }
    else
    {
        count++;
        return ( SearchBST ( k,  p->rchild ) ) ; //����������
    }

}
BST CreateBST (FILE*fp)//����һ�����������
{
    BSTnode* F=NULL;
    keytype key;
    records R;
    fscanf(fp,"%d ",&key);//����һ����¼
    while(key){  //����key=0�����������־
        a[number]=key;
        number++;
        R.key=key;
        R.other='\0';
        F=InsertBST(R, F, 1);//�����¼R
        fscanf(fp,"%d",&key);//�����¸���¼
    }
    return F;
}
records  deletemin(BST F)//ɾ����СԪ��
{
    records tmp ;
    BST p ;
    if (F->lchild==NULL){//����СԪ
        p = F ;
        tmp = F->data ;
        F = F->rchild ; //�����̳�
        free(p) ;
        return tmp ;//���ظ���С�ڵ�ֵ
    }
    else//���������գ���С�������������
        return deletemin(F->lchild);//���������ϵݹ��ɾ��
}

BST  DeleteB (keytype k,BST F)
{
    if ( F != NULL )
    {
        if ( k < F->data.key )
            F->lchild=DeleteB( k, F->lchild );
        else if (k > F->data.key)
            F->rchild=DeleteB(k, F->rchild);
        else
        { // k==F->data.key
            if (F->rchild == NULL)
                F = F->lchild;//�����̳�,����Ҷ
            else if (F->lchild == NULL)
                F = F->rchild;//�����̳�,����Ҷ
            else //����������
                F->data = deletemin(F->rchild);
        }
    }
    else return NULL;
    return F;
}
void visit(BST F)//����������γ���������
{
    if(F==NULL)return;
    visit(F->lchild);
//    printf("%d ",F->data.key);
    Bin[number++]=F->data;
    visit(F->rchild);
}

int BinFind(const keytype k,int low,int high)//�۰���ҵݹ鷽��
{
    int temp;//�����е�λ���±�
    if(low>high)return -1;
    else
    {
        int temp=(low+high)/2;
        if(k<Bin[temp].key)
        {
            count++;
            return BinFind(k,low,temp-1);
        }
        else if(k>Bin[temp].key)
        {
            count++;
            return BinFind(k,temp+1,high);
        }
        else
        {
            count++;
            return temp;
        }
    }
}

int main() {
    FILE*fp;
    BST F=NULL;
    BST answer=NULL;
    double average_length=0;
    fp=fopen("C:\\Users\\Slater\\Documents\\vscode\\.vscode\\DSAFE\\Chapter5 Search\\data.txt","r");
    F=CreateBST(fp);
    for(int i=0;i<number-1;i++)
    {
        SearchBST(a[i],F);
        sum=sum+count;
        count=0;
    }
    average_length=(double)(sum)/number;
    printf("���������ҳɹ�ƽ�����ȣ�%.2f\n",average_length);
    sum=0;
    for(int i=0;i<number-1;i++)
    {
        SearchBST(1234,F);
        sum=sum+count;
        count=0;
    }
    average_length=(double)(sum)/number;
    printf("����������ʧ��ƽ������: %.2f\n",average_length);
    number=0;
    visit(F);
    printf("\n");
    sum=0;
    for(int i=0;i<number-1;i++) {
        BinFind(a[i],0,1023);
        sum = sum + count;
        count = 0;
    }
    average_length=(double)(sum)/number;
    printf("�۰���ҳɹ�ƽ������: %.2f\n",average_length);
    sum=0;
    for(int i=0;i<number-1;i++) {
        BinFind(1234,0,1023);
        sum = sum + count;
        count = 0;
    }
    average_length=(double)(sum)/number;
    printf("�۰����ʧ��ƽ������: %.2f",average_length);
//    F=DeleteB(5,F);
//    visit(F);
    return 0;

}