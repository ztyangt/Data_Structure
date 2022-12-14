#include <stdio.h>


#define ElemType int
#define MAXSIZE	 100



// 静态分配
typedef struct {
	ElemType data[MAXSIZE];
	int length;
	int MaxSize;
}SqList;

//初始化
void InitList(SqList& L)
{
	L.length = 0;
}

bool ListInsert(SqList& L, int i, ElemType e) {
	if (L.length >= MAXSIZE || i < 1 || i > L.length + 1)
		return false;
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//查找元素,返回值
int GetElem(SqList L, int i)
{
	if (i < 1 || i > L.length)
		return 0;
	return L.data[i-1];
}


//删除元素
bool ListDelete(SqList& L, int i, ElemType &e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//查找元素，返回位序
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i + 1;
	}
	return 0;
}

//遍历顺序表元素
void Print_SeqList(SqList L)
{
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}


