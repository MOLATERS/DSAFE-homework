#include "SeqList.h"

int Reverse(list* L,type start,type end)//转置线性表
{
	int i =start;
	int j =end;
	for (; i < j; j--, i++)
	{
		swap(&L->element[i], &L->element[j]);
	}
	return 1;
}
void LeftMove(list* L, type step)//将线性表向左移动step位
{
	Reverse(L, 1, step);
	Reverse(L, step+1, L->last);
	Reverse(L, 1, L->last);
	return;
}
void RightMove(list* L, type step)//将线性表向右移动step位
{
	Reverse(L, L->last-step+1, L->last);
	Reverse(L, 1, L->last-step);
	Reverse(L, 1, L->last);
	return;
}
