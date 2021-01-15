#include<stdio.h>
#include<stdlib.h>

typedef struct llnode
{
 int *arr;
 int size;
 struct llnode *next;
}LinkedListNode;

typedef struct LinkedList_
{
 LinkedListNode *head;
 int size;
}LinkedList;

int maxSize;
LinkedList *linkedList;
LinkedListNode *current;

void printAscending(int *arr, int *record, int *subset, int size, int start, int subset_index)
{
 int i;
 LinkedListNode *node,*temp;
 if(start==size) 
 {
  if(subset_index>maxSize)
  {
   node=linkedList->head;
   while(node)
   {
    free(node->arr);
    temp=node;
    node=node->next;
    free(temp);
   }
   node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
   node->arr=(int *)malloc(sizeof(int)*subset_index);
   for(i=0;i<subset_index;i++) node->arr[i]=subset[i];
   node->size=subset_index;
   node->next=NULL;
   linkedList->head=node;
   current=node;
   maxSize=subset_index;
  }
  else if(subset_index==maxSize)
  {
   node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
   node->arr=(int *)malloc(sizeof(int)*subset_index);
   for(i=0;i<subset_index;i++) node->arr[i]=subset[i];
   node->size=subset_index;
   node->next=NULL;
   current->next=node;
   current=node;
  }
  return;
 }
 if(subset_index==0)
 {
  for(i=0;i<size-1;i++)
  {
   if(record[i]!=0) continue;
   subset[0]=arr[i];
   printAscending(arr,record,subset,size,start+i,subset_index+1);
  }
 }
 else
 {
  if(arr[start]>subset[subset_index-1])
  {
   subset[subset_index]=arr[start];
   record[start]++;
   printAscending(arr,record,subset,size,start+1,subset_index+1);
  }
  else
  {
   printAscending(arr,record,subset,size,start+1,subset_index);
  }
 }
}

int main()
{
 int arr[]={12,3,92,-3,76,54,12,93,78};
 int size=9,i;
 LinkedListNode *node,*temp;
 int *record=(int *)calloc(size,sizeof(int));
 int *subset=(int *)calloc(size,sizeof(int));
 linkedList=(LinkedList *)malloc(sizeof(LinkedList));
 linkedList->head=NULL;
 linkedList->size=0;
 printAscending(arr,record,subset,size,0,0);
 node=linkedList->head;
 while(node)
 {
  for(i=0;i<maxSize;i++)
  {
   printf("%d ",node->arr[i]);
  }
  printf("\n");
  node=node->next;
 }
 //Code to free allocated memory
 free(record);
 free(subset);
 node=linkedList->head;
 while(node)
 {
  free(node->arr);
  temp=node;
  node=node->next;
  free(temp);
 }
 free(linkedList);
 return 0;
}