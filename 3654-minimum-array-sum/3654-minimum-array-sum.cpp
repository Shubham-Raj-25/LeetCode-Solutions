class Solution {
public:
    long long dp[101][101][101];
    int func(int idx,int op1,int op2,int k,vector<int>& nums){
        if(idx >= nums.size())
            return 0;
        
        if(dp[idx][op1][op2] != -1) return dp[idx][op1][op2];
        
        // don't do anything
        int ans  = nums[idx] + func(idx+1,op1,op2,k,nums);

        // divide by 2 only
        if(op1 > 0)
            ans = min(ans, (nums[idx]+1)/2 + func(idx+1,op1-1,op2,k,nums));
        // minus only
        if(op2 > 0 && nums[idx] >= k)
            ans = min(ans, nums[idx] - k + func(idx+1,op1,op2-1,k,nums));
        
        if(op1 > 0 && op2 > 0){
            // minus then divide
            if(nums[idx] >= k)
                ans = min(ans,  (nums[idx]-k +1)/2 + func(idx+1,op1-1,op2-1,k,nums));
            // divide then minus
            if((nums[idx]+1)/2 - k >= 0)
                ans = min(ans, (nums[idx]+1)/2 - k + func(idx+1,op1-1,op2-1,k,nums));
        }

        return dp[idx][op1][op2] = ans;
    }


    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return func(0,op1,op2,k,nums);
    }
};