#include "SeqList.h"

void Insert(type x, position p, list* L)//��ָ��λ�ò���Ԫ��
{
	position q;
	if (p >= maxlength) printf("The list is full!");
	else if (p <= 0 || p > L->last + 1)printf("Wrong input!");
	else
	{
		for (q = L->last; q >= p; q--)
		{
			L->element[q + 1] = L->element[q];
		}
		L->last += 1;
		L->element[p] = x;
	}
}
