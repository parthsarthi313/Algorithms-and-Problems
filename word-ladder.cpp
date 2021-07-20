/*



*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string,int>mp;
    for(int i=0;i<(int)wordList.size();i++)
    {
        mp[wordList[i]]=1;
    }
    if(mp.find(endWord)==mp.end())
        return 0;
    queue<pair<string,int>>pq;
    map<string,int>vis;
    vis[beginWord]=1;
    pq.push({beginWord,1});
    while(!pq.empty())
    {
        string s=pq.front().first;
        int cnt=pq.front().second;
        pq.pop();
        if(s==endWord)
            return cnt;
        for(int i=0;i<(int)s.size();i++)
        {
            for(char j='a';j<='z';j++)
            {
                if(s[i]==j)
                    continue;
                string temp=s;
                temp[i]=j;
                if(mp.find(temp)==mp.end())
                    continue;
                if(vis.find(temp)!=vis.end())
                    continue;
                pq.push({temp,1+cnt});
                vis[temp]=1;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string beginWord,endWord;
    cin>>beginWord>>endWord;
    vector<string>wordList;
    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        wordList.push_back(s);
    }

    cout<<ladderLength(beginWord,endWord,wordList)<<endl;
}