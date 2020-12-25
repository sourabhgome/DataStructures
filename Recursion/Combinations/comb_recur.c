#include<stdio.h>

void _printCombination(int *arr, int *set, int length, int maxLength, int index)
{
 int i;
 if(maxLength==0)
 {
  printf("[%d, %d, %d]\n",arr[0],arr[1],arr[2]);
  return;
 }
 for(i=0;i<length;i++)
 {
  arr[index]=set[i];
  _printCombination(arr,set,length,maxLength-1,index+1);
 }
}

void printCombination(int *set, int length, int maxLength)
{
 int arr[3];
 _printCombination(arr, set, length, maxLength,0);
}

int main()
{
 int set[]={0,1,2,3};
 printCombination(set,4,3);
 return 0;
}