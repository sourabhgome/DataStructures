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

void addToList(LinkedList *list, int data)
{
 LinkedListNode *ptr,*node;
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
 while(ptr->next) ptr=ptr->next;
 node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
 node->data=data;
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

void findMaxMin(int *arr, int size, int *min, int *max)
{
 int i;
 *min=arr[0];
 *max=arr[0];
 i=1;
 while(i<size)
 {
  if(arr[i]>*max) *max=arr[i];
  if(arr[i]<*min) *min=arr[i];
  i++;
 }
}

void pigeonHoleSort(int *arr, int size)
{
 int range,max,min,i,k;
 LinkedList * lists;
 findMaxMin(arr,size,&min,&max);
 range=max-min+1;
 lists=(LinkedList *)malloc(sizeof(LinkedList)*range);
 i=0;
 while(i<range)
 {
  initList(&lists[i]);
  i++;
 }
 i=0;
 while(i<size)
 {
  addToList(&lists[arr[i]-min],arr[i]);
  i++;
 }
 i=0;
 k=0;
 while(i<range)
 {
  while(!isEmpty(&lists[i]))
  {
   arr[k++]=removeFromList(&lists[i]);
  }
  i++;
 }
 free(lists);
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
 pigeonHoleSort(arr, req);
 printf("After sorting : \n");
 for(i=0;i<req;i++) printf("%d ",arr[i]);
 printf("\n");
 free(arr);
 return 0;
}