#include<bits/stdc++.h>
using namespace std;
struct Item {
    int value, weight;
 
    // Constructor
   
};
 bool cmp(Item a,Item b)
 {
     double r1=(double)a.value/(double)a.weight;
     double r2=(double)b.value/(double)b.weight;
     return r1>r2;
 }
double fractionalknapsack(int w,struct Item arr[],int n)
{
sort(arr,arr+n,cmp);
int currweight=0;
double finalvalue=0.0;
for(int i=0;i<n;i++)
{
  if(currweight+arr[i].weight<=w)
  {
      currweight+=arr[i].weight;
      finalvalue+=arr[i].value;
  }
  else 
  {
      int remain=w-currweight;
      finalvalue+=(arr[i].value /(double(arr[i].weight)))*double(remain);
  }
}
return finalvalue;

}

int main()
{
    int n;
    cin>>n;
    int maxcap;
    cin>>maxcap;
    Item arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value;
        cin>>arr[i].weight;
    }
  cout<<fractionalknapsack(maxcap,arr,n);
}