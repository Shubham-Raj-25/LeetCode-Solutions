class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // sliding window should shrink
        // atmost (k-1) can be solved but not atleast
        int maxi = INT_MIN;
        for(int num : nums){
            maxi = max(num, maxi);
        }
        int l = 0, count = 0;
        long long ans = nums.size() * (nums.size()+1)/2;
        for(int r=0;r<nums.size();r++){
            count += nums[r] == maxi;
            while(count >= k){
                count -= nums[l] == maxi;
                l++;
            }
            ans -= (r-l+1);
        }
        return ans;
    }
};