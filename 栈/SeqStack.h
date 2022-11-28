#include <stdio.h>

#define ElemType int
#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

// 初始化
void InisStack(SqStack &stack){
    stack.top = 0;
}

// 判断栈空
bool StackEmpty(SqStack stack){
    if(stack.top == 0){
        return true;
    }
    return false;
}

// 入栈
bool Push(SqStack &stack, ElemType e){
    if(stack.top == MaxSize){
        return false;
    }
    stack.data[stack.top++] = e;
    return true;
}

// 出栈
bool Pop(SqStack &stack,ElemType &e){
    if(stack.top == 0){
        return false;
    }
    e = stack.data[--stack.top];
    return true;
}


// 获取栈顶
bool GetTop(SqStack stack, ElemType &e){
    if(stack.top == 0) return false;
    e = stack.data[stack.top - 1];
    return true;
}


// 遍历
void Print_SqStack(SqStack stack){
    for(int i = 0; i < stack.top;i++){
        printf("%d\t",stack.data[i]);
    }
    printf("\n");
}


