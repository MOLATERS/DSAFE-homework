#include "LinkList.h"

void insert(position add, position p)//把n结点插入到p节点后
{
	if (p->next != NULL)
	{
		add->next = p->next;
		p->next->previous = add;
		p->next = add;
		add->previous = p;
	}
	else if (p->next==NULL)
	{
		add->next = NULL;
		p->next = add;
		add->previous = p;
	}

}