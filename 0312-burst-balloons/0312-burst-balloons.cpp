class Solution {
public:
    int func(int s, int e, vector<int>& nums, vector<vector<int>>& dp){
        if(s > e)
            return 0;
        
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int max_score = 0;

        for(int k = s; k <= e; k++)
            max_score = max(max_score, nums[s-1]*nums[k]*nums[e+1] + func(s,k-1,nums,dp)+ func(k+1,e,nums,dp));
        
        return dp[s][e] = max_score;
        
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return func(1,n,nums,dp);
    }
};