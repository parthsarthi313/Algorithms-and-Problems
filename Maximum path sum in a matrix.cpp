class Solution{
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
