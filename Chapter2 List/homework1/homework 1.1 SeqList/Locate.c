#include"SeqList.h"

position Locate(type x, list* L)//�ҵ�ָ��Ԫ��λ��
{
	position q;
	for (q = 1; q <= L->last; q++)
	{
		if (L->element[q] == x)
		{
			return q;
		}
	}
	return L->last;
}
