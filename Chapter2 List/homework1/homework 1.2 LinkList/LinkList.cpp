#include "LinkList.h"
using namespace std;

int main() {
	position head = initial(50);
	position head1 = initial(30);
	cout << "��һ������:"<<endl;
	show(head);
	cout << "�ڶ�������:"<<endl ;
	show(head1);
	cout << endl;
	Sort(head);
	Sort(head1);
	cout << "����������" << endl;
	cout << "��һ������:"<< endl;
	show(head);
	cout << "�ڶ�������:"<< endl;
	show(head1);
	cout << endl;
	head=SumList(head, head1);
	Reinitial(head);
	cout << "�ϲ��������"<< endl;
	Sort(head);
	show(head);
	cout << endl;
	cout << "ɾ���ظ�Ԫ�ص�����"<< endl;
	Delete_same(head);
	show(head);
	cout << endl;
	head=Reverse(1,End(head),head);
	cout << "��������"<< endl;
	show(head);
	cout << endl;
	LeftMove(3, head);
	cout << "����3λ��"<< endl;
	show(head);
	cout << endl;
	RightMove(6, head);
	cout << "������λ��"<< endl;
	show(head);
}