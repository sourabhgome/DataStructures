#include<stdio.h>

void swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

void createMaxHeap(int *arr, int lb, int ub)
{
 int ri,ci;
 int i=1;
 while(i<=ub)
 {
  ci=i;
  while(ci>lb)
  {
   ri=(ci-1)/2;
   if(arr[ci]>arr[ri])
   {
    swap(&arr[ci],&arr[ri]);
    ci=ri;
   }
   else break;
  }
  i++;
 }
}

void adjustMaxHeap(int *arr, int lb, int ub)
{
 int ri=lb;
 int lci,rci,swi=0;
 while(ri<ub)
 {
  lci=(ri*2)+1;
  rci=lci+1;
  if(lci>ub) break;
  if(rci>ub) swi=lci;
  else swi=(arr[rci]>arr[lci])?rci:lci;
  if(arr[swi]>arr[ri])
  {
   swap(&arr[ri],&arr[swi]);
   ri=swi;
  }
  else break;
 }
}

int kthMin(int *arr, int lb, int ub, int k)
{
 createMaxHeap(arr,0,k-1);
 int i=k;
 while(i<=ub)
 {
  if(arr[0]>arr[i]) swap(&arr[0],&arr[i]);
  adjustMaxHeap(arr,0,k-1);
  i++;
 }
 return arr[0];
}

int main()
{
 int arr[]={21,16,45,89,11,47,23,2,6,4};
 int k=4;
 printf("%dth Min = %d",k,kthMin(arr,0,9,k));
}