#ifndef _LIST
#define _LIST
#endif

#define maxlength 200
#include <stdio.h>
#include<string.h>

typedef int position;
typedef int type;

typedef struct LIST {
	type element[maxlength];
	int last;
}list;

void sumlist(list *L,const list*L2);//合并排好序的线性表
void Delete(position p, list* L);//删除指定位置的结点
void Insert(type x, position p, list* L);//在指定位置插入
position Locate(type x, list* L);//定位某个元素在表中的位置
void Sort(list* L);//对线性表中的元素进行排序
void Delete_Same(list* L,type x);//删除线性表中的特定元素
void swap(type* a, type* b);//交换元素
int Reverse(list* L, type start, type end);//逆置线性表
void LeftMove(list* L, type step);//左移线性表
void RightMove(list* L, type step);//右移线性表
void DeleteAllSame(list* L);//删除所有重复元素



