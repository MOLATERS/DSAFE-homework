#include "huffman.h"
NW N[maxlength]; //用于记录字母出现的频率
HFM T[2*maxlength];//用于保存结点数据
Node D[maxlength];//用于保存每个字符对应的编码
int count=0;//用于记录存在的字符种类数量
int total=0;//计算出输入的总数
void NWinitial()//初始化记录表
{
    for(int i=0;i<=maxlength-1;i++)
    {
        N[i].ch='\0';
        N[i].weight=0;
    }
}
void HFMinitial()//构建哈夫曼树
{
    int num1=0,num2=0;
    for(int i=0;i<=2*count-1;i++)
    {
        T[i].weight=N[i].weight;
        T[i].x=N[i].ch;
        T[i].lchild=T[i].parent=T[i].rchild=-1;
    }
    for(int i=count;i<=count*2-2;i++)
    {      
            TwoMin(i-1,&num1,&num2);
            T[num1].parent=T[num2].parent=i;
            T[i].lchild=num1;
            T[i].rchild=num2;
            T[i].weight=T[num1].weight+T[num2].weight;
    }
}
void TwoMin(int n,int *num1,int *num2)//选取叶子中的最小频率值
{
    int n1=0,n2=0;
    while(T[n1].parent!=-1)n1++;
    for(int i=0;i<=n;i++)
    {
        if(T[i].parent!=-1)continue;
        else if(T[n1].weight>=T[i].weight)n1=i;
    }
    T[n1].parent=0;
    while(T[n2].parent!=-1)n2++;
    for(int i=0;i<=n;i++)
    {
        if(i==n1)continue;
        else if(T[i].parent!=-1)continue;
        else if(T[n2].weight>=T[i].weight)n2=i;
    }
    *num1=n1;
    *num2=n2;
}
void SetWeight(FILE* fp)//记录权值
{
    char ch;
    int i=0;
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        total++;
        i=0;
        while(N[i].ch!=ch&&N[i].weight!=0)i++;
        if(N[i].ch==ch)N[i].weight++;
        else
            {
                N[i].ch=ch;
                N[i].weight++;
                count++;
            }
        ch=fgetc(fp);
    }
    for(int i=0;i<=count-1;i++)
    {
        N[i].weight=N[i].weight/total;
    }
}
void Code()//进行哈夫曼编码
{
    int child,parent,start;
    int i;
    for(i=0;i<=count-1;i++)
    {
        char* temp=(char*)malloc(sizeof(char)*(count+1));
        D[i].ch=T[i].x;
        start=0;
        child=i;
        while((parent=T[child].parent)>=0)
        {
            temp[start++]=(T[parent].lchild==child)?'0':'1';
            child=parent;
        }
        temp[start++]='\0';
        strcpy(D[i].bit,temp);
        free(temp);
    }
}
void Transfer(FILE* fp,FILE* fq)//读取文件并转换为哈夫曼编码
{
    char ch;
    char p[16];
    unsigned char temp;
    int length;
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        for(int i=0;i<count;i++)
        {
            if(ch==D[i].ch)
            {
                strcpy(p,D[i].bit);
                break;
            }
        }
        while( (length=strlen(p))>8)
        {
            temp='\0';
            for(int i=length-1;i>=length-8;i--)
            {
                temp<<=1;
                if(p[i]=='1')
                temp|=1;
            }
            fwrite((unsigned char*)&temp,sizeof(unsigned char),1,fq);
            p[length-8]='\0';
        }
        if(0<(length=strlen(p))<=8)
        {
            temp='\0';
            for(int i=length-1;i>=0;i--)
            {
                temp<<=1;
                if(p[i]=='1')
                {
                    temp|=1;
                }
            }
            temp<<=8-length;
            fwrite((unsigned char*)&temp,sizeof(unsigned char),1,fq);
        }
        ch=fgetc(fp);
    }
}
void Recover(const HFM T[2*maxlength], FILE* fq,FILE* fg)//将哈夫曼编码还原为文本文件
{
    unsigned char ch;
    int start=2*count-2;
    fseek(fq,0,SEEK_SET);
    while(fread(&ch,sizeof(unsigned char),1,fq))
    {
        for(int i=0;i<8;++i)
        {
            if(ch&128)
            start=T[start].rchild;
            else
            start=T[start].lchild;
            if (start<count)
            {
                fprintf(fg,"%c",T[start].x);
                start=2*count-2;
                break;
            }
            ch<<=1;
        }
    }
}
void ShowA()//展示各个字符的出现频率
{
    printf("字符\t 频率\n");
    for(int i=0;i<=count-1;i++)
    {
        printf("%c\t%f\n",N[i].ch,N[i].weight);
    }
    return;
}
void ShowB()//展示各个字符的转换编码
{
    char*p;
    printf("字符\t 编码\n");
    for(int i=0;i<=count-1;i++)
    {
        printf("%c\t",D[i].ch);
        p=D[i].bit;
        while(*p!='\0'){p++;}p--;
        while(p>=D[i].bit){printf("%c",*p);p--;}
        printf("\n");
    }
}
void Compare(FILE*fp,FILE*fg)//比较生成文件和初始文件的相似度
{
    long c=0;
    long total=0;
    double result;
    fseek(fp,0,SEEK_SET);
    fseek(fg,0,SEEK_SET);
    char ch1=fgetc(fp);
    char ch2=fgetc(fg);
    while(ch1!=EOF&&ch2!=EOF)
    {
        ch1=fgetc(fp);
        ch2=fgetc(fg);
        if(ch1!=ch2)
        {
            continue;
        }
        else
        {
            c++;
        }
        total++;
    }
    result=(double)(c)/total;
    printf("生成文件的匹配度为：%.3lf%%\n",result*100);
}
int main ()
{
    FILE* fp=fopen("sourse.txt","r");
    FILE* fq=fopen("transfer.hcp","wb+");
    FILE* fg=fopen("recover.txt","w+");
    if(fp==NULL||fq==NULL||fg==NULL||N==NULL)
    {
        printf("打开文件失败");
        return -1;
    }
    NWinitial();
    SetWeight(fp);
    //ShowA();
    HFMinitial();
    Code();
    //ShowB();
    fseek(fp,0,SEEK_SET);
    Transfer(fp,fq);
    fseek(fq,0,SEEK_SET);
    Recover(T,fq,fg);
    Compare(fp,fg);
    return 0;
}