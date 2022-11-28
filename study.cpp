#include <stdio.h> 
#include <stdlib.h>
// 不带头结点
typedef struct Linknode {
	int data;
	struct Linknode* next;
}Linknode, * LiStack;
// 后插法插入,在链栈首处插入一个节点 
bool InsertNextNode(LiStack& L, int e) {
	Linknode* s = (Linknode*)malloc(sizeof(Linknode));
	s->data = e;
	if (L == NULL) {
		L = s;	// 第一个节点 
		s->next = NULL;// 下一个初始化为空 ！！！ 
	}
	else {
		s->next = L;
		L = s;
	}
	return true;
}
// 头插法建立链表
LiStack LiStack_HeadInsert(LiStack& L) {
	int x = 1;
	scanf("%d", &x);
	while (x != 0) {
		InsertNextNode(L, x);
		scanf("%d", &x);
	}
	return L;
}
// 入栈
bool Push(LiStack& L, int e) {
	return InsertNextNode(L, e);
}
// 出栈
bool Pop(LiStack& L, int& e) {
	if (L == NULL) {
		return false;
	}
	Linknode* s = L;
	e = s->data;
	L = s->next;
	free(s);
	return true;
}
// 是否为空
bool LiStackEmpty(LiStack& L) {
	if (L == NULL) {
		return true;
	}
	return false;
}
// 打印
void PrintLiStack(LiStack& L) {
	if (L == NULL) {
		return;
	}
	Linknode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	LiStack L = NULL;
	b = LiStackEmpty(L);
	if (b) printf("栈为空\n");
	printf("输入值建立栈，输入0结束\n");
	LiStack_HeadInsert(L);
	PrintLiStack(L);
	Push(L, 11);
	Push(L, 13);
	Push(L, 16);
	printf("元素压入栈后：\n");
	PrintLiStack(L);
	b = Pop(L, e);
	printf("出栈元素：%d\n", e);
	PrintLiStack(L);
	b = Pop(L, e);
	printf("出栈元素：%d\n", e);
	PrintLiStack(L);
	
	return 0;
}

