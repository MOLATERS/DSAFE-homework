#include "LinkList.h"

position initial(int size)
{
	std::ifstream in("data.txt");
	Type temp1 = 0;
	if (!in.fail())
		in >> temp1;
	position head = new celltype{temp1,NULL,NULL,1};
	position end = new celltype{size,NULL,NULL};
	position p = new celltype;
	p = head;
	for (int i = 1; i <= size; i++)
	{
		if (!in.fail())
			in >> temp1;
		else
			return NULL;
		position temp = new celltype{temp1,NULL,NULL,i};
		temp->previous = p;
		p->next = temp;
		p = p->next;
	}
	end = p;
	return head;
}
void Reinitial(position head)
{
	position temp=head;
	int count = 1;
	while (temp->next != NULL)
	{
		temp->order = count;
		temp = temp->next;
		++count;
    }
}