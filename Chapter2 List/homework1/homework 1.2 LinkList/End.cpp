#include "LinkList.h"

int End(position head)
{
	int count = 0;
	position p = head;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}