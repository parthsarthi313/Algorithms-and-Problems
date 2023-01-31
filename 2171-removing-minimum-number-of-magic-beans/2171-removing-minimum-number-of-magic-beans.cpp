class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans = LLONG_MAX;
        long long sum = 0;
        sort(beans.begin(),beans.end());
        long long totalsum = 0;
        for(int i =0;i<beans.size();i++){
        totalsum += beans[i];
        }
        for(int i =0;i<beans.size();i++){
            long long temp = sum + (totalsum-sum-beans[i] - (beans.size()-(i+1))*beans[i]);
            ans = min(ans,temp);
        }
        return ans;
    }
};