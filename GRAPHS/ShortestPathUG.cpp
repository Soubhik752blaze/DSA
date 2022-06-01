#include<bits/stdc++.h>
using namespace std;


bool UGshortestpathunitweight(int n,int src,vector<int> adj[])
    {
        int dist[n];
	    queue<int> q;
        for(int i = 0;i<n;i++) 
            dist[i]=INT_MAX;
        q.push(src);
        dist[src]=0;

        while(!q.empty())
        {
            int node = q.front();                           //Slightly Tweeked BFS to find shortest path for nodes in a graph with unit weight edges 
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[node]+1<dist[it])  
                    {
                        dist[it]=1+dist[node]; 
                        q.push(it);
                    }         
            }
        }
        for(int i=0;i<n;i++)
            {
                cout<<"Distance from Source (" <<src<<") to "<<i<<" is "<<dist[i]<<endl;
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
    UGshortestpathunitweight(n,0,adj);
      
    

    return 0;
}


//Codebelongsto -- Blaze