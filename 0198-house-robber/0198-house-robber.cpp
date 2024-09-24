class Solution {
public:
    int func(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        // rob
        int rob = nums[idx] + func(idx+2,nums,dp);
        // skip
        int skip = func(idx+1,nums,dp);

        return dp[idx] = max(skip,rob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        return func(0,nums,dp);
    }
};