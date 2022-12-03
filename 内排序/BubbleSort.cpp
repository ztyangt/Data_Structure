#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int ElemType;

typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;

void InitSST(SSTable &ST,int len){
    ST.TableLen = len;
    ST.elem = (ElemType *)malloc(sizeof(SSTable)*ST.TableLen);
    srand(time(NULL));
    for(int i=0;i<ST.TableLen;i++){
        ST.elem[i] = rand()%100;
    }
}


void BubbleSort(SSTable &ST){
    int i,j,temp;
    for(i=0;i<ST.TableLen-1;i++){
        for(j=ST.TableLen-1;j>i;j--){
            if(ST.elem[j]<ST.elem[j-1]){
                temp = ST.elem[j-1];
                ST.elem[j-1] = ST.elem[j];
                ST.elem[j] = temp;
            }
        }
    }
} 



void ST_Print(SSTable ST){
    for(int i = 0;i<ST.TableLen;i++){
        printf("%d\t",ST.elem[i]);
    }
    printf("\n");
}

int main()
{
    SSTable ST;
    InitSST(ST,10);
    printf("排序前数组为：");
    ST_Print(ST);
    BubbleSort(ST);
    printf("排序后数组为：");
    ST_Print(ST);
    return 0; 
}