#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void oddEvenSort(int *arr, int size)
{
 int i=0;
 int flag;
 while(1)
 {
  flag=0;
  //Odd indexes
  i=1;
  while(i<size-1)
  {
   if(arr[i]>arr[i+1])
   {
    arr[i]=arr[i]+arr[i+1];
    arr[i+1]=arr[i]-arr[i+1];
    arr[i]=arr[i]-arr[i+1];
    flag=1;
   }
   i+=2;
  }
  //Even indexes
  i=0;
  while(i<size-1)
  {
   if(arr[i]>arr[i+1])
   {
    arr[i]=arr[i]+arr[i+1];
    arr[i+1]=arr[i]-arr[i+1];
    arr[i]=arr[i]-arr[i+1];
    flag=1;
   }
   i+=2;
  }
  if(flag==0) break;
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
 oddEvenSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}