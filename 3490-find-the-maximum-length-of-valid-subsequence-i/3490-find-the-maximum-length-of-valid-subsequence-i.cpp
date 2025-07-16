class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()<3)return nums.size();
        int odd=0,even=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
            if(nums[i]==0)even++;
            else{
                odd++;
            }
        }
        if(odd==0)return even;
        if(even==0)return odd;

        vector<int>dp(nums.size(),0);
        int num=nums[0];
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=num){
                dp[i]=dp[i-1]+1;
                num=nums[i];
            }else{
                dp[i]=dp[i-1];
            }
        }
        if(odd>dp[nums.size()-1]||even>dp[nums.size()-1])return max(odd,even);
        
        return dp[nums.size()-1];
    }
};