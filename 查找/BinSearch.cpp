/* 
折半查找（二分查找）
仅适用于有序的顺序表 
*/

#include <stdio.h>

#define ElemType int

typedef struct{
    ElemType *elem;
    int Tablelen;
}SSTable;

// 升序排列
int Binary_Search(SSTable L, ElemType key){
    int low=0,high=L.Tablelen-1,mid;
    while(low < high){
        mid = (low + high) / 2;
        if(L.elem[mid] == key){
            return mid;
        }else if(L.elem[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}