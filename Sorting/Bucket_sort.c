#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct __linked_list_node_
{
 int data;
 struct __linked_list_node_ * next;
}LinkedListNode;

typedef struct __linked_list_
{
 LinkedListNode* head;
 int size;
}LinkedList;

void initList(LinkedList *list)
{
 list->head=NULL;
 list->size=0;
}

int isEmpty(LinkedList *list)
{
 return list->size==0? 1 : 0;
}

int findPartitionPoint(int *arr,int lb,int ub)
{
 int e,f,temp;
 e=lb+1;
 f=ub;
 while(e<f)
 {
  while(e<ub && arr[e]<=arr[lb]) e++;
  while(f>=lb && arr[f]>arr[lb]) f--;
  if(e<f)
  {
   temp=arr[e];
   arr[e]=arr[f];
   arr[f]=temp;
  }
  else
  {
   temp=arr[lb];
   arr[lb]=arr[f];
   arr[f]=temp;
  }
 }
 return f;
}

void quickSort(int *arr, int lb, int ub)
{
 int pp;
 if(ub<=lb) return;
 pp=findPartitionPoint(arr,lb,ub);
 quickSort(arr,lb,pp-1);
 quickSort(arr,pp+1,ub);
}

void addToList(LinkedList *list, int data,int index)
{
 LinkedListNode *ptr,*node;
 node=NULL;
 int i,j;
 int *arr;
 if(list->size==0)
 {
  node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
  node->data=data;
  node->next=NULL;
  list->head=node;
  list->size++;
  return;
 }
 ptr=list->head;
 arr=(int *)malloc(sizeof(int)*(list->size+1));
 i=0;
 while(ptr)
 {
  arr[i]=ptr->data;
  ptr=ptr->next;
  i++;
 }
 arr[i]=data;
 quickSort(arr,0,i);
 ptr=list->head;
 i=0;
 while(ptr)
 {
  ptr->data=arr[i];
  i++;
  if(!ptr->next) break;
  ptr=ptr->next;
 }
 node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
 node->data=arr[i];
 node->next=NULL;
 ptr->next=node;
 list->size++;
}

int removeFromList(LinkedList *list)
{
 int data;
 LinkedListNode *node=list->head;
 list->head=list->head->next;
 data=node->data;
 list->size--;
 free(node);
 return data;
}

int hashFunction(int num, int place)
{
 int r=1,i=1;
 while(i<place)
 {
  r=r*10;
  i++;
 }
 return (num%(r*10))/r;
}

int findMax(int *arr,int size)
{
 int i;
 int max=arr[0];
 for(i=1;i<size;i++) if(arr[i]>max) max=arr[i];
 return max;
}

int digitCount(int num)
{
 int dc=1;
 for(;num>9;num/=10) dc++;
 return dc;
}

void bucketSort(int *arr, int size)
{
 int i,j;
 LinkedList * buckets[10];
 int dc=digitCount(findMax(arr,size));
 for(i=0;i<10;i++)
 {
  buckets[i]=(LinkedList *)malloc(sizeof(LinkedList));
  initList(buckets[i]);
 }
 for(i=0;i<size;i++)
 {
  addToList(buckets[hashFunction(arr[i],dc)],arr[i],hashFunction(arr[i],dc));
 } 
 j=0;
 for(i=0;i<10;i++)
 {
  while(!isEmpty(buckets[i]))
  {
   arr[j++]=removeFromList(buckets[i]);
  }
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
 for(i=0;i<req;i++) arr[i]=rand();

 printf("Before sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 bucketSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 return 0;
}