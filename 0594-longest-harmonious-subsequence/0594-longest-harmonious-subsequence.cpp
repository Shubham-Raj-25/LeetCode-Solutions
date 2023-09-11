class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int left = 0, right = 0;

        while(right<nums.size()){
            while(right<nums.size() && nums[right]==nums[left])
                right ++;
            while(right<nums.size() && nums[right]-nums[left]==1)
                {   
                    ans = max(ans,right-left+1);
                    right++;
                }
            left++;
        }
    
        return ans;
    }
};