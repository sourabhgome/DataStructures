#include<stdio.h>

int hcf(int div, int rem)
{
 if(rem==0) return div;
 return hcf(rem ,div%rem);
}

int main()
{
 int num1=75;
 int num2=50;
 printf("HCF of %d and %d is %d\n",num1,num2,hcf(num1,num2));
 return 0;
}