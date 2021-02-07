#include<stdio.h>

int x[]={65,66,67,68,80,90};
int y[]={66,90,68,90};
int sizeX=6;
int sizeY=4;
int copies=0;
int _get_lcs_size(int e,int f)
{
 copies++;
 int rightSide, leftSide;
 if(e==sizeX || f==sizeY) return 0;
 if(x[e]==y[f]) return 1+_get_lcs_size(e+1,f+1);
 leftSide=_get_lcs_size(e+1,f);
 rightSide=_get_lcs_size(e,f+1);
 return (leftSide>rightSide) ? leftSide: rightSide;
}

int get_lcs_size()
{
 return _get_lcs_size(0,0);
}
int main()
{
 printf("LCS size = %d\n",get_lcs_size());
 printf("Copies made = %d\n",copies);
 return 0;
}