#include<stdio.h>
#include<stdlib.h>

void matAdd(int **a, int **b, int **c, int i1, int j1, int i2, int j2, int size)
{
 int i,j,k,l;
 for(i=i1,k=i2;i<(i1+size);i++,k++) for(j=j1,l=j2;j<(j1+size);j++,l++) c[i][j]=a[i][j]+b[k][l];
}

void matMul(int **a, int **b, int **c, int i1, int j1, int i2, int j2, int size)
{
 int e,f,g,h,sum;
 int **temp;
 if(size==2)
 {
  for(e=i1;e<(i1+size);e++)
  {
   for(f=j2;f<(j2+size);f++)
   {
    sum=0;
    for(g=j1,h=i2; g<(j1+size); g++,h++)
    {
     sum=sum+(a[e][g]*b[h][f]);
    }
    c[e][f]=sum;
   }
  }
 }
 else
 {
  temp=(int **)malloc(size*sizeof(int *));
  for(e=0;e<size;e++)
  {
   temp[e]=(int *)malloc(size*sizeof(int));
   for(f=0;f<size;f++)
   {
    temp[e][f]=0;
   }
  }
  for(e=i1;e<(i1+size);e+=(size/2))
  {
   for(f=j2;f<(j2+size);f+=(size/2))
   {
    for(g=j1,h=i2; g<(j1+size); g+=(size/2),h+=(size/2))
    {
     matMul(a,b,temp,e,g,h,f,size/2);
     matAdd(temp,c,c,e,f,e,f,size/2);
    }
   }
  }
 } 
}

int main()
{
 int i,j,k;
 int size=4;
 int **a=(int **)malloc(size*sizeof(int *));
 int **b=(int **)malloc(size*sizeof(int *));
 int **c=(int **)malloc(size*sizeof(int *));
 for(i=0;i<size;i++)
 {
  a[i]=(int *)malloc(size*sizeof(int));
  b[i]=(int *)malloc(size*sizeof(int));
  c[i]=(int *)malloc(size*sizeof(int));
 }
 k=1;
 for(i=0;i<size;i++)
 {
  for(j=0;j<size;j++)
  {
   a[i][j]=k;
   b[i][j]=k*10;
   c[i][j]=0;
   k++;
  }
 }
 matMul(a,b,c,0,0,0,0,size);
 for(i=0;i<(size);i++)
 {
  for(j=0;j<(size);j++)
  {
   printf("%5d ",c[i][j]);
  }
  printf("\n");
 }
 return 0;
}