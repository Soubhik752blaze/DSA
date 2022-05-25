#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> &vis,vector<int> adj[],vector<int> &s)
{
    s.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it,vis,adj,s);
    }
    


}

vector<int> DFSofgraph(int n,vector<int> adj[])
    {
    
      vector<int> s; 
	  vector<int> vis(n, 0); 
      for(int i = 1;i<n;i++) {
        if(!vis[i]) 
            dfs(i, vis, adj, s); 
      }
	    return s; 
    
    }
    
    
int main()
{
    int u,v;
    int m;
    int n=7;
    vector<int> adj[n];
    cin>>m;
    
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> df;
    df=DFSofgraph(n,adj);
    cout<<" THE DFS iS ===> ";
    for(auto it:df)
        cout<<it<< " ";
    

    return 0;
}
