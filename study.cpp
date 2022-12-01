#include <stdio.h> 
#include <stdlib.h>
#include <cmath>

typedef struct BiTNode {
	int data; 		// 数据域 
	struct BiTNode* lchild, * rchild;// 左右孩子指针 
	struct BiTNode* parent;// 父亲结点 
}BiTNode, * BiTree;
// 插入根结点 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL;
	return true;
}
// 1.当前p结点的左孩子 
BiTNode* GetLeftC(BiTree& p) {
	if (p == NULL || p->lchild == NULL) {
		return NULL;
	}
	return p->lchild;
}
// 2.当前p结点的右孩子  
BiTNode* GetRightC(BiTree& p) {
	if (p == NULL || p->rchild == NULL) {
		return NULL;
	}
	return p->rchild;
}
// 3.当前p结点的父亲  
BiTNode* GetParent(BiTree& p) {
	if (p == NULL || p->parent == NULL) {
		return NULL;
	}
	return p->parent;
}
// 当前结点c插入一个左结点
bool InsertTreeLeftNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->lchild = p;
	return true;
}
// 当前c结点插入一个右结点
bool InsertTreeRightNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->rchild = p;
	return true;
}
// 删除c节点 : 要删除c结点的左右结点，并且释放空间
bool DeleteTreeNode(BiTree& c) {
	BiTNode* curp = c;
	BiTNode* p;
	while (curp != NULL) { // 扫描左结点
		p = curp->lchild;
		if (p != NULL) {
			curp = p->lchild;// 当前结点被删除之前获取当前结点的左结点，以便下次循环
		}
		else {
			curp = NULL;
		}
		free(p);
	}
	curp = c;// 当前节点开始扫描右节点 
	while (curp != NULL) {
		p = curp->rchild;
		if (p != NULL) {
			curp = p->rchild;
		}
		else {
			curp = NULL;
		}
		free(p);
	}
	// 注意此结点的父节点的左或者右结点置空。 
	if (c->parent->lchild == c) {
		c->parent->lchild = NULL;
	}
	else {
		c->parent->rchild = NULL;
	}
	free(c);// 释放自己 
	return true;
}
// 判断二叉树是否为空
bool Empty(BiTree& root) {
	if (root == NULL) {
		return true;
	}
	return false;
}


// 辅助方法：中序遍历 
void InOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->data);
		InOrder(p->rchild);
	}
}
int main() {
	// 手动构造二叉树 
	BiTree root = NULL;
	InsertRootNode(root, 1);
	BiTree cur = root;// cur = 1
	InsertTreeLeftNode(cur, 2);
	InsertTreeRightNode(cur, 3);

	cur = root->lchild;// cur = 2
	InsertTreeLeftNode(cur, 4);
	InsertTreeRightNode(cur, 5);

	cur = root->rchild;// cur = 3
	InsertTreeLeftNode(cur, 6);
	InsertTreeRightNode(cur, 7);

	cur = root->lchild->lchild;// cur = 4
	InsertTreeLeftNode(cur, 8);
	InsertTreeRightNode(cur, 9);

	cur = root->lchild->rchild;// cur = 5
	InsertTreeLeftNode(cur, 10);
	InsertTreeRightNode(cur, 11);

	cur = root->rchild->lchild;// cur = 6
	InsertTreeLeftNode(cur, 12);
	InsertTreeRightNode(cur, 13);

	cur = root->rchild->rchild;// cur = 7
	InsertTreeLeftNode(cur, 14);
	InsertTreeRightNode(cur, 15);

	// 测试获取左右结点 父结点方法
	cur = GetLeftC(root->lchild->lchild);
	if (cur != NULL) {
		printf("结点%d的左结点是%d\n", root->lchild->lchild->data, cur->data);
	}
	cur = GetRightC(root->rchild->rchild);
	if (cur != NULL) {
		printf("结点%d的右结点是%d\n", root->rchild->rchild->data, cur->data);
	}
	cur = GetParent(root->lchild->rchild);
	if (cur != NULL) {
		printf("结点%d的父亲结点是%d\n", root->lchild->rchild->data, cur->data);
	}
	printf("中序遍历：\n", root->lchild->data);
	InOrder(root);
	// 删除节点
	printf("\n删除结点%d后中序遍历：\n", root->lchild->data);
	DeleteTreeNode(root->lchild);
	InOrder(root);
	printf("\n");
}

