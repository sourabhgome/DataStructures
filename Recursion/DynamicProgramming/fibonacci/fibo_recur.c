#include<stdio.h>

int copies=0;

int fibo(int k)
{
 copies++;
 if(k<=1) return k;
 return fibo(k-1)+fibo(k-2);
}

int main()
{
 int k;
 scanf("%d",&k);
 printf("%d\n",fibo(k));
 printf("Copies made : %d\n",copies);
 return 0;
}