#include "SeqList.h"

void Delete(position p, list* L)//删除指定位置的元素
{
	position q;
	if (p >= L->last + 1 || p < 1) printf("Wrong input\n");
	else {
		for (q = p; q <= L->last; q++)
		{
			L->element[q] = L->element[q + 1];
		}
		L->last -= 1;
	}
}

void DeleteAllSame(list* L)//删除所有的重复元素
{
	int count=0;
	for(int i=1;i<=L->last;i++)
	{
		if(L->element[i]==L->element[i+1])
		{
			Delete_Same(L, L->element[i+1]);
			count++;
		}
	}
	printf("一共删除%d个\n",count);
}

void Delete_Same(list* L,type x)//删除指定元素的重复元素
{
	position q;
	q=1+Locate(x,L);
	while (q < L->last+1)
	{
		if (L->element[q] == x)
			Delete(q,L);
		else
			q = q + 1;
	}
}
