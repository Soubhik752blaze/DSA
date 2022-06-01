#include<bits/stdc++.h>
using namespace std;


bool checkcyclic(int node, int vis[], int dfsvis[],vector<int> adj[])
{
    
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(checkcyclic(it,vis,dfsvis,adj))
                return true;
        } 
        else if(dfsvis[it])
            return true;
    }
    dfsvis[node]=0;   
    return false;
    


}

bool DGcycledetectionDFS(int n,vector<int> adj[])
    {
	  int vis[n]={0},dfsvis[n]={0};
      for(int i = 0;i<n;i++) 
      {
        if(!vis[i]) 
            if(checkcyclic(i, vis,dfsvis, adj))
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
    }

    cout<<"\n \n";
    DGcycledetectionDFS(n,adj)?cout<<"Cycle Present":cout<<"No cycle detected";
      
    

    return 0;
}


//Codebelongsto -- Blaze