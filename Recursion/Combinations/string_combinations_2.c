#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int copies=0;

void _printCombinations(char *seed, char *set, int length, int patLength, int index) //An extra parameter to keep track of which index is previously visited
{
 copies++;
 int i,seedSize,range;
 char *str;
 if(patLength==0)
 {
  printf("%s\n",seed);
  return;
 }
 seedSize=strlen(seed);
 str=(char *)malloc(seedSize+2);
 strcpy(str,seed);
 range=length-(patLength-1);
 for(i=index;i<range;i++)
 {

  /*First approach : Checking if the element exists already or not but this approach is time consuming
  found=0;
  ptr=str;
  while(*ptr)
  {
   if(*ptr==set[i])
   {
    found++;
    break;
   }
   ptr++;
  }
  if(found) continue;*/

  str[seedSize]=set[i];
  str[seedSize+1]='\0';
  _printCombinations(str, set, length, patLength-1, i+1);
 }
}

void printCombinations(char *set, int length, int patLength)
{
 //Second approach : Generating new set which does not contain duplicate elements
 char *temp,*ptr1,*ptr2;
 int setLength=strlen(set);
 int found=0,index;
 temp=(char *)malloc(setLength+1);
 temp[0]='\0';
 index=0;
 ptr1=set;
 while(*ptr1)
 {
  found=0;
  ptr2=temp;
  while(*ptr2)
  {
   if(*ptr1==*ptr2)
   {
    found++;
    break;
   }
   ptr2++;
  }
  if(!found)
  {
   temp[index++]=*ptr1;
  }
  ptr1++;
 }
 temp[index]='\0';
 _printCombinations("",temp,index,patLength,0);
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