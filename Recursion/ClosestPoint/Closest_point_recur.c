#include<stdio.h>
#include<math.h>

double findDistance(int x1, int y1, int x2, int y2)
{
 return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double closestPoint(int arr[22][2], int lb, int ub,double *minDist)
{
 int mid,flag1=0,flag2=0;
 double temp1,temp2;
 if(((ub-lb)+1)==2)
 {
  return findDistance(arr[lb][0],arr[lb][1],arr[ub][0],arr[ub][1]);
 }
 else
 {
  mid=lb+(((ub-lb)+1)/2);
  if(((ub-lb)+1)%2==1)
  {
   if((mid-lb)+1>=2)
   {
    temp1=closestPoint(arr,lb,mid,minDist);
    flag1++;
   }
   if((ub-mid)+1>=2)
   {
    temp2=closestPoint(arr,mid,ub,minDist);
    flag2++;
   }
  }
  else
  {
   if((mid-1-lb)+1>=2)
   {
    temp1=closestPoint(arr,lb,mid-1,minDist);
    flag1++;
   }
   if((ub-mid)+1>=2)
   {
    temp2=closestPoint(arr,mid,ub,minDist);
    flag2++;
   }
  }
  if(flag1==0 && flag2==0) return *minDist;
  else if(flag1==0 && flag2!=0)
  {
   *minDist=temp2;
   return *minDist;
  }
  else if(flag2==0 && flag1!=0)
  {
   *minDist=temp1;
   return *minDist;
  }
  if(temp1<=temp2) *minDist=temp1;
  else *minDist=temp2;
  return *minDist;
 }
}

int main()
{
 double minDist1,minDist2;
 int i,j,x1,x2,y1,y2,size,temp;
 int points[22][2]={{1,3},{1,6},{2,3},{2,7},{1,8},{3,5},{3,9},{4,8},{4,10},{5,7},{5,10},{6,6},{6,9},{7,4},{7,10},{8,3},{8,6},{9,4},{10,7},{10,10},{11,9},{11,11}};
 //sort wrt to x
 i=0;
 size=22;
 while(i<size-1)
 {
  j=i+1;
  while(j<size)
  {
   if(points[i][0]>points[j][0])
   {
    temp=points[i][0];
    points[i][0]=points[j][0];
    points[j][0]=temp;
    temp=points[i][1];
    points[i][1]=points[j][1];
    points[j][1]=temp;
   }
   j++;
  }
  i++;
 }
 x1=points[0][0];
 y1=points[0][1];
 x2=points[1][0];
 y2=points[1][1];
 minDist1=findDistance(x1,y1,x2,y2);
 minDist2=closestPoint(points,0,21,&minDist1);
 printf("Min Dist : %lf\n",minDist1);
 return 0;
}