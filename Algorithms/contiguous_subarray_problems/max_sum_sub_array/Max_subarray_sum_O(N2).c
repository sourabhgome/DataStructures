// O(n^2) -> Bruteforce method to find maximum sum of a contigous subarray in a array

#include<stdio.h>

int main()
{
 int arr[]={10,-2,7,-6,-9,3};
 int size=6;
 int e,f,maxSum,sum;
 maxSum=0;
 e=0;
 while(e<size)
 {
  sum=arr[e];
  f=e+1;
  while(f<size)
  {
   sum=sum+arr[f];
   if(sum>maxSum) maxSum=sum;
   f++;
  }
  e++;
 }
 printf("Max sum : %d\n",maxSum);
 return 0;
}