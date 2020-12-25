#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findPosition(int *arr, int si, int ei, int num)
{
 int mid;
 while(si<=ei)
 {
  mid=si+(ei-si)/2;
  if(arr[mid]==num)
  {
   si++;
   break;
  }
  if(arr[mid]<num) si=mid+1;
  else ei=mid-1;
 }
 return si;
}

void binaryInsertionSort(int *arr, int lb, int ub)
{
 int mind;
 int i=1,j,index;
 while(i<=ub)
 {
  mind=arr[i];
  index=findPosition(arr,lb,i-1,mind);
  j=i;
  while(j>=index)
  {
   arr[j]=arr[j-1];
   j--;
  }
  arr[index]=mind;
  i++;
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
 binaryInsertionSort(arr, 0, req-1);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}