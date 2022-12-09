//
// Created by Slater on 2022/11/14.
//

#ifndef CHAPTER5_SEARCH_SEARCH_H
#define CHAPTER5_SEARCH_SEARCH_H

typedef int keytype;
typedef char fields;
typedef struct records{
    keytype key;
    fields other;
}records;
typedef struct BSTnode{
    records data;
    struct BSTnode *lchild;
    struct BSTnode *rchild;
}BSTnode;
typedef  BSTnode* BST;
BST InsertBST(records R, BST F,int flag);//插入查找树结点
BSTnode * SearchBST( keytype  k, BST F);//递归查找操作
BST CreateBST (FILE*fp);//创建一个查找树
records  deletemin(BST F);//删除最小元素对应节点
void visit(BST F);//中序遍历，形成有序序列
#endif //CHAPTER5_SEARCH_SEARCH_H