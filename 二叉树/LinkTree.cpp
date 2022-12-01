#include <stdio.h>
#include <stdlib.h>

#define ELemType int

typedef struct BiTNode {
    ELemType data;
    struct BiTNode* lchild,* rchild;
}BiTNode, * BiTree;

// 插入根节点
bool InsertRootNode(BiTree& btree, ELemType e){
    btree = (BiTree)malloc(sizeof(BiTNode));
    btree->data = e;
    btree->lchild = NULL;
    btree->lchild = NULL;
    return true;
}

// 获取当前节点的左孩子
BiTree GetLeftC(BiTree p) {
    if (p == NULL || p->lchild == NULL){
        return NULL;
    }
    return p->lchild;
}

// 获取当前节点的右孩子 
BiTree GetRightC(BiTree p) {
    if (p == NULL || p->rchild == NULL){
        return NULL;
    }
    return p->rchild;
}

// 当前节点插入一个左节点
bool InsertLeftNode(BiTree& c, ELemType e){
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = e;
    c->lchild = p;
    return true;
}

// 当前节点插入一个右节点
bool InsertRightNode(BiTree& c, ELemType e){
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = e;
    c->rchild = p;
    return true;
}

// 判断二叉树是否为空
bool isEmpty(BiTree root){
    if(root == NULL){
        return true;
    }
    return false;
}

// 访问节点
void visit(BiTree p){
    if(p){
        printf("%d\t",p->data);
    }
}

// 先序遍历 NLR
void PreOrder(BiTree p){
    if(p){
        visit(p);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}


// 中序遍历 LNR
void InOrder(BiTree p){
    if(p){
        InOrder(p->lchild);
        visit(p);
        InOrder(p->rchild);
    }
}

// 后序遍历 LRN
void PostOrder(BiTree p){
    if(p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        visit(p);
    }
}


int main()
{
    // 构造二叉树
    BiTree root = NULL;
    InsertRootNode(root,1);

    BiTree cur = root;
    InsertLeftNode(cur,2);
    InsertRightNode(cur,3);

    cur = root->lchild;
    InsertLeftNode(cur,4);
    InsertRightNode(cur,5);

    cur = root->rchild;
    InsertLeftNode(cur,6);
    InsertRightNode(cur,7);

    cur = root->lchild->lchild;
    InsertLeftNode(cur,8);
    InsertRightNode(cur,9);

    cur = root->lchild->rchild;
    InsertLeftNode(cur,10);
    InsertRightNode(cur,11);

    cur = root->rchild->lchild;
    InsertLeftNode(cur,12);
    InsertRightNode(cur,13);

    cur = root->rchild->rchild;
    InsertLeftNode(cur,14);
    InsertRightNode(cur,15);

    // 获取左右节点
    cur = root;
    printf("根节点的左右节点是：%d\t%d\n",cur->lchild->data,cur->rchild->data);
    cur = root->lchild;
    printf("2的左右节点是：%d\t%d\n",cur->lchild->data,cur->rchild->data);
    cur = root->rchild->rchild;
    printf("7的左右节点是：%d\t%d\n",cur->lchild->data,cur->rchild->data);

    // 遍历二叉树
    printf("先序遍历:");
    PreOrder(root);
    printf("\n");
    printf("中序遍历:");
    InOrder(root);
    printf("\n");
    printf("后序遍历:");
    PostOrder(root);

    return 0;
}