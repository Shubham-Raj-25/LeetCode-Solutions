class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // F(k+1) = F(k) + sum(nums) - n*A[n-1-k];
        int k = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
            ans += i*nums[i];
        
        int sum = 0;
        for(auto it: nums) sum += it;
        
        vector<int> dp(nums.size());

        dp[0] = ans;

        for(int i=1;i<nums.size();i++){
            dp[i] = dp[i-1]+sum - int(nums.size())*nums[nums.size()-i];
            ans = max(ans,dp[i]);
        }

        return ans;

    }
};