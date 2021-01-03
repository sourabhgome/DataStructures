#include<stdio.h>

void swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

int kthMin(int *arr,int lb, int ub,int k)
{
 int i,j,x;
 i=ub-1;
 x=0;
 while(x<k)
 {
  j=lb;
  while(j<=i)
  {
   if(arr[j]<arr[j+1]) swap(&arr[j],&arr[j+1]);
   j++;
  }
  for(int z=0; z<10; z++) printf("%d ",arr[z]);
  printf("\n");
  i--;
  x++;
 }
 return arr[ub-(lb+k)+1];
}

int main()
{
 int arr[]={21,16,45,89,11,47,23,2,6,4};
 int k=5;
 printf("%dth Min = %d",k,kthMin(arr,0,9,k));
}