#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>v;
int main()
{
	int n,m;
	cin>>n>>m;
	int i;
	for(i=0;i<m;i++)
	{
		int cost,a,b;
		cin>>cost>>a>>b;
		v.push_back({cost,{a,b}});
	}
	sort(v.begin(),v.end());
	int tree_id[n+1];
	for(i=1;i<=n;i++)
	{
		tree_id[i]=i;
	}
	int ans=0;
	int cnt=0;
	for(i=0;i<m;i++)
	{
		if(tree_id[v[i].second.first]!=tree_id[v[i].second.second])
		{
			ans+=v[i].first;
			cnt++;
			cout<<v[i].first<<endl;
			for(int j=1;j<=n;j++)
			{
				if(j==v[i].second.first)
					continue;
				if(tree_id[j]==tree_id[v[i].second.first])
					tree_id[j]=tree_id[v[i].second.second];
			}
			tree_id[v[i].second.first]=tree_id[v[i].second.second];
		}
		if(cnt==n-1)
			break;
	}
	cout<<ans<<endl;
}