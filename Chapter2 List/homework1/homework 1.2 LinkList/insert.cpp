#include "LinkList.h"

void insert(position add, position p)//��n�����뵽p�ڵ��
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