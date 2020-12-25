#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

void stoogeSort(int *arr, int lb, int ub)
{
 int range=0;
 if(arr[lb]>arr[ub]) swap(&arr[lb],&arr[ub]);
 if(ub-lb+1>2)
 {
  range=(ub-lb+1)-((int)((ub-lb+1)/3));
  stoogeSort(arr,lb,lb+range-1);
  stoogeSort(arr,ub-range+1,ub);
  stoogeSort(arr,lb,lb+range-1);
 }
}


int main()
{
 int req,i;
 int *arr;
 printf("Enter requirement : ");
 scanf("%d",&req);
 arr=(int *)malloc(sizeof(int)*req);
 srand(time(0));
 for(i=0;i<req;i++) arr[i]=rand();
 printf("Before sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 stoogeSort(arr, 0, req-1);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 free(arr);
 return 0;
}