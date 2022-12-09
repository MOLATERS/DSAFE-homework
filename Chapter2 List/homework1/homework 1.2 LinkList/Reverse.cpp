#include "LinkList.h"

position Reverse(int start,int end, position head)
{
	for (int i = start,j=end; i < j; i++,j--)
	{
		swap(i, j, head);
	}
	return head;
}
void LeftMove(int step, position head)
{
	int last = End(head);
	Reverse(1, step, head);
	Reverse(step + 1, last, head);
	Reverse(1, last, head);
}
void RightMove(int step, position head)
{
	int last = End(head);
	LeftMove(last - step, head);
}