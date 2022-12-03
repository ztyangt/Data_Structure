#include <stdio.h>
#include <stdlib.h>

#define ElemType int

/* 二叉排序树查找
左子树节点值 < 根节点值 < 右节点值
若树非空，目标值与根节点值比较；
若相等，则查找成功 
若小于根节点，则在左子树查找，否则在右子树查找
查找成功，返回节点指针，查找失败返回NULL
*/


typedef struct BSTNode{
    ElemType key;
    BSTNode *lchild,*rchild;
}BSTNode,*BSTree;


// 非递归实现查找 空间复杂度 O(1)
BSTNode *BST_Search(BSTree T,ElemType key){
    while(T!=NULL && T->key!=key){
        if(key < T->key){
            T = T->lchild;
        }else{
            T = T->rchild;
        }
    }
    return T;
}

// 递归实现,空间复杂度 O(h)
BSTNode *BSTSearch(BSTree T, ElemType key){
    if(T==NULL || T->key == key){
        return T;
    }
    if(key < T->key) return BSTSearch(T->lchild,key);
    else return BSTSearch(T->rchild,key);
}

/* 二叉排序树的插入
① 若原二叉树为空，则插入到节点；
② 若关键字小于根节点值，则插入到左子树；
③若关键字大于根节点值，则插入到右子树；
*/

// 递归实现插入 最坏空间复杂度 O(h)
int BST_Insert(BSTree &T,ElemType key){
    if(T == NULL) {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(T->key == key){
        return 0;                           //树中存在相同节点值，插入失败
    }else if(key < T->key) {
        return BST_Insert(T->lchild,key);
    }else {
        return BST_Insert(T->rchild,key);
    }
}

/* 
二叉排序树的构造 
按照 ElemType[]中的关键字序列建立二叉树
*/

void Create_BST(BSTree &T,ElemType data[],int n){
    T = NULL;
    int i = 0;
    while(i < n){
        BST_Insert(T,data[i++]);
    }
}

/* 
二叉排序树的删除
① 若被删除节点是叶子节点，则直接删除
② 若节点z只有一棵左子树或右子树，则让z的子树成为z父节点的子树，替代z的位置
③ 若节点z有左右两棵子树，则让z的直接后继（或直接前驱）替代z,然后从二叉排序树中删除这个直接后继（或直接前驱）
*/
