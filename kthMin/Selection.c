#include<stdio.h>

int minIndex(int *arr, int lb, int ub)
{
 int minIndex=lb, min=arr[lb];
 for(int i=lb+1; i<=ub; i++)
  if(arr[i]<min)
  {
   min=arr[i];
   minIndex=i;
  }
 return minIndex;
}

int kthMin(int *arr,int lb, int ub,int k)
{
 int i=lb;
 int index;
 while(i<(lb+k))
 {
  index=minIndex(arr,i,ub);
  arr[index]=arr[index]+arr[i];
  arr[i]=arr[index]-arr[i];
  arr[index]=arr[index]-arr[i];
  i++;
 }
 return arr[k-1];
}

int main()
{
 int arr[]={21,16,45,89,11,47,23,2,6,4};
 int k=5;
 printf("%dth Min = %d",k,kthMin(arr,0,9,k));
}