#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iterator>

using namespace std;

void findSequences(int *arr, int *record, int *subset, int start ,int size, int subset_size, list<int*> *ans_list, list<int> *subset_sizes)
{
 int i,*temp;
 if(start>=size)
 {
  temp=(int *)malloc(sizeof(int)*subset_size);
  for(i=0;i<subset_size;i++)
  {
   temp[i]=subset[i];
  }
  subset_sizes->push_back(subset_size);
  ans_list->push_back(temp);
  return;
 }
 if(subset_size==0)
 {
  for(i=start;i<size-1;i++)
  {
   if(record[i]!=0) continue;
   subset[0]=arr[i];
   findSequences(arr, record, subset, i+1, size, subset_size+1, ans_list, subset_sizes);
  }
 }
 else
 {
  if(subset[subset_size-1]<arr[start])
  {
   record[start]++;
   subset[subset_size]=arr[start];
   findSequences(arr, record, subset, start+1, size, subset_size+1, ans_list, subset_sizes);
  }
  else
  {
   findSequences(arr, record, subset, start+1, size, subset_size, ans_list, subset_sizes);
  }
 }
}

int isSame(int *arr1, int *arr2, int size)
{
 int i=0;
 while(i<size)
 {
  if(arr1[i]!=arr2[i]) return 0;
  i++;
 }
 return 1;
}

int main()
{
 int arr1[]={12,3,92,-3,76,54,12,93,78};
 int arr2[]={12,92,93,6,5,4,3,2,1};
 int size1=9;
 int size2=9;
 int i,j;
 int *subset1=(int *)calloc(size1,sizeof(int));
 int *subset2=(int *)calloc(size2,sizeof(int));
 int *record1=(int *)calloc(size1,sizeof(int));
 int *record2=(int *)calloc(size2,sizeof(int));
 list <int *> list1;
 list <int *> list2;
 list <int *>:: iterator list1_iter;
 list <int *>:: iterator list2_iter;
 list <int> subset1_sizes;
 list <int> subset2_sizes;
 list <int>:: iterator sizes1_iter;
 list <int>:: iterator sizes2_iter;
 findSequences(arr1,record1,subset1,0,size1,0,&list1,&subset1_sizes);
 findSequences(arr2,record2,subset2,0,size2,0,&list2,&subset2_sizes);
 list1_iter=list1.begin();
 sizes1_iter=subset1_sizes.begin();
 while(list1_iter!=list1.end())
 {
  list2_iter=list2.begin();
  sizes2_iter=subset2_sizes.begin();
  while(list2_iter!=list2.end())
  {
   if(*sizes1_iter==*sizes2_iter && isSame(*list1_iter, *list2_iter, *sizes1_iter))
   {
    for(i=0;i<*sizes1_iter;i++) printf("%d ",(*list1_iter)[i]);
    printf("\n");
   }
   sizes2_iter++;
   list2_iter++;
  }
  sizes1_iter++;
  list1_iter++;
 }
 return 0;
}
