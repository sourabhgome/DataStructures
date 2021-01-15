// O(n^3) -> Bruteforce method to find maximum sum of a contigous subarray in a array

#include<stdio.h>

int main()
{
 int arr[]={10,-2,7,-6,-9,3};
 int size=6;
 int e,f,g,maxSum,sum;
 maxSum=0;
 e=0;
 while(e<size)
 {
  f=e;
  while(f<size)
  {
   sum=0;
   g=e;
   while(g<=f)
   {
    sum=sum+arr[g];
    g++;
   }
   if(sum>maxSum) maxSum=sum;
   f++;
  }
  e++;
 }
 printf("Max sum : %d\n",maxSum);
 return 0;
}