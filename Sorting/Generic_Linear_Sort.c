#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//User have to give address of a comparator function as the 3rd parameter
void linearSort(void *collection,int size,int element_size,int (*comparator)(void *, void *))
{
 int e,f;
 void *a,*b,*c;
 c=malloc(element_size);
 e=0;
 while(e<size-1)
 {
  f=e+1;
  while(f<size)
  {
   a=collection+(e*element_size);
   b=collection+(f*element_size);
   if(comparator(a,b)>0)
   {
    memcpy(c,a,element_size);
    memcpy(a,b,element_size);
    memcpy(b,c,element_size);
   }
   f++;
  }
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
 linearSort(collection,size,sizeof(int),comparator);
 for(i=0;i<size;i++)
 {
  printf("%d\n",collection[i]);
 } 
 return 0;
}
