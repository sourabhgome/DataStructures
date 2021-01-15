#include<stdio.h>

int main()
{
 int arr[]={12,3,92,-3,76,54,12,93,78};
 int count[]={1,1,1,1,1,1,1,1,1};
 int size=9;
 int e,f,max=1;
 f=1;
 while(f<size)
 {
  e=0;
  while(e<f)
  {
   if(arr[e]<arr[f])
   {
    if(count[e]+1>count[f])
    {
     count[f]=count[e]+1;
     if(count[f]>max) max=count[f];
    }
   }
   e++;
  }
  f++;
 }
 for(e=0;e<size;e++) printf("%3d ",arr[e]);
 printf("\n");
 for(e=0;e<size;e++) printf("%3d ",count[e]);
 printf("\n");
 printf("Length of LIS is : %d\n",max);
 return 0;
}