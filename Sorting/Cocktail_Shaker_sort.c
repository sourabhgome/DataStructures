#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

void cocktailShakerSort(int *arr, int lb, int ub)
{
 int e=ub-1,f;
 int i=lb,k;
 int swap_count;
 while(e>lb)
 {
  swap_count=0;
  f=i;
  while(f<=e)
  {
   if(arr[f]>arr[f+1])
   {
    swap(&arr[f],&arr[f+1]);
    swap_count++;
   }
   f++;
  }
  if(!swap_count) break;
  f=e;
  swap_count=0;
  while(f>i)
  {
   if(arr[f-1]>arr[f])
   {
    swap(&arr[f-1],&arr[f]);
    swap_count++;
   }
   f--;
  }
  if(!swap_count) break;
  i++;
  e--;
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
 cocktailShakerSort(arr, 0, req-1);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}