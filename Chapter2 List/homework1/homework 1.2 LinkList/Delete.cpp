#include "LinkList.h"

void Delete_element(Type x, position head)
{
	position p = new celltype;
	p=	Locate(x, head);
	if (p != NULL)
	{
		p->next->previous = p->previous;
		p->previous->next = p->next;
	}
	delete(p);
}
void Delete_cell (position p, position head)
{
	p->next->previous = p->previous;
	p->previous->next = p->next;
	delete(p);
}
void Delete_same(position head)
{
	position p = new celltype;
	p = head;
	while (p->next != NULL)
	{
		if (p->next->element == p->element)
		{
			Delete_cell(p->next, head);
			if (p != head)
				p = p->previous;
			else
				p = head;
		}
		p = p->next;
	}
}