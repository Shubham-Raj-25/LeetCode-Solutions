class Solution {
public:
    int func(int curr, int prev, vector<vector<int>>& dp, vector<int>& nums){
        if(curr == nums.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int pick = 0, skip = 0;
        
        if(prev == -1 || nums[curr] > nums[prev])
            pick = 1 + func(curr+1,curr,dp,nums);
        
        skip = func(curr+1,prev,dp,nums);

        return dp[curr][prev+1] = max(pick,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        return func(0,-1,dp,nums);
    }
};