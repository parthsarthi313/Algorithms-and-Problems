#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int main()class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for(int i =0;i<N;i++){
            dp[0][i] = Matrix[0][i];
        }
        for(int i =1;i<N;i++){
            for(int j =0;j<N;j++){
                dp[i][j] = 0;
                if(i-1 >=0) dp[i][j] = max(dp[i][j],dp[i-1][j] + Matrix[i][j]);
                if(i-1 >=0 && j-1 >=0) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + Matrix[i][j]);
                if(i-1 >=0 && j+1 <= N-1) dp[i][j] = max(dp[i][j],dp[i-1][j+1] + Matrix[i][j]);
            }class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for(int i =0;i<N;i++){
            dp[0][i] = Matrix[0][i];
        }
        for(int i =1;i<N;i++){
            for(int j =0;j<N;j++){
                dp[i][j] = 0;
                if(i-1 >=0) dp[i][j] = max(dp[i][j],dp[i-1][j] + Matrix[i][j]);
                if(i-1 >=0 && j-1 >=0) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + Matrix[i][j]);
                if(i-1 >=0 && j+1 <= N-1) dp[i][j] = max(dp[i][j],dp[i-1][j+1] + Matrix[i][j]);
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<N;i++){
            ans = max(ans,dp[N-1][i]);
        }
        return ans;
    }
};
        }
        int ans = INT_MIN;
        for(int i =0;i<N;i++){
            ans = max(ans,dp[N-1][i]);
        }
        return ans;
    }
};
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int dp[n+1][k+1];
    for(int i =0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j && arr[i-1] > 0){
                    dp[i][j] += dp[i-1][j/arr[i-1]] + 1;
                }
            }
        }
    }
    cout << dp[n][k];

}
