#include<stdio.h>
#include<stdlib.h>

void matAdd(int **a, int **b, int **c, int i1, int j1, int i2, int j2, int size)
{
 int i,j,k,l;
 for(i=i1,k=i2;i<(i1+size);i++,k++) for(j=j1,l=j2;j<(j1+size);j++,l++) c[i][j]=a[i][j]+b[k][l];
}

void matSub(int **a, int **b, int **c, int i1, int j1, int i2, int j2, int size)
{
 int i,j,k,l;
 for(i=i1,k=i2;i<(i1+size);i++,k++) for(j=j1,l=j2;j<(j1+size);j++,l++)
 {
  c[i][j]=a[i][j]-b[k][l];
 }
}


void matMul(int **A, int **B, int **C, int i1, int j1, int i2, int j2, int size)
{
 int e,f,g,h,sum;
 int i,j,k,l,m,n,o,p;
 int m1,m2,m3,m4,m5,m6,m7;
 int **m_i, **m_j, **m_k, **m_l, **m_m, **m_n, **m_o, **m_p;
 int **m_m1, **m_m2, **m_m3, **m_m4, **m_m5, **m_m6, **m_m7;
 int **temp1,**temp2,**temp3;
 if(size==2)
 {
  i=A[i1][j1];
  j=A[i1][j1+1];
  k=A[i1+1][j1];
  l=A[i1+1][j1+1];
  m=B[i2][j2];
  n=B[i2][j2+1];
  o=B[i2+1][j2];
  p=B[i2+1][j2+1];
  m1=i*(n-p);
  m2=(i+j)*p;
  m3=(k+l)*m;
  m4=l*(o-m);
  m5=(i+l)*(m+p);
  m6=(j-l)*(o+p);
  m7=(i-k)*(m+n);
  C[i1][j2]=m5+m4-m2+m6;
  C[i1][j2+1]=m1+m2; 
  C[i1+1][j2]=m3+m4;
  C[i1+1][j2+1]=m1+m5-m3-m7;
 }
 else
 {
  temp1=(int **)malloc((size/2)*sizeof(int *));
  temp2=(int **)malloc((size/2)*sizeof(int *));
  temp3=(int **)malloc((size/2)*sizeof(int *));
  m_i=(int **)malloc((size/2)*sizeof(int *));
  m_j=(int **)malloc((size/2)*sizeof(int *));
  m_k=(int **)malloc((size/2)*sizeof(int *));
  m_l=(int **)malloc((size/2)*sizeof(int *));
  m_m=(int **)malloc((size/2)*sizeof(int *));
  m_n=(int **)malloc((size/2)*sizeof(int *));
  m_o=(int **)malloc((size/2)*sizeof(int *));
  m_p=(int **)malloc((size/2)*sizeof(int *));
  m_m1=(int **)malloc((size/2)*sizeof(int *));
  m_m2=(int **)malloc((size/2)*sizeof(int *));
  m_m3=(int **)malloc((size/2)*sizeof(int *));
  m_m4=(int **)malloc((size/2)*sizeof(int *));
  m_m5=(int **)malloc((size/2)*sizeof(int *));
  m_m6=(int **)malloc((size/2)*sizeof(int *));
  m_m7=(int **)malloc((size/2)*sizeof(int *));
  for(e=0;e<size/2;e++)
  {
   temp1[e]=(int *)malloc((size/2)*sizeof(int));
   temp2[e]=(int *)malloc((size/2)*sizeof(int));
   temp3[e]=(int *)malloc((size/2)*sizeof(int));
   m_i[e]=(int *)malloc((size/2)*sizeof(int));
   m_j[e]=(int *)malloc((size/2)*sizeof(int));
   m_k[e]=(int *)malloc((size/2)*sizeof(int));
   m_l[e]=(int *)malloc((size/2)*sizeof(int));
   m_m[e]=(int *)malloc((size/2)*sizeof(int));
   m_n[e]=(int *)malloc((size/2)*sizeof(int));
   m_o[e]=(int *)malloc((size/2)*sizeof(int));
   m_p[e]=(int *)malloc((size/2)*sizeof(int));
   m_m1[e]=(int *)malloc((size/2)*sizeof(int));
   m_m2[e]=(int *)malloc((size/2)*sizeof(int));
   m_m3[e]=(int *)malloc((size/2)*sizeof(int));
   m_m4[e]=(int *)malloc((size/2)*sizeof(int));
   m_m5[e]=(int *)malloc((size/2)*sizeof(int));
   m_m6[e]=(int *)malloc((size/2)*sizeof(int));
   m_m7[e]=(int *)malloc((size/2)*sizeof(int));
   for(f=0;f<size/2;f++)
   {
    temp1[e][f]=0;
    temp2[e][f]=0;
    temp3[e][f]=0;
    m_i[e][f]=0;
    m_j[e][f]=0;
    m_k[e][f]=0;
    m_l[e][f]=0;
    m_m[e][f]=0;
    m_n[e][f]=0;
    m_o[e][f]=0;
    m_p[e][f]=0;
    m_m1[e][f]=0;
    m_m2[e][f]=0;
    m_m3[e][f]=0;
    m_m4[e][f]=0;
    m_m5[e][f]=0;
    m_m6[e][f]=0;
    m_m7[e][f]=0;
   }
  }
  for(e=i1;e<i1+size/2;e++) for(f=j1;f<j1+size/2;f++) m_i[e%(size/2)][f%(size/2)]=A[e][f];
  for(e=i1;e<i1+size/2;e++) for(f=j1+size/2;f<j1+size;f++) m_j[e%(size/2)][f%(size/2)]=A[e][f];
  for(e=i1+size/2;e<i1+size;e++) for(f=j1;f<j1+size/2;f++) m_k[e%(size/2)][f%(size/2)]=A[e][f];
  for(e=i1+size/2;e<i1+size;e++) for(f=j1+size/2;f<j1+size;f++) m_l[e%(size/2)][f%(size/2)]=A[e][f]; 
  for(e=i2;e<i2+size/2;e++) for(f=j2;f<j2+size/2;f++) m_m[e%(size/2)][f%(size/2)]=B[e][f];
  for(e=i2;e<i2+size/2;e++) for(f=j2+size/2;f<j2+size;f++) m_n[e%(size/2)][f%(size/2)]=B[e][f];
  for(e=i2+size/2;e<i2+size;e++) for(f=j2;f<j2+size/2;f++) m_o[e%(size/2)][f%(size/2)]=B[e][f];
  for(e=i2+size/2;e<i2+size;e++) for(f=j2+size/2;f<j2+size;f++) m_p[e%(size/2)][f%(size/2)]=B[e][f];
  //m1=i*(n-p);
  matSub(m_n,m_p,temp1,0,0,0,0,size/2);
  matMul(m_i,temp1,m_m1,0,0,0,0,size/2);
  //m2=(i+j)*p;
  matAdd(m_i,m_j,temp1,0,0,0,0,size/2);
  matMul(temp1,m_p,m_m2,0,0,0,0,size/2);
  //m3=(k+l)*m;
  matAdd(m_k,m_l,temp1,0,0,0,0,size/2);
  matMul(temp1,m_m,m_m3,0,0,0,0,size/2);
  //m4=l*(o-m);
  matSub(m_o,m_m,temp1,0,0,0,0,size/2);
  matMul(m_l,temp1,m_m4,0,0,0,0,size/2);
  //m5=(i+l)*(m+p);
  matAdd(m_i,m_l,temp1,0,0,0,0,size/2);
  matAdd(m_m,m_p,temp2,0,0,0,0,size/2);
  matMul(temp1,temp2,m_m5,0,0,0,0,size/2);
  //m6=(j-l)*(o+p);
  matSub(m_j,m_l,temp1,0,0,0,0,size/2);
  matAdd(m_o,m_p,temp2,0,0,0,0,size/2);
  matMul(temp1,temp2,m_m6,0,0,0,0,size/2);
  //m7=(i-k)*(m+n);
  matSub(m_i,m_k,temp1,0,0,0,0,size/2);
  matAdd(m_m,m_n,temp2,0,0,0,0,size/2);
  matMul(temp1,temp2,m_m7,0,0,0,0,size/2);
  //C[i1][j2]=m5+m4-m2+m6;
  matAdd(m_m5,m_m4,temp1,0,0,0,0,size/2);
  matSub(temp1,m_m2,temp2,0,0,0,0,size/2);
  matAdd(temp2,m_m6,temp3,0,0,0,0,size/2);
  for(e=i1;e<i1+(size/2);e++)
  {
   for(f=j2;f<j2+(size/2);f++)
   {
    C[e][f]=temp3[e%(size/2)][f%(size/2)];
   }
  }
  //C[i1][j2+1]=m1+m2;
  matAdd(m_m1,m_m2,temp1,0,0,0,0,size/2);
  for(e=i1;e<i1+(size/2);e++)
  {
   for(f=j2+(size/2);f<j2+(size);f++)
   {
    C[e][f]=temp1[e%(size/2)][f%(size/2)];
   }
  }
  //C[i1+1][j2]=m3+m4;
  matAdd(m_m3,m_m4,temp1,0,0,0,0,size/2);
  for(e=i1+(size/2);e<i1+(size);e++)
  {
   for(f=j2;f<j2+(size/2);f++)
   {
    C[e][f]=temp1[e%(size/2)][f%(size/2)];
   }
  }
  //C[i1+1][j2+1]=m1+m5-m3-m7;
  matAdd(m_m1,m_m5,temp1,0,0,0,0,size/2);
  matSub(temp1,m_m3,temp2,0,0,0,0,size/2);
  matSub(temp2,m_m7,temp3,0,0,0,0,size/2);
  for(e=i1+(size/2);e<i1+(size);e++)
  {
   for(f=j2+(size/2);f<j2+(size);f++)
   {
    C[e][f]=temp3[e%(size/2)][f%(size/2)];
   }
  }
 } 
}

int main()
{
 int i,j,k;
 int size=8;
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