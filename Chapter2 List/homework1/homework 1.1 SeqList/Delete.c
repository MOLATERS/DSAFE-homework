#include "SeqList.h"

void Delete(position p, list* L)//ɾ��ָ��λ�õ�Ԫ��
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

void DeleteAllSame(list* L)//ɾ�����е��ظ�Ԫ��
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
	printf("һ��ɾ��%d��\n",count);
}

void Delete_Same(list* L,type x)//ɾ��ָ��Ԫ�ص��ظ�Ԫ��
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
