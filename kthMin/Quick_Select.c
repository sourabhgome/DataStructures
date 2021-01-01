#include<stdio.h>

int partitionPoint(int *arr, int lb, int ub)
{
 int e,f,temp;
 e=lb+1;
 f=ub;
 while(e<f)
 {
  while(e<=ub && arr[e]<=arr[lb]) e++;
  while(arr[f]>arr[lb]) f--;
  if(e<f)
  {
   temp=arr[e];
   arr[e]=arr[f];
   arr[f]=temp;
  }
  else
  {
   temp=arr[lb];
   arr[lb]=arr[f];
   arr[f]=temp;
  }
 }
 return f;
}

void quickSort(int *arr, int lb, int ub, int kthMin)
{
 int pp;
 if(lb>=ub || lb>kthMin || ub<kthMin) return;
 pp=partitionPoint(arr, lb, ub);
 if(pp==kthMin) return;
 quickSort(arr, lb, pp-1, kthMin);
 quickSort(arr, pp+1, ub, kthMin);
}

int main()
{
 int arr[]={36,56,94,3,1,6,74,85,63,22};
 int kthMin=4;
 for(int i=0;i<10;i++) printf("%d ",arr[i]);
 printf("\n\n");
 quickSort(arr, 0, 9, kthMin-1);
 for(int i=0;i<10;i++) printf("%d ",arr[i]);
 printf("\n\n");
 printf("%dth Minimum : %d\n",kthMin, arr[kthMin-1]);
}