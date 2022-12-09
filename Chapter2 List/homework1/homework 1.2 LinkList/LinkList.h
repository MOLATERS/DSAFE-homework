#ifndef _Linklist
#define _Linklist 
#endif // !1
#include <iostream>
#include <fstream>
typedef int Type;
typedef int index;

struct celltype {
	Type element;
	celltype* next, * previous;
	index order;
};
typedef struct celltype* position;

position initial(int size);//��ʼ������
position Locate(Type x, position head);//��λ�����ӦԪ�ص�λ��
void Delete_element(Type x, position head);//ɾ��Ԫ��
void show(position head);//չʾ�����ڴ洢������
position Locate_index(int n, position head);//��λ��ȷ������
void insert(position add, position p);//��p�������һ��������
void swap(int i, int j, position& head);//��������������
void Sort(position head);//��������������
int End(position head);//����������
void Delete_cell(position p, position head);//ɾ����λ����
void Delete_same(position head);//ɾ���ظ�Ԫ��
position Reverse(int start,int end,position head);//ת��
void LeftMove(int step, position head);//����nλ
void RightMove(int step, position head);//����n
position SumList(position head, position head1);//�ϲ������Ѿ��ź��������
void Reinitial(position head);
int Count(position head);