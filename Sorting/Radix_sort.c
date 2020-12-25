#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct __queue_node_
{
 int data;
 struct __queue_node_ *next; 
}QueueNode;

typedef struct __queue_
{
 QueueNode *start;
 QueueNode *end;
 int size;
}Queue;

int isQueueEmpty(Queue *queue)
{
 return queue->size==0? 1 : 0;
}

void initQueue(Queue *queue)
{
 queue->start=NULL;
 queue->end=NULL;
 queue->size=0;
}

void addToQueue(Queue *queue, int data)
{
 QueueNode *node;
 node=(QueueNode *)malloc(sizeof(QueueNode));
 if(!node) return;
 node->data=data;
 if(queue->start==NULL)
 {
  queue->start=node;
  queue->end=node;
  node->next=NULL;
 }
 else
 {
  queue->end->next=node;
  queue->end=node;
  node->next=NULL;
 }
 queue->size++;
}

int deleteFromQueue(Queue *queue)
{
 QueueNode *node;
 int data;
 node=queue->start;
 queue->start=queue->start->next;
 data=node->data;
 free(node);
 queue->size--;
 return data;
}

void radixSort(int *arr, int size)
{
 Queue negQueue[10],posQueue[10];
 int i,j,largest,digitCount,negCount,div,x,y;
 for(i=0;i<10;i++)
 {
  initQueue(&negQueue[i]);
  initQueue(&posQueue[i]);
 }
 largest=arr[0];
 negCount=0;
 for(i=0;i<size;i++)
 {
  if(arr[i]<0)
  {
   if(((-1)*(arr[i]))>largest) largest=((-1)*(arr[i]));
   negCount++;
  }
  else
  {
   if(arr[i]>largest) largest=arr[i];
  }
 }
 digitCount=1;
 while(largest>9)
 {
  largest/=10;
  digitCount++;
 }
 i=0;
 div=1;
 while(i<digitCount)
 {
  j=0;
  while(j<size)
  {
   if(arr[j]<0)
   {
    addToQueue(&negQueue[((-arr[j])%(div*10))/div],arr[j]);
   }
   else
   {
    addToQueue(&posQueue[(arr[j]%(div*10))/div],arr[j]);
   }
   j++;
  }

  x=0;
  y=negCount;
  j=0;
  while(j<10)
  {
   while(!isQueueEmpty(&negQueue[j]))
   {
    arr[x++]=deleteFromQueue(&negQueue[j]);
   }
   while(!isQueueEmpty(&posQueue[j]))
   {
    arr[y++]=deleteFromQueue(&posQueue[j]);
   }
   j++;
  }
  div*=10;
  i++;
 }
 i=0;
 j=negCount-1;
 while(i<j)
 {
  arr[i]=arr[i]+arr[j];
  arr[j]=arr[i]-arr[j];
  arr[i]=arr[i]-arr[j];
  i++;
  j--;
 }
}

int main()
{
 int req,i;
 int *arr;
 printf("Enter requirement : ");
 scanf("%d",&req);
 arr=(int *)malloc(sizeof(int)*req);
 /*printf("Enter %d numbers : \n",req);
 for(i=0;i<req;i++) scanf("%d",&arr[i]);*/

 srand(time(0));
 for(i=0;i<req;i++) if(i%2==0) arr[i]=rand(); else arr[i]=-(rand());

 printf("Before sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 radixSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}