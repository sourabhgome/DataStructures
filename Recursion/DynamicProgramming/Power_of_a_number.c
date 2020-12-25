#include<stdio.h>

int dp[32]={0};
int copies=0;

int pwr(int num, int pow)
{
 copies++;
 if(pow==1) return num;
 if(dp[pow]!=0) return dp[pow];
 dp[pow]= (pow%2==0) ? pwr(num,pow/2)*pwr(num,pow/2) : num*pwr(num,pow/2)*pwr(num,pow/2);
 return dp[pow];
}

int power(int num, int pow)
{
 if(pow==0) return 1;
 pwr(num, pow);
}

int main()
{
 int num,pow,ans;
 printf("Enter number : ");
 scanf("%d",&num);
 printf("Enter power: ");
 scanf("%d",&pow);
 ans=power(num,pow);
 printf("%d^%d = %d\n",num,pow,ans);
 printf("%d copies created\n",copies);
 return 0;
}