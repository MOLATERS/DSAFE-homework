#include <stdio.h>
#include "SeqList.h"
#include <stdlib.h>
int show(list L);

int main()
{
	list L,L2;
	L.last = 90;
	L2.last = 20;
	list* l=&L;
	FILE *p=fopen("Data.txt","r");
	if(p==NULL)
	{
		printf("failed!");
	}
	for(int i=1;i<=L.last;i++)
	fscanf(p," %d",&L.element[i]);
	for(int i=1;i<=L2.last;i++)
	{
		//p--;
		fscanf(p," %d",&L2.element[i]);
	}
	fclose(p);

	printf("��ʼ��һ����Ϊ��\n");
	show(L);
	printf("��ʼ�ڶ�����Ϊ��\n");
	show(L2);
	Sort(&L);
	Sort(&L2);
	printf("������һ����Ϊ��\n");
	show(L);
	printf("�����ڶ�����Ϊ��\n");
	show(L2);
	printf("�ϲ��������\n");
	sumlist(&L,&L2);
	show(L);
	printf("ɾ�������ظ�Ԫ�غ�\n");
	DeleteAllSame(&L);
	show(L);
	printf("���ñ��\n");
	Reverse(&L,1,l->last);
	show(L);
	printf("����3λ��\n");
	LeftMove(&L, 3);
	show(L);
	printf("����3λ��\n");
	RightMove(&L, 6);
	show(L);


	for(int i=1;i<=90;i++)
	L.element[i] = (type)(rand() % 100);
	FILE *q=fopen("listdata(2).txt","w");
	if(q==NULL)
	{
		printf("failed!");
	}
	for(int i=1;i<=90;i++)
	fprintf(q," %d",L.element[i]);
	fclose(q);


	return 0;
}

int show(list L)
{
	for (int i = 1; i <= L.last; i++)
		printf("%d ", L.element[i]);
	printf("\n\n");
	return 0;
}
