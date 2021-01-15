#include<stdio.h>

int main()
{
 int arr[]={10,-2,7,-6,-9,3};
 //int arr[]={-1,-1,50,-1,-1,-1};
 int size=6;
 int i,global_max,local_max,start,end;
 start=0;
 end=0;
 global_max=arr[0];
 local_max=arr[0];
 i=1;
 while(i<size)
 {
  local_max = arr[i]>local_max+arr[i] ? arr[i] : local_max+arr[i];
  if(local_max>global_max)
  {
   global_max=local_max;
   if(end==0)
   {
    end=i;
   }
   else
   {
    start=end;
    end=i;
   }
  }
  i++;
 }
 start = arr[end]==global_max ? end : start;
 printf("Start = %d, End = %d, Sum = %d\n",start,end,global_max);
 return 0;
}