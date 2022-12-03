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


void SelectSort(SSTable &ST){
  int i,j,min,temp;
  for(i=0;i<ST.TableLen-1;i++){
    min = i;
    for(j=i+1;j<ST.TableLen;j++){
        if(ST.elem[j] < ST.elem[min]) min=j;
    }
    if(i!=min){
        temp = ST.elem[i];
        ST.elem[i]=ST.elem[min];
        ST.elem[min] = temp;
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
    SelectSort(ST);
    printf("排序后数组为：");
    ST_Print(ST);
    return 0; 
}