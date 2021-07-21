/*



*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

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
int makeConnected(int n, vector<vector<int>>& connections) {
    int m=connections.size();
    build(n);
    int deg[n];
    int i;
    for(i=0;i<n;i++)
        deg[i]=0;
    for(i=0;i<m;i++)
    {
        int a=connections[i][0];
        int b=connections[i][1];
        merge(a,b);
        deg[a]++;
        deg[b]++;
    }
    map<int,vector<int>>mp;
        
    for(i=0;i<n;i++)
    {
        int x=find(i);
            mp[x].push_back(i);
    }
    int extra=0;
    int groups=mp.size();
    for(auto i:mp)
    {
        int sum=0;
        for(int j:i.second)
        {
            sum+=deg[j];
        }
        extra+=(sum/2)-(int)i.second.size()+1;
    }
        
    if(extra<(groups-1))
        return -1;
    return groups-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>connections;
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            vector<int>v;
            v.push_back(a);
            v.push_back(b);
            connections.push_back(v);
        }
        cout<<makeConnected(n,connections)<<endl;
    }
    
}