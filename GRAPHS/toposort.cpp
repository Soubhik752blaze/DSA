#include<bits/stdc++.h>
using namespace std;


void findtopo(int node, stack<int> &s,vector<int> &vis, vector<int> adj[])
{
    
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            findtopo(it,s,vis,adj);
        }
    }   
    s.push(node);

}

void toposort(int n,vector<int> adj[])
    {
	  vector<int> topo;
      stack<int> s;
      vector<int> vis(n,0);
      for(int i=0;i<n;i++)
      {
          if(!vis[i])
            findtopo(i,s,vis,adj);
      }
      while(!s.empty())
      {
          int i= s.top();
          topo.push_back(i);
          s.pop();
      }
      for(auto it: topo)
      {
          cout<<it<<" "; 
      }
        
    
    }
    
    
int main()
{
    int u,v;
    int m;
    int n;
    cout<<"Enter no of nodes:- ";
    cin>>n;
    vector<int> adj[n];
    cout<<"Enter No of Edges :- ";
    cin>>m;
    cout<<" Add the Edges \n";
    while(m--)
    {
    
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<"\n \n";
    toposort(n,adj);
      
    return 0;

}


//Codebelongsto -- Blaze