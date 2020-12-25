#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int copies=0;

void _printCombinations(char *seed, char *set, int length, int patLength)
{
 copies++;
 int i,seedSize;
 char *str;
 if(patLength==0)
 {
  printf("%s\n",seed);
  return;
 }
 seedSize=strlen(seed);
 str=(char *)malloc(seedSize+2);
 strcpy(str,seed);
 for(i=0;i<length;i++)
 {
  str[seedSize]=set[i];
  str[seedSize+1]='\0';
  _printCombinations(str, set, length, patLength-1);
 }
}

void printCombinations(char *set, int length, int patLength)
{
 _printCombinations("",set,length,patLength);
}

int main()
{
 char str[101];
 int patLength;
 printf("Enter string : ");
 scanf("%s",str);
 printf("Enter length of combinations : ");
 scanf("%d",&patLength);
 printCombinations(str, strlen(str), patLength);
 printf("Copies made : %d\n",copies);
 return 0;
}