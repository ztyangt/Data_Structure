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


/* 部分有序到全局有序 
① 按照增量d分成子序列
② 对子序列排序（直接插入排序）、
③ 缩小增量，重复以上步骤，直至增量为1
*/
void ShellSort(SSTable &ST){
    int i,j,temp,d=ST.TableLen/2;
    for(d=ST.TableLen/2;d>=1;d=d/2){
        for(i=d;i<=ST.TableLen;i++){
            if(ST.elem[i]<ST.elem[i-d]){
                temp = ST.elem[i];
                for(j=i-d;j>=0 && temp<ST.elem[j];j-=d){
                    ST.elem[i]=ST.elem[j];
                }
                ST.elem[d+j] = temp;
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
    ShellSort(ST);
    printf("排序后数组为：");
    ST_Print(ST);
    return 0; 
}