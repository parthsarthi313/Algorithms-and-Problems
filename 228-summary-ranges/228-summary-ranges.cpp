class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.size() == 0) return v;
        else if(nums.size() == 1){
            v.push_back(to_string(nums[0]));
            return v;
        }
        int prev = nums[0];
        int curr = nums[0];
        int flg = 0;
        for(int i =1;i<nums.size();i++){
            if(nums[i] == curr+1){
                curr = nums[i];
                if(i == nums.size()-1) flg = 1;
            }
            else{
                if(i == nums.size()-1) flg = 2;
                if(prev == curr){
                    v.push_back(to_string(prev));
                    prev = nums[i];
                    curr = nums[i];
                }
                else{
                    v.push_back(to_string(prev) + "->" + to_string(curr));
                    prev = nums[i];
                    curr = nums[i];
                }
            }
        }
        if(flg == 1){
            if(prev == curr) v.push_back(to_string(prev));
            else v.push_back(to_string(prev) + "->" + to_string(curr));
        }
        else if(flg == 2){
            v.push_back(to_string(nums[nums.size()-1]));
        }
        return v;
    }
    
};