#include <stdio.h>
#include <stdlib.h>


#define ElemType int

typedef struct LNode {
    ElemType data;
    LNode * next;
}LNode, *LinkList;


// 头插法逆序建表(带头结点)
LinkList List_HeadInsert(LinkList& L, int n){
    LNode* s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(int i = 0;i < n; i++){
        scanf("%d",&x);
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}

// 尾插法顺序建表(带头结点)
LinkList List_TailInsert(LinkList &L, int n){
    LNode *s, *r = L;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    for(int i = 0; i < n; i++){
        s = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &x);
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

// 按位序查找元素
LinkList GetElem(LinkList L, int i){
    if(i < 0) {
        return NULL;
    }
    LNode* p = L;
    int j = 0;
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

// 按值e查找结点
LNode* LocateElem(LinkList L, ElemType e){
    LNode* p = L;
    while(p && p->data != e){
        p = p->next;
    }
    return p;
}

// 按值查找位序
int FindElem(LinkList L, ElemType e){
    LNode* p = L;
    int i = 0;
    while(p && p->data != e){
        p = p->next;
        i++;
    }
    return i;
}

bool ListInsert(LinkList& L, int i, ElemType e){
    LNode* s, * p = L;
    int j = 0;
    while(p && j < i-1){
        p = p-> next;
        j++;
    }
    if(p && j == i-1){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }else{
        return false;
    }
}

// 链表输出
void Print_LinkList(LinkList L){
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d\t",p->data);
    }
    printf("\n");
}

bool ListDelete(LinkList &L, int i, ElemType& e){
    LNode *p = L;
    int j = 0;
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    if(p && j == i-1){
        e = p->next->data;
        p->next = p->next->next;
        return true;
    }else{
        return false;
    }
}