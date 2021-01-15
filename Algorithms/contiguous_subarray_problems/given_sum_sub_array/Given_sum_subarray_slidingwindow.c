#include<stdio.h>

int main()
{
 int arr[]={2,9,63,94,2,3,1};
 int sum=163;
 int size=sizeof(arr)/sizeof(arr[0]);
 int i,found=0,window_sum=0,start=0,end=-1;
 i=0;
 while(i<size && start<size && end<size)
 {
  if(window_sum>sum)
  {
   window_sum-=arr[start];
   start++;
  }
  else
  {
   window_sum+=arr[i];
   end=i;
   i++;
  }
  if(window_sum==sum)
  {
   found++;
   break;
  }
 }
 if(found && end>=start) printf("(%d, %d) -> %d\n",start,end,sum);
 else printf("No such subarray present\n");
 return 0;
}