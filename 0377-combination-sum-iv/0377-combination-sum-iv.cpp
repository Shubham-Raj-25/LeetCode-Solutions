class Solution {
public:
    unordered_map<int,int> dp;
    int func(int sum,vector<int>& nums, int target){
        
        if(dp.find(sum)!=dp.end())
            return dp[sum];
        
        if(sum==target)
            return 1;
        if(sum > target)
            return 0;
        
        int ans = 0;

        for(int i=0;i<nums.size();i++)
            ans += func(sum+nums[i],nums,target);
        
        return dp[sum] = ans;

    }

    int combinationSum4(vector<int>& nums, int target) {
        return func(0,nums,target);
    }
};