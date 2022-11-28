#include <stdio.h>
#include <stdlib.h>

#define ElemType int

// 不带头节点
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;   
}LinkNode, *LinkStack;



// 入栈
bool Push(LinkStack &stack, ElemType e){
    LinkStack s = (LinkStack)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = stack;
    stack = s;
    return true;
}

