#include<stdio.h>

int main()
{
 int x,y,z,i,n; 
 scanf("%d",&n);
 x=0;
 y=1;
 i=1;
 while(i<n)
 {
  z=x+y;
  x=y;
  y=z;
  i++;
 }
 printf("%d\n",y);
 return 0;
}