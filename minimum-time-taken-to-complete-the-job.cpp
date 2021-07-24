/*
Given a Directed Acyclic Graph having V 
vertices and E edges, where each edge {U, V}
 represents the Jobs U and V such that Job V 
 can only be started only after completion of 
 Job U. The task is to determine the 
 minimum time taken by each job to be 
 completed where each Job takes unit time 
 to get completed.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int V,E;
	cin>>V>>E;
	vector<int>adj[V+1];
	int indegree[V+1],ans[V+1];
	int i;
	for(i=1;i<=V;i++)
	{
		indegree[i]=0;
		ans[i]=0;
	}
	for(i=1;i<=E;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	queue<int>pq;
	for(i=1;i<=V;i++)
	{
		//cout<<indegree[i]<<" ";
		if(indegree[i]==0)
		{
			pq.push(i);
			ans[i]=1;
		}
	}
	
	while(!pq.empty())
	{
		//cout<<"sdg"<<endl;
		int node=pq.front();
		pq.pop();
		for(int child:adj[node])
		{
			indegree[child]--;
			if(indegree[child]==0)
			{
				pq.push(child);
				ans[child]=ans[node]+1;
				//cout<<child<<endl;
			}
		}
	}
	for(i=1;i<=V;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}