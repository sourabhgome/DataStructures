#include<stdio.h>
#include<stdlib.h>

void printAscending(int *arr, int *record, int *subset, int size, int start, int subset_index)
{
 int i;
 if(start==size) 
 {
  for(i=0;i<subset_index;i++) printf("%d ",subset[i]);
  printf("\n");
  return;
 }
 if(subset_index==0)
 {
  for(i=0;i<size-1;i++)
  {
   if(record[i]!=0) continue;
   subset[0]=arr[i];
   printAscending(arr,record,subset,size,start+i,subset_index+1);
  }
 }
 else
 {
  if(arr[start]>subset[subset_index-1])
  {
   subset[subset_index]=arr[start];
   record[start]++;
   printAscending(arr,record,subset,size,start+1,subset_index+1);
  }
  else
  {
   printAscending(arr,record,subset,size,start+1,subset_index);
  }
 }
}

int main()
{
 int arr[]={12,3,92,-3,76,54,12,93,78};
 int size=sizeof(arr)/sizeof(arr[0]);
 int *record=(int *)calloc(size,sizeof(int));
 int *subset=(int *)calloc(size,sizeof(int));
 printAscending(arr,record,subset,size,0,0);
 free(record);
 return 0;
}