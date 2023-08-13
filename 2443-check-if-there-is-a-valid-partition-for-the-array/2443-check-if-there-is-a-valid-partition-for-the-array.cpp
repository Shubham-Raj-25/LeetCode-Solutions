// dp question
class Solution {
public:
    bool func(int idx, vector<int>& nums, vector<int>& dp){
        if(idx==nums.size())
            return true;
        
        if(dp[idx]!=-1) return dp[idx];

        bool ans = false;

        if(idx<nums.size()-1 && nums[idx]==nums[idx+1])
            ans = func(idx+2,nums,dp);
        
        if(idx<nums.size()-2 && ((nums[idx]==nums[idx+1])&& (nums[idx+1]==nums[idx+2]) || (nums[idx]+1==nums[idx+1]) && (nums[idx+1]+1==nums[idx+2])))
            ans = ans || func(idx+3,nums,dp);
        
        return dp[idx] = ans;

    }

    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return func(0,nums,dp);
    }
};