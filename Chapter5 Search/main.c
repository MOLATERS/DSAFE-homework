#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include <stdio.h>
#include <malloc.h>
#include "search.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
long count=0;//用来进行单次查找长度计数
long double sum=0;//用来记录总体查找长度
long number=0;//用来记录元素的个数
int a[2000]={0};//用来存储所有出现元素
records Bin[2000]={0};//元素对于关键字生成的顺序表

BST InsertBST(records R, BST F,int flag)//插入查找树节点
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

BSTnode * SearchBST( keytype  k, BST F )//递归查找操作
{
    BST p = F;
    if (p == NULL) {
        return p;
    } else {
        if (k == p->data.key) { //递归终止条件
            count++;
            return p;
        }
    }
    if ( k < p->data.key )
    {
        count++;
        return ( SearchBST ( k,  p->lchild ) ) ; //查找左子树
    }
    else
    {
        count++;
        return ( SearchBST ( k,  p->rchild ) ) ; //查找右子树
    }

}
BST CreateBST (FILE*fp)//创建一个二叉查找树
{
    BSTnode* F=NULL;
    keytype key;
    records R;
    fscanf(fp,"%d ",&key);//读入一个记录
    while(key){  //假设key=0是输入结束标志
        a[number]=key;
        number++;
        R.key=key;
        R.other='\0';
        F=InsertBST(R, F, 1);//插入记录R
        fscanf(fp,"%d",&key);//读入下个记录
    }
    return F;
}
records  deletemin(BST F)//删除最小元素
{
    records tmp ;
    BST p ;
    if (F->lchild==NULL){//是最小元
        p = F ;
        tmp = F->data ;
        F = F->rchild ; //右链继承
        free(p) ;
        return tmp ;//返回该最小节点值
    }
    else//左子树不空，最小结点在左子树上
        return deletemin(F->lchild);//在左子树上递归地删除
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
                F = F->lchild;//右链继承,包括叶
            else if (F->lchild == NULL)
                F = F->rchild;//右链继承,包括叶
            else //有两棵子树
                F->data = deletemin(F->rchild);
        }
    }
    else return NULL;
    return F;
}
void visit(BST F)//中序遍历，形成有序序列
{
    if(F==NULL)return;
    visit(F->lchild);
//    printf("%d ",F->data.key);
    Bin[number++]=F->data;
    visit(F->rchild);
}

int BinFind(const keytype k,int low,int high)//折半查找递归方法
{
    int temp;//储存中点位置下标
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
    printf("查找树查找成功平均长度：%.2f\n",average_length);
    sum=0;
    for(int i=0;i<number-1;i++)
    {
        SearchBST(1234,F);
        sum=sum+count;
        count=0;
    }
    average_length=(double)(sum)/number;
    printf("查找树查找失败平均长度: %.2f\n",average_length);
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
    printf("折半查找成功平均长度: %.2f\n",average_length);
    sum=0;
    for(int i=0;i<number-1;i++) {
        BinFind(1234,0,1023);
        sum = sum + count;
        count = 0;
    }
    average_length=(double)(sum)/number;
    printf("折半查找失败平均长度: %.2f",average_length);
//    F=DeleteB(5,F);
//    visit(F);
    return 0;

}