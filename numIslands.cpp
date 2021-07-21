/*



*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

int vis[505][505];
vector<pair<int,int>>v;
void bfs(int x,int y,vector<vector<char>>& grid)
{
    queue<pair<int,int>>pq;
    pq.push({x,y});
    int n=grid.size();
    int m=grid[0].size();
    while(!pq.empty())
    {
        x=pq.front().first;
        y=pq.front().second;
        pq.pop();
        vis[x][y]=1;
            
            
        for(int i=0;i<8;i++)
        {
            int nx=x+v[i].first;
            int ny=y+v[i].second;
            if(nx<0 || ny<0 || nx>=n || ny>=m)
            continue;
            if(vis[nx][ny]==1)
            continue;
            if(grid[nx][ny]=='0')
            continue;
                
            pq.push({nx,ny});
            vis[nx][ny]=1;
        }
    }
}
int numIslands(vector<vector<char>>& grid) 
{
        // Code here
    int n=grid.size();
    int m=grid[0].size();
    int i,j;
        
    v.push_back({1,0});
    v.push_back({0,1});
    v.push_back({-1,0});
    v.push_back({0,-1});
    v.push_back({1,1});
    v.push_back({1,-1});
    v.push_back({-1,1});
    v.push_back({-1,-1});
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
    }
        
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1' && vis[i][j]==0)
            {
                bfs(i,j,grid);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid;
    int i,j;
    for(i=0;i<n;i++)
    {
        vector<char>v2;
        for(j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            v2.push_back(ch);
        }
        grid.push_back(v2);
    }

    cout<<numIslands(grid)<<endl;
}