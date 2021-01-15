#include<stdio.h>

int main()
{
 //int arr[]={2,6,9,4,1,6};
 int arr[]={-10, 0, 2, -2, -20, 10};
 int sum=-22;
 int size=6;
 int i,j,temp,found=0;
 i=0;
 while(i<size)
 {
  temp=0;
  j=i;
  while(j<size)
  {
   temp+=arr[j];
   if(temp==sum)
   {
    found++;
    break;
   }
   j++;
  }
  if(found) break;
  i++;
 }
 if(found) printf("(%d, %d) -> %d\n",i,j,sum);
 else printf("No such subarray present\n");
 return 0;
}