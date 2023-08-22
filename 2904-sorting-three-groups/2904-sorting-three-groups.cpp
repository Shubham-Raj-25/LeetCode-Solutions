class Solution {
public:
    int func(int idx,int last,vector<int>&nums, vector<vector<int>>& dp){

        if(idx==nums.size())
            return 0;
        
        if(dp[idx][last+1]!=-1)
            return dp[idx][last+1];

        int notTake = func(idx+1,last,nums,dp);

        int take = 0;

        if(last==-1 || nums[idx]>=nums[last])
            take = 1+func(idx+1,idx,nums,dp);

        return dp[idx][last+1] = max(take,notTake);    
    
    }


    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+3,-1));
        return n-func(0,-1,nums,dp);
    }
};