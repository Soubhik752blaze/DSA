#include<bits/stdc++.h>
using namespace std;


bool DGcycledetectionBFS(int n,vector<int> adj[])
    {
        int cnt = 0;
	    queue<int> q;
        vector<int> indegree (n,0);
        for(int i = 0;i<n;i++) 
            for(auto it:adj[i])
                indegree[it]++;

        for(int i = 0;i<n;i++) 
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();                           //USED KAHN'S ALGORITHM
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);        
            }

        }
        if(cnt==n)
            return false;
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
    }

    cout<<"\n \n";
    DGcycledetectionBFS(n,adj)?cout<<"Cycle Present":cout<<"No cycle detected";
      
    

    return 0;
}


//Codebelongsto -- Blaze