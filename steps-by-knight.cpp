/*

Check if the cycle is present in the undirected 
graph of not.

*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
        // Code here
        
    int x=KnightPos[0];
    int y=KnightPos[1];
    x--;
    y--;
        
    vector<pair<int,int>>v;
    v.push_back({2,1});
    v.push_back({-2,1});
    v.push_back({2,-1});
    v.push_back({-2,-1});
        
    v.push_back({1,2});
    v.push_back({-1,2});
    v.push_back({1,-2});
    v.push_back({-1,-2});
    queue<pair<pair<int,int>,int>>pq;
    int vis[N+1][N+1];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            vis[i][j]=0;
        }
    }
    pq.push({{x,y},0});
    while(!pq.empty())
    {
        x=pq.front().first.first;
        y=pq.front().first.second;
        int cnt=pq.front().second;
        pq.pop();
        if(x==(TargetPos[0]-1) && y==(TargetPos[1]-1))
        return cnt;
        vis[x][y]=1;
        for(int i=0;i<8;i++)
        {
            int nx=x+v[i].first;
            int ny=y+v[i].second;
            if(nx<0 || ny<0 || nx>=N || ny>=N)
            continue;
            if(vis[nx][ny]==1)
            continue;
                
            pq.push({{nx,ny},1+cnt});
            vis[nx][ny]=1;
        }
    }
    //return 1;
        
        
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N;
        cin>>N;
        cin>>KnightPos[0]>>KnightPos[1];
        cin>>TargetPos[0]>>TargetPos[1];
        cout<<minStepToReachTarget(KnightPos,TargetPos,N)<<endl;
    }
}