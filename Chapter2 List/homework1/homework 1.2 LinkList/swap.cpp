#include"LinkList.h"

void swap(int i, int j, position& head)
{
	position pi = Locate_index(i, head);
	position pj = Locate_index(j, head);
	Type temp;
	temp = pi->element;
	pi->element = pj->element;
	pj->element = temp;
}
void Swap(position &i, position &j)
{
	position temp;
	temp = i;
	i = j;
	j = temp;
}