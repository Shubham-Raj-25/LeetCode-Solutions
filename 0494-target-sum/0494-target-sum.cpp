class Solution {
public:
    int helper(int idx, int sum, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == nums.size()){
            return sum == target;
        }

        if(dp[idx][sum+1000] != -1){
            return dp[idx][sum+1000];
        }

        int doPlus = helper(idx+1,sum+nums[idx],target,nums,dp);
        int doMinus= helper(idx+1,sum-nums[idx],target,nums,dp);

        return dp[idx][sum+1000] = doPlus+doMinus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(20, vector<int>(2001,-1));
        return helper(0,0,target,nums,dp);
    }
};