/*

Check if the cycle is present in the undirected 
graph of not.

*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

int vis[100005];
bool dfs(int node,int par,vector<int> adj[])
{
    vis[node]=1;
    for(int child:adj[node])
    {
        if(child==par)
        continue;
        if(vis[child]==0)
        {
            if(dfs(child,node,adj))
            return true;
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int>adj[])
{
    // Code here
    int i;
    for(i=0;i<=V;i++)
    {
        vis[i]=0;
    }
    for(i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i,-1,adj))
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        int i;
        vector<int>graph[V+1];
        for(i=0;i<V;i++)
        {
            graph[i].clear();
        }
        for(i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        cout<<isCycle(V,graph)<<endl;
    }
}