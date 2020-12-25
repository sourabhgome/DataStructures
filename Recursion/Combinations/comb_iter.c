#include<stdio.h>

int main()
{
 int arr[]={0,1,2,3,4,5,6,7,8,9};
 int i,j,k;
 int size=sizeof(arr)/sizeof(int);
 for(i=0;i<size-2;i++)
  for(j=i+1;j<size-1;j++)
   for(k=j+1;k<size;k++)
    printf("[%d, %d, %d]\n",arr[i],arr[j],arr[k]);
 return 0;
}