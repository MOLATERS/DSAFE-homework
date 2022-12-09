#include "LinkList.h"
using namespace std;

int main() {
	position head = initial(50);
	position head1 = initial(30);
	cout << "第一个链表:"<<endl;
	show(head);
	cout << "第二个链表:"<<endl ;
	show(head1);
	cout << endl;
	Sort(head);
	Sort(head1);
	cout << "排序后的链表：" << endl;
	cout << "第一个链表:"<< endl;
	show(head);
	cout << "第二个链表:"<< endl;
	show(head1);
	cout << endl;
	head=SumList(head, head1);
	Reinitial(head);
	cout << "合并后的链表："<< endl;
	Sort(head);
	show(head);
	cout << endl;
	cout << "删除重复元素的链表："<< endl;
	Delete_same(head);
	show(head);
	cout << endl;
	head=Reverse(1,End(head),head);
	cout << "倒置链表："<< endl;
	show(head);
	cout << endl;
	LeftMove(3, head);
	cout << "左移3位："<< endl;
	show(head);
	cout << endl;
	RightMove(6, head);
	cout << "右移三位："<< endl;
	show(head);
}