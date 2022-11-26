#include "SeqList.h"


int main() 
{
	int a, b;
	ElemType m;
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 5);
	ListInsert(L, 4, 7);
	PrintList(L);
	a = GetElem(L, 2);
	printf("第二个元素为：%d\n", a);
	b = LocateElem(L, 7);
	printf("7的位序为：%d\n", b);
	ListDelete(L, 1, m);
	printf("删除的元素为： %d\n", m);
	printf("删除后的顺序表为：\n");
	PrintList(L);
	return 0;
}