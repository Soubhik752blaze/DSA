#include<bits/stdc++.h>
using namespace std;

vector<int> BFSofgraph(int n,vector<int> adj[])
{
    
    vector<int> bfs; 
    vector<int> vis(n, 0); 
    for(int i = 1;i<n;i++) 
    {
        if(!vis[i]) 
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto it:adj[node])
                {    if(!vis[it])
                        {
                            q.push(it);
                            vis[it]=1;
                        }    
                }        

                bfs.push_back(node);
            }
            
        }   
    }
    return bfs;
}
        
    
void addedge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[8];
    addedge(0,1,adj);
    addedge(1,2,adj);
    addedge(2,3,adj);
    addedge(3,4,adj);
    addedge(2,5,adj);
    addedge(2,6,adj);
    addedge(7,6,adj);
    
    vector<int> df;
    df=BFSofgraph(8,adj);
    cout<<" THE BFS iS ===> ";
    for(auto it:df)
        cout<<it<< " ";
    

    return 0;
}


//Codebelongsto -- Blaze
