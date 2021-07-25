/*
implementation of kruskal in O(ElogE + V^2)
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>v;
int par[100005],sz[100005];
void build(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
}
int find(int x)
{
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	if(sz[x]<sz[y])
		swap(x,y);
	par[y]=x;
	sz[x]+=sz[y];
}
int main()
{
	int V,E;
	cin>>V>>E;
	build(V-1);
	int i;
	for(i=0;i<E;i++)
	{
		int cost,a,b;
		cin>>cost>>a>>b;
		v.push_back({cost,{a,b}});
	}
	sort(v.begin(),v.end());

	int ans=0;
	int cnt=0;
	for(i=0;i<E;i++)
	{
		if(find(v[i].second.first)!=find(v[i].second.second))
		{
			ans+=v[i].first;
			cnt++;
			merge(v[i].second.first,v[i].second.second);
			if(cnt==(E-1))
				break;
		}
	}
	cout<<ans<<endl;
}