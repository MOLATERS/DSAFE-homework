#include "LinkList.h"

position Locate(Type x, position head)//x代表具体数值
{
	position p = head;
	while (p->next != NULL)
	{
		if (p->element == x)
		{
			return p;
		}
		else {
			p = p->next;
		}
	}
	return NULL;
}
position Locate_index(int n, position head)//n代表位置
{
	position p =head;
	for (int i = 0; i <= n - 2; i++)
	{
		p = p->next;
	}
	return p;
}
