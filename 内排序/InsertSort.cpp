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

// 直接插入排序
void InsertSort(SSTable &ST){
    int i,j,temp;
    for(i=1;i<ST.TableLen;i++){
        if(ST.elem[i] < ST.elem[i-1]){
            temp = ST.elem[i];
            for(j=i-1;j>=0 && ST.elem[j]>temp;--j){
                ST.elem[j+1]=ST.elem[j];
            }
            ST.elem[j+1] = temp;
        }
    }
} 

// 折半插入排序
void BinartInsert(SSTable &ST){
    int i,j,low,mid,high,temp;
    for(i=1;i<ST.TableLen;i++){
        low = 0;
        high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(ST.elem[i] < ST.elem[mid]) high = mid-1;
            else low = mid + 1;
        }
        temp = ST.elem[i];
        for(j=i-1;j>=high+1;--j){
            ST.elem[j+1] = ST.elem[j];
        }
        ST.elem[high+1] = temp;
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
    // InsertSort(ST);
    BinartInsert(ST);
    printf("排序后数组为：");
    ST_Print(ST);
    return 0; 
}