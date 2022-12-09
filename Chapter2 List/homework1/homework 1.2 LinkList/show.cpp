#include"LinkList.h"
using namespace std;

void show(position head)
{
	position p = head;
	while (p->next != NULL)
	{
		cout << p->element << " ";
		p = p->next;
	}
	cout<<endl;
}