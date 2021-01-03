#include<stdio.h>

void swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

int kthMin(int *arr, int lb, int ub, int k)
{
 int *ptr=&arr[lb+k-1];
 int i,j,swapCount=1;
 while(swapCount)
 {
  swapCount=0;
  i=lb;
  while(i<k-1)
  {
   if(*ptr<arr[i])
   {
    swap(ptr,&arr[i]);
    swapCount++;
   }
   i++;
  }
  j=k;
  while(j<=ub)
  {
   if(*ptr>arr[j])
   {
    swap(ptr,&arr[j]);
    swapCount++;
    break;
   }
   j++;
  }
 }
 return *ptr;
}

int main()
{
 int arr[]={21,16,45,89,11,47,23,2,6,4};
 int k=5;
 printf("%dth Min = %d",k,kthMin(arr,0,9,k));
}