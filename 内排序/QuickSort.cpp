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


void QuickSort(SSTable &ST,int low,int high){
    int i,j,pivot;
    if(low < high){
        pivot = ST.elem[low];
        i = low;
        j = high;
        while(i<j){
            while(i<j && ST.elem[j]>=pivot) j--;
            ST.elem[i] = ST.elem[j];
            while(i<j && ST.elem[i]<=pivot) j++;
            ST.elem[j] = ST.elem[i];
        }
        ST.elem[i]=pivot;
    }
    QuickSort(ST,low,i-1);
    QuickSort(ST,i+1,high);
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
    QuickSort(ST,0,9);
    printf("排序后数组为：");
    ST_Print(ST);
    return 0; 
}