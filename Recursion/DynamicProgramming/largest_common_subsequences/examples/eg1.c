#include<stdio.h>
#include<stdlib.h>
int main()
{
 int arr[]={12,3,92,-3,76,54,12,93,78};
 int size=sizeof(arr)/sizeof(arr[0]);
 int *record=(int *)calloc(size,sizeof(int));
 int i,j,start,flag=0;
 for(i=0;i<size-1;i++)
 {
  if(record[i]!=0) continue;
  start=arr[i];
  flag=0;
  j=i+1;
  while(j<size)
  {
   if(arr[j]>start)
   {
    printf("%d ",start);
    start=arr[j];
    record[j]++;
    flag++;
   }
   j++;
  }
  if(flag) printf("%d\n",start);
 }
 free(record);
 return 0;
}