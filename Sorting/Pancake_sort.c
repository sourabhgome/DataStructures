#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void flip(int *arr, int lb, int ub)
{
 int i=lb,j=ub;
 while(i<j)
 {
  arr[i]=arr[i]+arr[j];
  arr[j]=arr[i]-arr[j];
  arr[i]=arr[i]-arr[j];
  i++;
  j--;
 }
}

int findMaxIndex(int *arr, int lb, int ub)
{
 int max,maxIndex,i;
 max=arr[lb];
 maxIndex=lb;
 i=lb+1;
 while(i<=ub)
 {
  if(arr[i]>max)
  {
   max=arr[i];
   maxIndex=i;
  }
  i++;
 }
 return maxIndex;
}

void pancakeSort(int *arr, int size)
{
 int i,j,maxIndex;
 i=size-1;
 while(i>0)
 {
  maxIndex=findMaxIndex(arr,0,i);
  if(maxIndex==i)
  {
   i--;
   continue;
  }
  else
  {
   flip(arr,0,maxIndex);
   flip(arr,0,i);
  }
  i--;
 }
}


int main()
{
 int req,i;
 int *arr;
 printf("Enter requirement : ");
 scanf("%d",&req);
 arr=(int *)malloc(sizeof(int)*req);
 /*printf("Enter %d numbers : \n",req);
 for(i=0;i<req;i++) scanf("%d",&arr[i]);*/
 srand(time(0));
 for(i=0;i<req;i++) arr[i]=rand();
 printf("Before sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 pancakeSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}