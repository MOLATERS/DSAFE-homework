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

	printf("初始第一个表为：\n");
	show(L);
	printf("初始第二个表为：\n");
	show(L2);
	Sort(&L);
	Sort(&L2);
	printf("排序后第一个表为：\n");
	show(L);
	printf("排序后第二个表为：\n");
	show(L2);
	printf("合并两个表后：\n");
	sumlist(&L,&L2);
	show(L);
	printf("删除所有重复元素后：\n");
	DeleteAllSame(&L);
	show(L);
	printf("逆置表后：\n");
	Reverse(&L,1,l->last);
	show(L);
	printf("左移3位后：\n");
	LeftMove(&L, 3);
	show(L);
	printf("右移3位后：\n");
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
