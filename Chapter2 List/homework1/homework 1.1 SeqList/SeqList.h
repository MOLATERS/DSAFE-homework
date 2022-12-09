#ifndef _LIST
#define _LIST
#endif

#define maxlength 200
#include <stdio.h>
#include<string.h>

typedef int position;
typedef int type;

typedef struct LIST {
	type element[maxlength];
	int last;
}list;

void sumlist(list *L,const list*L2);//�ϲ��ź�������Ա�
void Delete(position p, list* L);//ɾ��ָ��λ�õĽ��
void Insert(type x, position p, list* L);//��ָ��λ�ò���
position Locate(type x, list* L);//��λĳ��Ԫ���ڱ��е�λ��
void Sort(list* L);//�����Ա��е�Ԫ�ؽ�������
void Delete_Same(list* L,type x);//ɾ�����Ա��е��ض�Ԫ��
void swap(type* a, type* b);//����Ԫ��
int Reverse(list* L, type start, type end);//�������Ա�
void LeftMove(list* L, type step);//�������Ա�
void RightMove(list* L, type step);//�������Ա�
void DeleteAllSame(list* L);//ɾ�������ظ�Ԫ��



