#include <stdio.h>

// 牺牲一个存储单元判断堆空与队满

#define MaxSize 50
#define ElemType int

typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

// 队列初始化
void InitQueue(SqQueue& Q){
    Q.front = Q.rear = 0;
}

// 判断队列空
bool QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

// 入队 - 只能从队尾插入
bool EnQueue(SqQueue &Q, ElemType e){
    if((Q.rear + 1) % MaxSize == Q.front){
        return false; //栈满
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

int GetSize(SqQueue& Q) {
	return (Q.rear - Q.front + MaxSize) % MaxSize;
}

// 遍历
void PrintSqQueue(SqQueue Q){
    for(int i = Q.front;i != Q.rear;i=(i+1) % MaxSize) {
        printf("%d\t",Q.data[i]);
    }
    printf("\n");
}

int main()
{
    SqQueue Q;
	InitQueue(Q);
    if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 3);
	printf("元素3入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 5);
	printf("元素5入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);
    return 0;
}

