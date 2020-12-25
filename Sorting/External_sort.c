#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define NUMBERS_TO_BE_GENERATED 1000000

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

void generateRandomNumbers()
{
 FILE* file;
 int i,num;
 file=fopen("files/randomNumbers.dat","wb");
 srand(time(0));
 i=0;
 while(i<NUMBERS_TO_BE_GENERATED)
 {
  num=rand();
  fwrite(&num, sizeof(int), 1, file);
  i++;
 }
 fclose(file);
}

void createFiles()
{
 FILE* file,*temp;
 char fileName[]="files/1.dat";
 int i,j,size,data;
 int *arr;
 file=fopen("files/randomNumbers.dat","rb");
 size=0;
 fseek(file,0,SEEK_END);
 size=ftell(file);
 size=size/sizeof(int);
 fseek(file,0,SEEK_SET);
 i=0;
 while(i<10)
 {
  fileName[6]=(char)(i+48);
  temp=fopen(fileName,"wb");
  arr=(int *)malloc(sizeof(int)*(size/10));
  j=0;
  while(j<size/10)
  {
   fread(&data, sizeof(int), 1, file);
   arr[j]=data;
   j++;
  }
  quickSort(arr,0,(size/10)-1);
  j=0;
  while(j<size/10)
  {
   data=arr[j];
   fwrite(&data, sizeof(int), 1, temp);
   j++;
  }
  free(arr);
  fclose(temp);
  i++;
 }
 fclose(file);
}

int findMinIndex(int *arr, int size)
{
 int minIndex,min,i;
 min=arr[0];
 minIndex=0;
 for(i=0;i<size;i++)
 {
  if(arr[i]<min)
  {
   min=arr[i];
   minIndex=i;
  }
 }
 return minIndex;
}

void externalSort()
{
 FILE *files[10];
 FILE *sorted,*sorted_r;
 int arr[10];
 int i,j,data,index,flag=1,arr_size,count=0;
 char fileName[]="files/1.dat";
 for(i=0;i<10;i++)
 {
  fileName[6]=(char)(i+48);
  files[i]=fopen(fileName, "rb");
 }
 sorted=fopen("files/sorted_binary.dat","wb");
 sorted_r=fopen("files/sorted_readable.txt","w");
 i=0;
 for(i=0;i<10;i++)
 {
  fread(&data, sizeof(int), 1, files[i]);
  arr[i]=data;
 }
 arr_size=10;
 while(flag)
 {
  index=findMinIndex(arr,arr_size);
  fwrite(&arr[index], sizeof(int), 1, sorted);
  fprintf(sorted_r,"%d\n",arr[index]);
  fread(&data, sizeof(int), 1, files[index]);
  if(feof(files[index]))
  {
   arr[index]=INT_MAX;
   fclose(files[index]);
   count++;
  }
  else
  {
   arr[index]=data;
  }
  if(count==10)
  {
   flag=0;
   break;
  }
 }
 fclose(sorted);
/*sorted=fopen("files/sorted.dat","rb");
 i=0;
 while(!feof(sorted))
 {
  fread(&data,sizeof(int),1,sorted);
  printf("%d : %d\n",i,data);
  i++;
 }
 fclose(sorted);*/
}

int main()
{
 generateRandomNumbers();
 createFiles();
 externalSort();
 return 0;
}