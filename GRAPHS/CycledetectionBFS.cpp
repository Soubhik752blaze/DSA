#include<bits/stdc++.h>
using namespace std;


bool checkforcycleBFS(int src, int n,vector<int> &vis,vector<int> adj[])
{
    queue<pair<int,int>> q;
    vis[src]=1;
    q.push({src,-1});
    while(!q.empty())
    {   
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            } 
            else if(it!=parent)
                return true;
        }   
    return false;
    
    }
}
bool isCycle(int n, vector<int> adj[])
    {
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                if (checkforcycleBFS(i, n, vis, adj ))
                    return true;

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
    if(n<2)
    {
        cout<<"No Cycle Present";
        return 0;
    }
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
    
    cout<<"\n";
    isCycle(n,adj)?cout<<"Cycle Present":cout<<"No cycle detected";
      
    

    return 0;
}


//Codebelongsto -- Blaze