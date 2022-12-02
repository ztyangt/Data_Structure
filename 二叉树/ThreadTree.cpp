#include <stdio.h>

#define ElemType int

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, * ThreadTree;

// 中序遍历二叉树，一边遍历二叉树，一遍线索化 
// 初始化 *pre=NULL
void Inthread(ThreadTree T, ThreadTree &pre){
    if(T != NULL){
        Inthread(T->lchild,pre);
        visit(T, pre);
        Inthread(T->rchild,pre);
    }
}

void visit(ThreadTree q,ThreadTree &pre){
    if(q->lchild == NULL){
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}