class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int maxNum = nums[0];
        for(int i=1;i<nums.size();i++){
            ans += maxNum;
            maxNum = max(nums[i],maxNum);
        }
        return ans;
    }
};