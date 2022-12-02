#include <stdio.h>

#define ElemType int



typedef struct {
    ElemType *elem; //动态数组基址
    int Tablelen;
}SSTable;
 
int Search_Seq (SSTable ST, ElemType key) {
    int i ;
    for(i=0;i<ST.Tablelen && ST.elem[i]!=key;++i);
    return i==ST.Tablelen ? -1 : i+1;
}

/* 顺序查找
数据从下标1开始
下标0存储查找关键字（哨兵）
从后往前找，查找成功返回i，失败返回0  
*/
int Search_Seq2(SSTable ST,ElemType e){
    ST.elem[0] = e;
    int i;
    for(i=ST.Tablelen;ST.elem[i]!=e;--i);
    return i;
}

void InitArr(ElemType *arr,int length){
    for(int i=0;i<length;i++){
        arr[i] = (i+1)*10;
    }
}

void PrintArr(ElemType *arr,int length){
    for(int i=0;i<length;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){
    ElemType arr[10];
    int p;
    SSTable table;
    InitArr(arr,10);
    PrintArr(arr,10);
    table.elem = arr;
    table.Tablelen = 10;
    p = Search_Seq2(table,70);
    printf("70的位置为：%d\n",p);
    return 0;
 }

/* 
 查找成功: ASL = (n+1)/2
 查找失败: ASL = n+1
*/