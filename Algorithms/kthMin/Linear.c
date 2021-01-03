#include<stdio.h>

void swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

int kthMin(int *arr,int lb, int ub,int k)
{
 int i,j;
 i=lb;
 while(i<k)
 {
  j=i+1;
  while(j<=ub)
  {
   if(arr[i]>arr[j]) swap(&arr[i],&arr[j]);
   j++;
  }
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