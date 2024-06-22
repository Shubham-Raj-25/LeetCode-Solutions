class Solution {
public:
    int func(vector<int>& nums, int k){
        int count = 0,ans = 0, l = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r] % 2 != 0)
                count++;
            while(count > k){
                count -= nums[l] % 2 != 0;
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // looks like reverse sliding window
        return func(nums,k) - func(nums,k-1);
    }
};