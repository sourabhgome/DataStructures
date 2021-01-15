#include<stdio.h>
#include<math.h>

double findDistance(int x1, int y1, int x2, int y2)
{
 return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main()
{
 double minDist1,minDist2,minDist;
 int i,j,l,r,x1,x2,y1,y2,x3,y3,x4,y4,size,temp,divider;
 int l_points[11][2];
 int r_points[11][2];
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
 divider=size/2;
 x1=points[0][0];
 y1=points[0][1];
 x2=points[1][0];
 y2=points[1][1];
 minDist1=findDistance(x1,y1,x2,y2);
 x3=points[0+divider][0];
 y3=points[0+divider][1];
 x4=points[1+divider][0];
 y4=points[1+divider][1];
 minDist2=findDistance(x3,y3,x4,y4);
 i=0;
 while(i<(divider-1))
 {
  j=i+1;
  while(j<divider)
  {
   temp=findDistance(points[i][0],points[i][1],points[j][0],points[j][1]);
   if(temp<minDist1)
   {
    minDist1=temp;
    x1=points[i][0];
    y1=points[i][1];
    x2=points[j][0];
    y2=points[j][1];
   }
   temp=findDistance(points[i+divider][0],points[i+divider][1],points[j+divider][0],points[j+divider][1]);
   if(temp<minDist2)
   {
    minDist2=temp;
    x3=points[i+divider][0];
    y3=points[i+divider][1];
    x4=points[j+divider][0];
    y4=points[j+divider][1];
   }
   j++;
  }
  i++;
 }
 if(minDist1<minDist2) minDist=minDist1;
 else 
 {
  x1=x3;
  y1=y3;
  x2=x4;
  y2=y4;
  minDist=minDist2;
 }
 i=0;
 l=0;
 r=0;
 while(i<size)
 {
  if(points[i][0]<points[divider][0] && points[i][0]>=points[divider][0]-minDist)
  {
   l_points[l][0]=points[i][0];
   l_points[l++][1]=points[i][1];
  }
  if(points[i][0]>=points[divider][0] && points[i][0]<=points[divider][0]+minDist)
  {
   r_points[r][0]=points[i][0];
   r_points[r++][1]=points[i][1];
  }
  i++;
 }
 i=0;
 while(i<l)
 {
  j=0;
  while(j<r)
  {
   minDist1=findDistance(l_points[i][0],l_points[i][1],r_points[j][0],r_points[j][1]);
   if(minDist1<minDist)
   {
    minDist=minDist1;
    x1=l_points[i][0];
    y1=l_points[i][1];
    x2=r_points[j][0];
    y2=r_points[j][1];
   }
   j++;
  }
  i++;
 }
 printf("Closest points : {%d, %d}, {%d, %d}\nDistance : %lf\n",x1,y1,x2,y2,minDist);
 return 0;
}