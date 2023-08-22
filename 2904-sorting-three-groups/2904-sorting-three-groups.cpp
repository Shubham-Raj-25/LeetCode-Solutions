class Solution {
public:
    int func(int ind, int prev, int n, vector<int>& nums,vector<vector<int>>&dp){

    if(ind == n) return 0;

    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

    int notTake = func(ind+1,prev,n,nums,dp);
    int take = -1;
    if(prev==-1 || nums[ind]>=nums[prev])
        take = 1+func(ind+1,ind,n,nums,dp);

    return dp[ind][prev+1] = max(take,notTake);

    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return n-func(0,-1,n,nums,dp);
    }
};