#include "LinkList.h"

int Count(position head)
{
	position p = head;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count-1;
}