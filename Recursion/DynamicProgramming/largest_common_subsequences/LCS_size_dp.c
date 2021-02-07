#include<stdio.h>

int x[]={1,2,3,4};
int y[]={5,2,3};
int sizeX=4;
int sizeY=3;
int copies=0;
int store[4][3];

int _get_lcs_size(int e,int f)
{
 copies++;
 int rightSide, leftSide;
 if(e==sizeX || f==sizeY) return 0;
 if(store[e][f]!=-1) return store[e][f];
 if(x[e]==y[f]) return store[e][f]=1+_get_lcs_size(e+1,f+1);
 leftSide=_get_lcs_size(e+1,f);
 rightSide=_get_lcs_size(e,f+1);
 return store[e][f]=(leftSide>rightSide) ? leftSide: rightSide;
}

int get_lcs_size()
{
 return _get_lcs_size(0,0);
}

int main()
{
 int i=0,j=0;
 for(i=0;i<sizeX;i++) for(j=0;j<sizeY;j++) store[i][j]=-1;
 printf("LCS size = %d\n",get_lcs_size());
 printf("Copies made = %d\n",copies);
 for(i=0;i<sizeX;i++)
 {
  for(j=0;j<sizeY;j++)
  {
   printf("%3d ",store[i][j]);
  }
  printf("\n");
 }
 return 0;
}