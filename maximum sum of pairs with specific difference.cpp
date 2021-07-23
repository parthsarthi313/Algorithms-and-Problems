class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        int dp[N];
        for(int i =0;i<N;i++){
            dp[i] = 0;
        }
        sort(arr,arr+N);
        for(int i =1;i<N;i++){
            if(arr[i]-arr[i-1] < K){
                dp[i] = max({dp[i-1],dp[i-2]+arr[i] + arr[i-1]});
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[N-1];
    }
};
