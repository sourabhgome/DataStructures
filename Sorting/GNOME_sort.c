#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gnomeSort(int *arr, int size)
{
 int j,temp;
 j=1;
 while(j<size)
 {
  if(j==0) j++;
  if(arr[j]<arr[j-1])
  {
   arr[j]=arr[j]+arr[j-1];
   arr[j-1]=arr[j]-arr[j-1];
   arr[j]=arr[j]-arr[j-1];
   j--;
  }
  else
  {
   j++;
  }
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
 gnomeSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}