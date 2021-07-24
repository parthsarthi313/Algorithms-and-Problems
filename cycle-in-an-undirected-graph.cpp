/*

Topological Sort snippet

*/


vector<int>ans;
int vis[10004];
void dfs(int node,vector<int>adj[])
{
	   vis[node]=1;
	   for(int child:adj[node])
	   {
	       if(vis[child]==0)
	       {
	           dfs(child,adj);
	       }
	   }
	   ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
	    // code here
	   ans.clear();
	   int i;
	   for(i=0;i<V;i++)
	   {
	       vis[i]=0;
	   }
	    
	   for(i=0;i<V;i++)
	   {
	       if(vis[i]==0)
	       {
	           dfs(i,adj);
	       }
	   }
	   if((int)ans.size()>0)
	   reverse(ans.begin(),ans.end());
	   return ans;
}

