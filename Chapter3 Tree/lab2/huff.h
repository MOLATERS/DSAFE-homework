#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxlength 100
typedef struct HuffmanTree{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char x;
}HFM;
typedef struct HFMcode{
    char ch;
    char bit[maxlength+1];
}Node;
typedef struct NodeWeight{
    char ch;
    double weight;
}NW;
typedef Node HFT[maxlength];
void SetWeight(FILE* fp);
void NWinitial();
void HFinitial();
void TwoMin(int n,int *num1,int *num2);
void Code();
void Transfer(FILE* fp,FILE* fq);
void Recover(const HFM T[2*maxlength], FILE* fq,FILE* fg);
