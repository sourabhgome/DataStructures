#include<stdio.h>

/**
 * MAX HEAP is used to sort in ascending order
 * Formulas used:
   ri = int((index-1)/2)
   lci = (r1*2)+1
   rci = lci+1
   ri => root index
   ci => child index
 */

void swap(int *a, int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}

void createMaxHeap(int *arr, int lb, int ub)
{
 int ri,ci;
 int y=1;
 while(y<=ub)
 {
  ci=y;
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
  y++;
 }
}


void adjustHeap(int *arr, int lb, int ub)
{
 int ri=lb;
 int lci,rci,swi=0;
 while(ri<ub)
 {
  lci=(ri*2)+1;
  rci=lci+1;
  if(lci>ub) break;
  if(rci>ub)
  {
   swi=lci;
  }
  else swi=(arr[rci]>arr[lci])?rci:lci;
  if(arr[swi]>arr[ri])
  {
   swap(&arr[ri],&arr[swi]);
   ri=swi;
  }
  else break;
 }
}

void heapSort(int *arr, int lb, int ub)
{
 createMaxHeap(arr,lb,ub);
 int y=ub;
 while(y>lb)
 {
  swap(&arr[lb],&arr[y]);
  y--;
  adjustHeap(arr,lb,y);
 }
}


int main()
{
 int arr[]={16,52,73,84,9,56,120,60,12,35};
 heapSort(arr,0,9);
 for(int i=0;i<10;i++) printf("%d ",arr[i]);
 return 0;
}