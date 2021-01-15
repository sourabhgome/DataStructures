#include<stdio.h>
#include<math.h>

double findDistance(int x1, int y1, int x2, int y2)
{
 return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main()
{
 double minDist,temp;
 int i,j,x1,x2,y1,y2;
 int points[10][2]={{0,2},{6,4},{9,6},{3,5},{1,3},{0,1},{2,9},{4,6},{5,7},{1,8}};
 minDist=findDistance(points[0][0],points[0][1],points[1][0],points[1][1]);
 x1=points[0][0];
 y1=points[0][1];
 x2=points[1][0];
 y2=points[1][1];
 i=0;
 while(i<9)
 {
  j=i+1;
  while(j<10)
  {
   temp=findDistance(points[i][0],points[i][1],points[j][0],points[j][1]);
   if(temp<minDist)
   {
    minDist=temp;
    x1=points[i][0];
    y1=points[i][1];
    x2=points[j][0];
    y2=points[j][1];
   }
   j++;
  }
  i++;
 }
 printf("Points : (%d, %d),(%d, %d)\nDistance : %lf\n",x1,y1,x2,y2,minDist);
 return 0;
}