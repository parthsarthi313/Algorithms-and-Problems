class Solution {
public:
    int dp[101];
    int func(int ind,int n,vector<int> &nums)
    {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + func(ind+2,n,nums);
        int notpick = func(ind+1,n,nums);
        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        memset(dp,-1,sizeof(dp));
        return func(ind,n,nums);
    }
};