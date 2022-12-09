#ifndef _Linklist
#define _Linklist 
#endif // !1
#include <iostream>
#include <fstream>
typedef int Type;
typedef int index;

struct celltype {
	Type element;
	celltype* next, * previous;
	index order;
};
typedef struct celltype* position;

position initial(int size);//初始化链表
position Locate(Type x, position head);//定位链表对应元素的位置
void Delete_element(Type x, position head);//删除元素
void show(position head);//展示链表内存储的数据
position Locate_index(int n, position head);//用位置确定链表
void insert(position add, position p);//在p结点后插入一个链表结点
void swap(int i, int j, position& head);//交换链表间的数据
void Sort(position head);//对链表升序排序
int End(position head);//返回链表长度
void Delete_cell(position p, position head);//删除单位链表
void Delete_same(position head);//删除重复元素
position Reverse(int start,int end,position head);//转置
void LeftMove(int step, position head);//左移n位
void RightMove(int step, position head);//右移n
position SumList(position head, position head1);//合并两个已经排好序的链表
void Reinitial(position head);
int Count(position head);