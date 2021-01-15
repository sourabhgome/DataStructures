#include<stdio.h>
#include<map>
using namespace std;
int main()
{
 map<int,int> temp;
 map<int,int>::iterator iter;
 int arr[]={10,-3,7,6,-2,4,3,9,-5,12};
 int sum=5,i,found=0;
 int size=10;
 int start=-1;
 int associated_sum=0;
 i=0;
 while(i<size)
 {
  associated_sum+=arr[i];
  if(associated_sum==sum)
  {
   found++;
   break;
  }
  iter=temp.find(associated_sum-sum);
  if(iter!=temp.end())
  {
   start=iter->second;
   found++;
   break;
  }
  temp.insert(pair<int,int>(associated_sum,i));
  i++;
 }
 if(found) printf("(%d, %d) -> %d\n",start+1,i,sum);
 else printf("No such subarray found\n");
 return 0;
}