#include<stdio.h>

int x[]={65,66,67,68,80,90};
int y[]={66,90,68,90};
int sizeX=6;
int sizeY=4;
int copies=0;
int store[7][5];

int main()
{
 int i=0,j=0;
 int max=0;
 for(i=0;i<=sizeX;i++) store[i][0]=0;
 for(j=0;j<=sizeY;j++) store[0][j]=0;

 for(i=1;i<=sizeX;i++)
 {
  for(j=1;j<=sizeX;j++)
  {
   if(x[i-1]==y[j-1])
   {
    store[i][j]=store[i-1][j-1]+1;
    if(store[i][j]>max) max=store[i][j];
   }
   else
   {
    store[i][j] = (store[i-1][j]>store[i][j-1]) ? store[i-1][j] : store[i][j-1];
   }
  }
 }

 printf("LCS size = %d\n",max);
 for(i=0;i<=sizeX;i++)
 {
  for(j=0;j<=sizeY;j++)
  {
   printf("%3d ",store[i][j]);
  }
  printf("\n");
 }
 return 0;
}