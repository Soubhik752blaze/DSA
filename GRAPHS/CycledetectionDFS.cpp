#include<bits/stdc++.h>
using namespace std;


bool checkforcycleDFS(int node, int parent, vector<int> &vis,vector<int> adj[])
{
    
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(checkforcycleDFS(it,node,vis,adj))
                return true;
        } 
        else if(it!=parent)
            return true;
    }   
    return false;
    


}

bool cycledetection(int n,vector<int> adj[])
    {
	  vector<int> vis(n, 0); 
      int parent;
      for(int i = 1;i<n;i++) 
      {
        if(!vis[i]) 
            if(checkforcycleDFS(i, -1,vis, adj))
                return true ;
      }
	    return false; 
    
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
        adj[v].push_back(u);
    }

    cout<<"\n \n";
    cycledetection(n,adj)?cout<<"Cycle Present":cout<<"No cycle detected";
      
    

    return 0;
}


//Codebelongsto -- Blaze