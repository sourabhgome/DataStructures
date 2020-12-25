#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//User have to give address of a comparator function as the 3rd parameter

/**
 * Keep number at e index in mind
 * Move upwards till we find a number equal or less than number in mind or once -1 index is reached
 * Till then shift the numbers to f+1 index
 * Loop ends put the number in mind to f+1 index
*/
void insertionSort(void *collection,int size,int element_size,int (*comparator)(void *, void *))
{
 int e,f;
 void *a,*b,*mind;
 mind=malloc(element_size);
 e=1;
 while(e<size)
 {
  memcpy(mind,collection+(e*element_size),element_size);
  f=e-1;
  while(f>=0)
  {
   a=collection+(f*element_size);
   b=collection+((f+1)*element_size);
   if(comparator(a,mind)>0) //a is big
   {
    memcpy(b,a,element_size);
   }
   else
   { 
    break;
   }
   f--;
  }
  memcpy(collection+((f+1)*element_size),mind,element_size);
  e++;
 }
}



// Driver Code
int comparator(void *left,void *right)
{
 int *lft=(int *)left;
 int *rght=(int *)right;
 return *lft-*rght;
}

int main()
{
 int size,i;
 int *collection;
 printf("Enter size of collection : ");
 scanf("%d",&size);
 collection=(int *)malloc(size*sizeof(int));
 if(collection==NULL)
 {
  printf("Cannot allocate memory");
  return 0;
 }
 printf("Enter %d numbers :\n",size);
 for(i=0;i<size;i++)
 {
  scanf("%d",&collection[i]);
 }
 insertionSort(collection,size,sizeof(int),comparator);
 for(i=0;i<size;i++)
 {
  printf("%d\n",collection[i]);
 } 
 return 0;
}
