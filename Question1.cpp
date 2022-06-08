#include<iostream>
#include<vector>
using namespace std;
const int N=5;
vector<int>g[N];
 bool haspath(int source,int destination, vector<bool>&visited)
    {
        if(source==destination)return true;
        visited[source]=true;
        for(auto child:g[source])
        {
            if(!visited[child])
            {
               bool ans= haspath(child,destination,visited);
                if(ans)return true;
            }
        }
        return false;
    }
    
int main()
{
    int M;
    cout<<"Enter number of Edges";
    cin>>M;
     for(int i=0;i<M;i++)
     {
         int v1,v2;
         cin>>v1>>v2;
         g[v1].push_back(v2);
         g[v2].push_back(v1);
     }
 for(int i=1;i<=5;i++)
 {
     cout<<i<<"-> ";
     for(int &x:g[i])
     {
         cout<<x<<" ";
     }
     cout<<endl;
 }
 int s,d;
 cin>>s>>d;
 vector<bool>visited(N);
 if(haspath(s,d,visited))cout<<"YES path exist!!";
 else cout<<"No path exist";
}