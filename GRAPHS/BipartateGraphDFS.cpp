#include<bits/stdc++.h>
using namespace std;


bool colorDFS(int node, int clr[],vector<int> adj[])
{
    
    if(clr[node]== -1)
        clr[node]=1;
    for(auto it:adj[node])
    {
        if(clr[it]== -1)
        {
            clr[it]= 1-clr[node];
            if(!colorDFS(it,clr,adj))
                return false;
        } 
        else if(clr[it]==clr[node])
            return false;
    }   
    return true;

}

bool bipartategraphDFS(int n,vector<int> adj[])
    {
	  int clr[n]; 
      for(int i=0;i<n;i++)
        clr[i]= -1;
      for(int i = 0;i<n;i++) 
      {
        if(clr[i] == -1) 
            if(!colorDFS(i,clr, adj))
                return false ;
      }
	  return true; 
    
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
    bipartategraphDFS(n,adj)?cout<<"It is a Bipartate Graph":cout<<" It is not a Bipartate Graph";
      
    return 0;

}


//Codebelongsto -- Blaze