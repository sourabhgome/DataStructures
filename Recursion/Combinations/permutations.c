#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a, char *b)
{
 char temp;
 temp=*a;
 *a=*b;
 *b=temp;
}

void _printPermutations(char *str, int si, int ei)
{
 int i;
 if(si==ei)
 {
  for(i=0;i<=ei;i++) printf("%c",str[i]);
  printf("\n");
  return;
 }
 for(i=si;i<=ei;i++)
 {
  swap(&str[si],&str[i]);
  _printPermutations(str, si+1, ei);
  swap(&str[si],&str[i]);
 }
}

void printPermutations(char *str, int si, int ei)
{
 _printPermutations(str, si, ei);
}

int main()
{
 char str[101];
 printf("Enter a string : ");
 scanf("%s",str);
 printPermutations(str,0,strlen(str)-1);
 return 0;
}