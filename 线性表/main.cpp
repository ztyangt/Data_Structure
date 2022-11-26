#include "SeqList.h"
#include "SingleLink.h"

// 顺序表
void SeqList(){
	int a, b;
	ElemType m;
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 5);
	ListInsert(L, 4, 7);
	Print_SeqList(L);
	a = GetElem(L, 2);
	printf("第二个元素为：%d\n", a);
	b = LocateElem(L, 7);
	printf("7的位序为：%d\n", b);
	ListDelete(L, 1, m);
	printf("删除的元素为： %d\n", m);
	printf("删除后的顺序表为：\n");
	Print_SeqList(L);
}

// 单链表
void SingleLink(){
	LinkList L,M;
	ElemType x;
	int a;
	bool flag;
	List_HeadInsert(L,0);
	// 插入元素
	for(int i=1;i<9;i++){
		ListInsert(L,i,i*10);
	}
	Print_LinkList(L);
	M = GetElem(L,5);
	printf("第五位元素为：%d\n",M->data);
	a = FindElem(L,70);
	printf("70的位置为：%d\n",a);
	flag = ListDelete(L,6,x);
	if(flag){
		printf("删除第6个元素成功：%d\n",x);
		printf("删除后的链表为：");
		Print_LinkList(L);
	}else{
		printf("删除失败");
	}
}

int main() 
{
	// SeqList();
	SingleLink();
	return 0;
}