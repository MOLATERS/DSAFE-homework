#include"LinkList.h"

position SumList(position head, position head1)
{
	position p = head;
	position p1 = head1;
	int len1 = Count(head);
	int len2 = Count(head1);
	position head_1=initial(len1+len2);
	position temp = head_1;
	while (temp->next!=NULL)
	{
		if (p1->next && p->next)
		{
			if (p1->element < p->element)
			{
				temp->element = p1->element;
				p1 = p1->next;
			}
			else if (p1->element >= p->element)
			{
				temp->element = p->element;
				p = p->next;
			}
		}
		else if (p1->next == NULL && p->next!=NULL)
		{
			temp->element = p->element;
			p = p->next;
		}
		else if (p->next == NULL && p1->next != NULL)
		{
			temp->element = p1->element;
			p1 = p1->next;
		}
		temp = temp->next;
	}
	return head_1;
}