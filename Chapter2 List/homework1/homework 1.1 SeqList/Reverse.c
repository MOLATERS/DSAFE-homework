#include "SeqList.h"

int Reverse(list* L,type start,type end)//ת�����Ա�
{
	int i =start;
	int j =end;
	for (; i < j; j--, i++)
	{
		swap(&L->element[i], &L->element[j]);
	}
	return 1;
}
void LeftMove(list* L, type step)//�����Ա������ƶ�stepλ
{
	Reverse(L, 1, step);
	Reverse(L, step+1, L->last);
	Reverse(L, 1, L->last);
	return;
}
void RightMove(list* L, type step)//�����Ա������ƶ�stepλ
{
	Reverse(L, L->last-step+1, L->last);
	Reverse(L, 1, L->last-step);
	Reverse(L, 1, L->last);
	return;
}
