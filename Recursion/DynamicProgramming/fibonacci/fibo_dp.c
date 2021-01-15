#include<stdio.h>
#include<stdlib.h>

int *arr;
int copies=0;

int fibo(int k)
{
 copies++;
 if(arr[k]!=-1) return arr[k];
 return arr[k]=fibo(k-1)+fibo(k-2);
}

int main()
{
 int k,i;
 scanf("%d",&k);
 arr=(int *)malloc(sizeof(int)*(k+1));
 arr[0]=0;
 arr[1]=1;
 for(i=2;i<=k;i++) arr[i]=-1;
 printf("%d\n",fibo(k));
 printf("Copies made : %d\n",copies);
 free(arr);
 return 0;
}