#include "SeqList.h"

void Sort(list* L)
{
	int i = 0;
	int j = 0;
	type temp;
	for (i = 1; i <= L->last; i++)
	{
		for (j = 1; j <= L->last  - i; j++)
		{
			if (L->element[j] < L->element[j + 1])
			{
				swap(&L->element[j], &L->element[j + 1]);
			}
		}
	}
}
