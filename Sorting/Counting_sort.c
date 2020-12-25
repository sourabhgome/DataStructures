#include<stdio.h>
#include<stdlib.h>

void countingSort(int *arr, int lb, int ub)
{
 int largest,i,j,k;
 int *tempArr;
 largest=arr[lb];
 for(i=lb+1;i<=ub;i++) if(arr[i]>largest) largest=arr[i];
 tempArr=(int *)malloc(sizeof(int)*(largest+1));
 for(i=0;i<largest+1;i++) tempArr[i]=0;
 for(i=lb;i<=ub;i++) tempArr[arr[i]]++;
 k=0;
 for(i=0;i<largest+1;i++)
 {
  j=0;
  while(j<tempArr[i])
  {
   arr[k++]=i;
   j++;
  }
 }
}

int main()
{
 int req,i;
 int *arr;
 printf("Enter requirement : ");
 scanf("%d",&req);
 arr=(int *)malloc(sizeof(int)*req);
 printf("Enter %d numbers : \n",req);
 for(i=0;i<req;i++) scanf("%d",&arr[i]);
 printf("Before sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 countingSort(arr, 0, req-1);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}