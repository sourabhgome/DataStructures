#include<stdio.h>

int calcHcf(int *arr, int size)
{
 for(int i=0;i<3;i++) printf("%d ",arr[i]);
 printf("\n");
 int p,q;
 p=arr[size-2];
 q=arr[size-1];
 if(size==1) return arr[0];
 if(q==0)
 {
  return calcHcf(arr, size-1);
 }
 if(p<q)
 {
  arr[size-1]=q%p;
  arr[size-2]=p;
 }
 else
 {
  arr[size-1]=p%q;
  arr[size-2]=q;
 }
 return calcHcf(arr,size);
}

int hcf(int *arr, int size)
{
 int temp[size];
 int i;
 for(i=0;i<size;i++) temp[i]=arr[i];
 return calcHcf(temp,size);
}

int main()
{
 int arr[]={56,96,34,52};
 printf("Hcf : %d\n",hcf(arr,4));
 return 0;
}