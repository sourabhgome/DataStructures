#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//User have to give address of a comparator function as the 3rd parameter
void bubbleSort(void *collection,int size,int element_size,int (*comparator)(void *, void *))
{
 int e,f,m;
 m=size-2;
 void *a,*b,*c;
 c=malloc(element_size);
 while(m>=0)
 {
  e=0;
  f=1;
  while(e<=m)
  {
   a=collection+(e*element_size);
   b=collection+(f*element_size);
   if(comparator(a,b)>0)
   {
    memcpy(c,a,element_size);
    memcpy(a,b,element_size);
    memcpy(b,c,element_size);
   }
   e++;
   f++;
  }
  m--;
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
 bubbleSort(collection,size,sizeof(int),comparator);
 for(i=0;i<size;i++)
 {
  printf("%d\n",collection[i]);
 } 
 return 0;
}
