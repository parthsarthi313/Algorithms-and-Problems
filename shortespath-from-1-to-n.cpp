/*

Consider a directed 
graph whose vertices are numbered from 1 to n.
 There is an edge from a vertex i to a vertex j 
 iff either j = i + 1 or j = 3 * i.
  The task is to find the minimum number 
  of edges in a path in G from vertex 1 
  to vertex n.

  Space Complexity(O(1))

*/

#include<bits/stdc++.h>
#define hell                         1000000007
#define ll                           long long
#define endl                           '\n'

using namespace std;

int minimumStep(int n){
        //complete the function here
        
    int cnt=0;
    int temp=1;
    while(temp<n)
    {
        temp*=3;
        cnt++;
        if(temp>n)
        {
            temp/=3;
            cnt--;
            cnt+=(n-temp);
            break;
        }
    }
    int ans=cnt;
    temp=n;
    cnt=0;
    while(temp>1)
    {
        if(temp%3==0)
        {
            temp/=3;
            cnt++;
        }
        else
        {
            temp--;
            cnt++;
        }
    }
    return min(cnt,ans);
       
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    cout<<minimumStep(n)<<endl;
}