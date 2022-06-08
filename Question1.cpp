#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>v,vector<vector<int>>&final,vector<int>ds,int temp,int sum,int idx)
{
    
    if(temp>sum)return;
    
  if(temp==sum)
  {
      final.push_back(ds);
      return;
  }
  for(int i=idx;i<v.size();i++)
  {
      ds.push_back(v[i]);
      temp+=v[i];
      helper(v,final,ds,temp,sum,i);
      temp-=v[i];
      ds.pop_back();
  }
   
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    int sum,x=0;
    cin>>sum;
    vector<vector<int>>final;
    vector<int>ds;
    helper(v,final,ds,x,sum,0);
    cout<<final.size();

    return 0;
}